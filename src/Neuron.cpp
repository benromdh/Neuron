#include <iostream>
#include "neurones.hpp"
//#include "constantes.cc"
#include <cmath>
using namespace std;

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
		V = exp(-h/tau)*V + I*R*(1-exp(-h/tau)) + J;
			
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

double Neurone :: get_J()
{
	return J;
}

Neurone :: Neurone()
:spikes(0), buffer(vector<int>((d/h)+1))
{}
