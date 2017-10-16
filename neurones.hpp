#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
using namespace std;

class Neurone 
{
	private :
		
		int spikes;
		double V;
		vector<double> spk_time;
		
		const double h = 0.1; 
		const double V_ref = 0.0;
		const double V_thr = 20;
		const double tau = 20; 
		const int C = 1;
		const double r_per = 0.5; //refractory period
		const double R = tau/C;
		const double J = 0.2;
				
	public :
	
		Neurone();
		bool update(int clock,double I);
		vector<double> get_tab();
		double get_potential();
		void receive();

};














#endif
