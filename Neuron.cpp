#include "Neuron.hpp"
#include <random>

using namespace std;

Neurone :: Neurone(double j)
:spikes(0),buffer(d+1, 0),J(j)		/*! on set la taille du buffer à d+1 (en pas de temps) afin d'avoir un tableau circulaire */
{}

	
bool Neurone :: update(int t,int p)
{	

	bool spiked = false;					
	if (!spk_time.empty() and ((t*h)-spk_time.back()) < r_per)	/*! valeur recu du neurone et qui doit etre ajoutée à V au temps t+d */
	{
		V = 0.0;
	}
		
	else
	{
		V = exp(-h/tau)*V + buffer[t % (d+1)]+ p*J_ext; //random_poisson(V_ext*h)*0.1;		
		
		if(V > V_thr) 
		{
			++spikes;
			spk_time.push_back(t*h);
			V = 0.0;
			
			spiked = true;
		}
	
	}
		
		buffer[t % (d+1)] = 0;	
		return spiked;
		
}

void Neurone::receive(int t, double J_voisin)
{
	buffer[(t+d) % (d+1)] += J_voisin;
}

vector<double> Neurone :: get_spk_time()	
{
	return spk_time;
}

double Neurone :: get_V()
{
	return V;
}

double Neurone :: get_J()
{
	return J;
}

vector<int> Neurone :: get_targets()
{
	return targets;
}

vector<double> Neurone :: get_buffer()
{
	return buffer;
}

void Neurone :: add_target(int i)
{
	targets.push_back(i);
}
