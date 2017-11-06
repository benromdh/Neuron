#include "Network.hpp"
#include <random>
#include <map>
#include <fstream>


using namespace std;


Network :: Network(double eta,double g)
{
	static random_device rd; 
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(0,9999);
	static uniform_int_distribution<> dis2(10000,12499);
	
	V_ext = eta*C_ext*V_thr/(C_ext*J_ext*tau);
	J_in = -g*J_ext;
	
	for(size_t i(0); i < NE; ++i)
	{	
		Neurones.push_back(new Neurone(J_ext));
	}

    for(size_t i(0); i < NI; ++i)
    {	
		Neurones.push_back(new Neurone(J_in));
	}

	for(size_t n(0); n < Neurones.size(); ++n)
	{
		for(int i(0); i < 1000; ++i)
		{
			Neurones[dis(gen)] -> add_target(n);
		}
		for(int j(0); j < 250; ++j) 
		{
			Neurones[dis2(gen)] -> add_target(n);
		}
	}
	
	/*for(size_t n(0); n < Neurones.size(); ++n)
		{
			cout<<"neuron : "<< n+1 <<" : " << Neurones[n]->get_targets().size() << endl;
		}*/
}
	
void Network :: interaction(int t_stop)
{
	static random_device rd;
	static mt19937 gen(rd());
	static poisson_distribution<> dis(V_ext*h);

	int clock = 0;
	string const valeurs_pot("valeurs4.txt");
	ofstream sortie(valeurs_pot.c_str());
	
	while (clock < t_stop)
	{
		for(size_t i(0); i < Neurones.size(); ++i)
		{	
			bool spike = Neurones[i] -> update(clock,dis(gen)); 
			if(spike)
			{	
				sortie << clock*h << "	";
				sortie << i+1 << endl;
				for(size_t j(0); j < Neurones[i] -> get_targets().size(); ++j) 		
				{
					Neurones[(Neurones[i]-> get_targets())[j]]->receive(clock,Neurones[i] -> get_J()); 
				}
			}
		}
	++clock;	
	}
	
	sortie.close();

} 
	
Network :: ~Network()
{
	for(auto& neurone : Neurones)
	{
		delete neurone;
		neurone = nullptr; 
	}
	Neurones.clear();
	
}
	
	



