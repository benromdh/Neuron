#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

class Neurone 
{
	private :
		
		double V;	
		static constexpr int d = 15;				  /*! potentiel de membrane */
		int spikes;					  /*! tableau qui repertorie le nombre total de spikes du neurone */
		std::vector<double> spk_time; /*! tableau qui stocke le temps de spike pour chaque Neurone */
		std::vector<int> targets;	 
		std::vector<double> buffer;	  /*! buffer pour gerer la reception du spike J au temps t + d*/
		double J;					  /*! parametre J qui définit la nature du neurone */
										
		static constexpr double h = 0.1;		  /*! unité de temps*/
		static constexpr double V_thr = 20;      /*! le V threshold */
		static constexpr double tau = 20; 		  /*! Constantes */
		static constexpr int C = 1;
		static constexpr double r_per = 2;       /*! refractory period (ms)*/
		static constexpr double R = tau/C;
		static constexpr double C_ext = 1000; 	    /*! connexions ext = connexions exitatrices */
		static constexpr double V_ext = 2; 	  		/*! le rate de reception du background noise */

		
				
	public :
	
		Neurone(double j);
		bool update(int t);
		std::vector<double> get_spk_time();		
		double get_potential();
		void receive(int t, double J_voisin); /*! gere l'affectation de J au neurone concerné */
		double get_V();
		double get_J();
		std::vector<int> get_targets();

};



#endif
