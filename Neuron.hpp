#ifndef NEURONES_H
#define NEURONES_H
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <random>

/************************************************************************************************************************************************//**
 * A class that simulate 1 Neuron. 
 * A neuron is mainly caracterized by it's membrane potential, the number of "spikes"
 * it makes during it's lifetime and whether it is excitatory or inhibitory : indeed, the potential membrane is incremented at each step until it reaches 
 * a certain limit value, or threshold : then the potential membrane is set to 0 back again and the spike and 
 * the time it occured are recorded. As we'll simulate a network of neurons, each neuron has it's own targets,
 * that will receive a certain amount of imput Jext or Jin from another "firing neuron" after a certain delay, depending on the nature of the neuron.
 * The buffer object is a vector that will make sure that the neuron receives
 * the imput received arrives after a certain delay.
 * 
 * For the time of the simulation(ms), we'll be mainly working with steps(t) : a step of time is equal to a time interval(unit time) of 0.1 ms.
 * Thus the global time(T) is obtained with the relation : T = t*h when needed.
 * The membrane potential and so J, are recorded in (mV).
 **************************************************************************************************************************************************/

class Neurone 
{
	private :
		
		double V;					   	/*! membrane potential (mV) */
		int spikes;					  	/*! number of spikes */
		std::list<double> spk_time; 	/*! tab that record the time of each spike for the neuron */
		std::vector<int> targets;	 	/*! reference numbers to the targets of each neuron choosen randomly(c.f network) */
		std::vector<double> buffer;	  	/*! buffer : a circular vector !! (we have to take the modulo operation t % (d+1) where d is the size of the buffer to navigate into the colomns ensuring that the neuron receives the imput J for the potential membrane after a delay d(time t+d)*/
		double J;						/*! constant of the neuron : the amount of imput it send to a target neuron (mV) either excitatory or inhibitory*/
		
/******************************** Constants declared here as const class attributes : time constants given in steps (t) ************************************************************************************/										
		
		static constexpr int d = 15;				/*! delay of reception of J */
		static constexpr double r_per = 20;       	/*! refractory period */
		static constexpr double J_ext = 0.1; 		/*!	fraction of excitatory neurons taking the whole network */						
		static constexpr double h = 0.1;		  	/*! unit time */
		static constexpr double V_thr = 20;      	/*! The threshold or limit for V */
		
		static constexpr int C = 1;					/*! Other constants */
		static constexpr double tau = 20; 		  	
		static constexpr double R = tau/C;
		static constexpr double c1 = exp(-h/tau); 	/*!constant of the membrane potential*/
												

		
				
	public :
		
		/*! A constructor.
		 * @param j wich will caracterize the nature of the neuron :
		 * either J_ext thus creating an excitatory neuron, or J_inh thus creating an inhibitory one.
		 */
		Neurone(double j);
		
		/*! A normal function that will update the neuron over time, returning true if this one spikes, false if not.
		 * @param t an integer argument (the actual time in steps).
		 * @param p poisson generator.
		 * @return true if spike.
		 */
		bool update(int t,int p);
		
		/*! A version of update to run the tets !!.
		 * @param T actual time step.
		 * @param I the current given.
		 */
		bool update_Test(int T,double I);
		
		/*! Test if the refractory period of the neuron is not passed yet.
		 * @param t current time of simulation.
		 * @return true if neuron is refractory.
		 */
		bool is_refractory(int t);
		
		/*! A method that will insert the J value of the firing neuron into the buffer of it's target at the current time(t) + d.
		 * @param t the actual time (steps !!).
		 * @param J_voisin the value of the firing imput J (either J_ext or J_inh).
		 */
		void receive(int t,double J_voisin); 
		
		/*! A method that enable to add targets(the number of that target) to some neuron, so it can fire to them.
		 * @param i the number of the target neuron. 
		 */
		void add_target(int i);	
		
/*********************************************** getters *******************************************************************************/

		std::list<double> get_spk_time();	
		double get_potential();
		double get_V();
		int get_spikes();
		double get_J();
		std::vector<int> get_targets();
		std::vector<double> get_buffer();
		

};



#endif
