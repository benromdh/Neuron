#include "Neuron.hpp"
#include <random>

using namespace std;

int random_poisson(int a)
{
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> dis(a);
	return dis(gen);
}

bool Neurone :: update(int t,double I)
{	

		if (!spk_time.empty() and ((t*h)-spk_time.back()) < r_per)
		{
			V = 0;
			return false;
		}
		
		else
		{
		J = buffer[t % ((int)(d/h) + 1)]; 
		buffer[t % ((int)(d/h) + 1)] = 0;
		V = exp(-h/tau)*V + I*R*(1-exp(-h/tau)) + J + random_poisson(V_ext*C_ext)*h*0.1;
			
			if(V > V_thr) 
			{
			++spikes;
			spk_time.push_back(t * h);
			V = 0;
			
			return true;
			}
			
			else { return false; }		
		}
		
}

void Neurone::receive(int t, double J_voisin)
{
	buffer[t+(int)(d/h)% (int)(d/h+1)] += J_voisin;
}

vector<double> Neurone :: get_tab()	
{
	return spk_time;
}

double Neurone :: get_potential()
{
	return V;
}

double Neurone :: get_V()
{
	return V;
}

double Neurone :: get_J()
{
	return J;
}

Neurone :: Neurone(double j)
:spikes(0), buffer(vector<int>((d/h)+1)), J(j)
{}
