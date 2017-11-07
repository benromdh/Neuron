#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <vector>
#include <iostream>
#include <random>
#include <map>

/***********************************************************************************************************************************************************//**
 * A Network class.
 * In this class, we create a network of several neurons using pointers.
 * Each of the neurons has it's own targets, to wich it can fires an excitatory (J_ext) imput or inhibitory one (J_in), thus increasing or decreasing their membrane 
 * potential. Also, each neuron has 1250 imputs that came from C_ext = 1000 excitatory neurons, and C_I = 250 inhibitory ones, those are chosen randomly(thus one neuron can be selected to target 
 * the same neuron twice).
 * Here, for a given time of simulation given by the user, the class will run the simulation and update each neuron for every time step. When one spikes, then the method interaction
 * navigate through it's targets and give the J of the spiking neuron to be received after a delay by each of the targets.
 * All this will enable to generate a plot representing for each step of time,all the spiking neurons,that were recorded for each time,
 * then drawing a plot using jupiter.
 * The 3 graphs basically differ by	their g value, g equal to J_in/J_ext, wich defines the inhibition value (J_ext constant), and by the value of eta,
 * that enters into the calculation of the rate of the background noise firing, that is poison distributed.
 * The network is composed of NE excitatory neurons(J_ext) and NI inhibitory(J_in)
 * 
 ****************************************************************************************************************************************************************/
class Network
{
	
	private :
		std::vector<Neurone*> Neurones;	/*! The network of neurons */
		double J_in;					/*! The inhibition value for a firing neuron*/
		double V_ext;					/*! The rate at wich the background noise fires it's excitatory signal to each connected neuron */
		
/*********************************************************Static Constants************************************************************************************************/
		
		static constexpr int NE = 10000; 		/*! number of excitatory neurons in the network */
		static constexpr int NI = 2500;			/*! number of inhibitory neurons in the network */
		static constexpr double h = 0.1;		/*! the value in (ms) of one step of time */
		static constexpr double J_ext = 0.1;	
		static constexpr double C_ext = 1000; 	/*! number of excitatory connections */	
		static constexpr double V_thr = 20; 
		static constexpr double tau = 20; 

	
	
	public :
	
		/*! A constructor.
		 * @param eta wich will determine the rate of V_ext.
		 * @param g with g = J_in/J_ext, J_ext constant, will determine J_in.
		 * */
		Network(double eta,double g);
		
		/*! A function taking time as an argument and in charge of running the simulation.
		 * @param t_stop integer value, define the time of the simulation.
		 */
		void interaction(int t_stop);
		
		/*! A function to select a neuron i in the network and give it's targets.
		 * @param i reference to a neuron in the network.
		 * @return the vector of targets generated for that neuron.
		 */
		std::vector<int> targets_of(int i);
		
		/*! A destructor.
		 * In charge of giving back the memory and clearing the table.
		 */
		~Network();

	
};


#endif
