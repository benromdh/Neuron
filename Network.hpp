#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <map>

class Network
{
	
	private :
		std::vector<Neurone*> Neurones;
		
		static constexpr int NE = 10000;
		static constexpr int NI = 2500;
		static constexpr double h = 0.1;
		static constexpr double J_ext = 0.1;
		static constexpr double C_ext = 1000; 	
		static constexpr double V_thr = 20; 
		static constexpr double tau = 20; 
		double J_in;
		double V_ext;
	
	
	public :
		Network(double eta,double g);
		void interaction(int t_stop);
		~Network();

	
};


#endif
