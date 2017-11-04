#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <array>
#include <iostream>
#include <random>
#include <map>

class Network
{
	
	private :
		std::vector<Neurone*> Neurones;
		/*int clock;				
		double t_stop;
		double h;*/

	public :
		Network();
		void interaction();
		~Network();

	
};


#endif
