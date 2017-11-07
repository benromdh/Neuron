#include "Network.hpp"
#include <map>
#include <fstream>


using namespace std;

/************************************************************************************************************************************************
 * In the constructor, we start by generating our network of NE excitatory neurons and NI inhibitory ones. (The first 10000 neurons are excitatory,
 * the rest are inhibitory.
 * Then we set up the targets for each neuron by adding each one randomly in the vector target of 1000 excitatory neurons and 250 inhibitory ones.
 * so The number of connection for each neuron is equal to (C_ext + C_in = 1250)
 * **********************************************************************************************************************************************/
Network :: Network(double eta,double g)
{		
	static random_device rd; 								//Random device and generator for the random uniformed distribution
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(0,9999);			
	static uniform_int_distribution<> dis2(10000,12499);
	
	V_ext = eta*C_ext*V_thr/(C_ext*J_ext*tau);
	J_in = -g*J_ext;
	
	for(size_t i(0); i < NE; ++i)					//creating the first NE neurons that are excitatory
	{	
		Neurones.push_back(new Neurone(J_ext));
	}

    for(size_t i(0); i < NI; ++i)					//The remain NI are inhibitory neurons
    {	
		Neurones.push_back(new Neurone(J_in));
	}

	for(size_t n(0); n < Neurones.size(); ++n)	//creating connexions
	{
		for(int i(0); i < 1000; ++i)
		{
			Neurones[dis(gen)] -> add_target(n);   //we generate our random excitatory connections
		}										
		
		for(int j(0); j < 250; ++j) 		  		//we generate our random inhibitory ones
		{
			Neurones[dis2(gen)] -> add_target(n);
		}
	}

			
}
	
void Network :: interaction(int t_stop)
{
	static random_device rd;						//Random devices for the poisson distribution
	static mt19937 gen(rd());
	static poisson_distribution<> dis(V_ext*h);

	int clock = 0;									//We set up the beginning of the simulation to 0
	string const valeurs_pot("valeursD.txt");		//fstream for recording spiking neurons at each time
	ofstream sortie(valeurs_pot.c_str());
	
	while (clock < t_stop)
	{	
		for(size_t i(0); i < Neurones.size(); ++i)	//We go through every neuron in the network and update it until one spikes..
		{	
			bool spike = Neurones[i] -> update(clock,dis(gen)); 
			if(spike)
			{	
				sortie << clock*h << "	" << i+1 << endl;		//The neuron 0 is indexed as 1 and so on
				for(auto& target : targets_of(i))
				{
					Neurones[target] -> receive(clock,Neurones[i] -> get_J()); 
				}
			}
		}
	++clock;	
	}
	
	sortie.close();

} 
	
vector<int> Network :: targets_of(int i)
{
	return Neurones[i] -> get_targets();
}

Network :: ~Network()
{
	for(auto& neurone : Neurones)
	{
		delete neurone;
		neurone = nullptr; 		//delete the neuron
	}
	Neurones.clear();			// clear the table
}
	
	


