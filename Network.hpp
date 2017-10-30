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
		std::array<std::array<int, 12500>, 12500> Connexions;
		std::vector<Neurone*> Neurones ;

	public :
		Network();
		void interaction();

	
};

int uniform(int a,int b);













#endif
