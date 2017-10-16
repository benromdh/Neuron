#include <iostream>
#include "neurones.hpp"
//#include "constantes.cc"
#include <cmath>
using namespace std;

bool Neurone :: update(int t,double I)

{	

		if (V > V_thr) 
		{
			++spikes;
			spk_time.push_back(t * h);
			V = 0;	
			return true;
		}
		
		if (!spk_time.empty() and ( (t*h)-spk_time.back()) < r_per)
		{
			V = 0;
			return false;
		}
	
		else 
		{
			
			V = exp(-h/tau)*V + I*R*(1-exp(-h/tau));
			return false;
		}
		
		
}

void Neurone::receive()
{
	
	V += J;	
}

vector<double> Neurone :: get_tab()	
{
	return spk_time;
}

double Neurone :: get_potential()
{
	return V;
}

Neurone :: Neurone()
:spikes(0), V(V_ref)
{}
