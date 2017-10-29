#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
using namespace std;

class Neurone 
{
	private :
		
		int spikes;
		vector<double> spk_time;
		double d = 1.5;
		const double h = 0.1; 
		vector<int> buffer;
		double V;
		const double V_thr = 20; //potential limit
		const double tau = 20; 
		const int C = 1;
		const double r_per = 0.5; //refractory period
		const double R = tau/C;
		double J = 0.1;
		
				
	public :
	
		Neurone();
		bool update(int clock,double I);
		vector<double> get_tab();
		double get_potential();
		void receive(int t, double J_voisin);
		double get_J();

};














#endif
