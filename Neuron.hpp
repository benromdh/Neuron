#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

/******************************************************************************************************************************
 * A class that simulate 1 Neuron. A neuron is mainly caracterized by it's membrane potential and the number of "spikes"
 * it makes during it's lifetime : indeed, the potential membrane is incremented at each step until it reaches 
 * a certain limit value, or threshold : then the potential membrane is set to 0 back again and the spike and 
 * the time it occured are recorded. As we'll simulate a network of neurons, each neuron has it's own targets,
 * that will receive a certain amount of imput Jext or Jin from the "firing neuron" after a certain delay, depending on the nature of the neuron :
 * This one can be either excitatory or inhibitory. The buffer object is a vector that will make sure that the neuron receives
 * the imput received arrives after a certain delay.
 * 
 * For the time of the simulation(ms), we'll be mainly working with steps(t) : a step of time is equal to a time interval(unit time) of 0.1 ms.
 * Thus the global time(T) is obtained with the relation : T = t*h
 * The membrane potential and so J, are recorded in mV.
 ******************************************************************************************************************************/

class Neurone 
{
	private :
		
		double V;					   	/*! membrane potential (mV) */
		int spikes;					  	/*! number of spikes */
		std::vector<double> spk_time; 	/*! tab that record the time of each spike for the neuron (ms) */
		std::vector<int> targets;	 	/*! reference numbers to the targets of each neuron choosen randomly(c.f network) */
		std::vector<double> buffer;	  	/*! buffer : a circular vector !! (we have to take the modulo operation t % (d+1) where d is the size of the buffer to navigate into the colomns ensuring that the neuron receives the imput J for the potential membrane after a delay d(time t+d)*/
		double J;						/*! constant of the neuron : the amount of imput it send to a target neuron (mV) either excitatory or inhibitory*/
		
/********************************Constantes************************************************************************************/										
		
		static constexpr int d = 15;				/*! delay of reception of J */
		static constexpr double J_ext = 0.1; 		/*!	fraction of excitatory neurons taking the whole network */						
		static constexpr double h = 0.1;		  	/*! unit time */
		static constexpr double V_thr = 20;      	/*! The threshold or limit for V */
		
		static constexpr double r_per = 2;       	/*! refractory period (ms)*/
		static constexpr int C = 1;					/*! Autres constantes */
		static constexpr double tau = 20; 		  	
		static constexpr double R = tau/C;
												

		
				
	public :
		
		/*! A constructor.
		 * @param j, wich will caracterize the nature of the neuron :
		 * either J_ext thus creating an excitatory neuron, or J_inh thus creating an inhibitory one.
		 */
		Neurone(double j);
		
		/*! A normal function that will update the neuron over time, returning true if this one spikes, false if not.
		 * @param t an integer argument(the actual time in steps).
		 * @param p poisson generator.
		 */
		bool update(int t,int p);
		
		/*! A method that will insert the J value of the firing neuron into the buffer of it's target at the current time(t) + d.
		 * @param t the actual time(steps !!).
		 * @param J_voisin the value of the firing imput J(either J_ext or J_inh).
		 */
		void receive(int t, double J_voisin); 
		
		/*! A method that enable to add targets(the number of that target) to some neuron, so it can fire to them.
		 * @param i the number of the target neuron. 
		 */
		void add_target(int i);	
		
		/*! getters */
		std::vector<double> get_spk_time();	
		double get_potential();
		double get_V();
		double get_J();
		std::vector<int> get_targets();
		std::vector<double> get_buffer();
		

};



#endif
