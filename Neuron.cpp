#include "Neuron.hpp"

using namespace std;

Neurone :: Neurone(double j)
:spikes(0),buffer(d+1, 0),J(j)		// we set the buffer size to d+1 (in steps) so we can recuperate the value of J in the ring buffer 
{}

/******************************************************Updating The Neuron********************************************************************************************************								
 * 
 * Each neuron is updated over time until the end of the simulation, during wich it's membrane potential increases according to 3 components(see the calculations of V below :
 * 1.The first component is recalculating V using the past value of the past time.
 * 2.This component increases V only if the delay after receiving J_in or J_ext from a firing neuron is passed. Then t = t+d (taking the module because of the "ring buffer"),
 * and we can extratc the written value of J. Otherwise the expression is equal to 0 and V doesn't change for that time.
 * 3.Finally, we're taking the background noise (imput from external parts of the brain) that is excitatory only (J_ext) and poisson distributed(p).
 *********************************************************************************************************************************************************************************/
 
bool Neurone :: update(int t,int p)
{	

	bool spiked = false;
	 
	if (!spk_time.empty() and is_refractory(t))	// check if neuron is refractory 
	{																		
		V = 0.0;
	}
		
	else
	{
		V = c1*V + buffer[t % (d+1)] + p*J_ext; // we recalculate the membrane potential		
											
		if(V > V_thr)				// if spike 																
		{
			++spikes;				// the number of spikes increases
			spk_time.push_back(t);	// we record the time of the spike
			V = 0.0;				// we reset the potential to 0
			
			spiked = true;			// we can get out of the function
		}
	
	}
		
		buffer[t % (d+1)] = 0;		// always resetting the current buffer to 0, so it doesn't accumulate
		return spiked;																		
												
}

bool Neurone :: update_Test(int T,double I)  //used during the tests
{	
	int t(0);
	bool spiked = false;
	 
	while(t < T)				//updates T times for 1 neuron
	{	
		if (!spk_time.empty() and is_refractory(t))				
		{																		
			V = 0.0;
		}
		
		else
		{
			V = c1*V + I*R*(1-c1) + buffer[t % (d+1)]; 			
											
			if(V > V_thr)												
			{
				++spikes;
				spk_time.push_back(t);
				V = 0.0;
			
				spiked = true;
			}
	
		}
		
			buffer[t % (d+1)] = 0;	
	}																	
			return spiked;											
}

bool Neurone :: is_refractory(int t)  
{
	return ((t-spk_time.back()) < r_per);
}

void Neurone :: receive(int t, double J_voisin)
{
	buffer[(t+d) % (d+1)] += J_voisin;
}

list<double> Neurone :: get_spk_time()	
{
	return spk_time;
}

double Neurone :: get_V()
{
	return V;
}

int Neurone :: get_spikes()
{
	return spikes;
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
