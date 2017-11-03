#include "Neuron.hpp"
#include <random>

using namespace std;

Neurone :: Neurone(double j)
:spikes(0), buffer(vector<int>(d+1)), J(j)			/*! on set la taille du buffer à d+1 (en pas de temps) afin d'avoir un tableau circulaire */
{}

int random_poisson(int a)
{
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> dis(a);
	return dis(gen);
}

bool Neurone :: update(int t)
{	
		bool spiked = false;
		//cout << "j'ai updaté n"<< endl;						
		if (!spk_time.empty() and ((t*h)-spk_time.back()) < r_per)	/*! valeur recu du neurone et qui doit etre ajoutée à V au temps t+d */
		{
			V = 0;
		}
		
		else
		{
			int j = buffer[t % (d+1)];
					   	  		  
			V = exp(-h/tau)*V + j + random_poisson(V_ext);   
		
			if(V > V_thr) 
			{
				++spikes;
				spk_time.push_back(t*h);
				V = 0;
			
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

