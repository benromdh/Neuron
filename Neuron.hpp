#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Neurone 
{
	private :
		
		int spikes;
		std::vector<double> spk_time;
		double d = 1.5;
		const double h = 0.1; 
		std::vector<int> buffer;
		double V;
		const double V_thr = 20; //potential limit
		const double tau = 20; 
		const int C = 1;
		const double r_per = 0.5; //refractory period
		const double R = tau/C;
		const double C_ext = 1000; //connexions ext = connexions exitatrices 
		const double V_ext = 2; //pour h = 0.1
		double J;
		
				
	public :
	
		Neurone(double j);
		bool update(int t,double I = 1.01);
		std::vector<double> get_tab();
		double get_potential();
		void receive(int t, double J_voisin);
		double get_V();
		double get_J();

};



#endif
