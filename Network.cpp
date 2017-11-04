#include "Network.hpp"
#include <random>
#include <map>
#include <fstream>
using namespace std;


int uniform(int a,int b)
{
	static random_device rd; 
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(a,b);
	return dis(gen);
}

Network :: Network()
{
	cout << "je suis dans network"<<endl;	
	for(size_t i(0); i < 10000; ++i)
	{	cout << i << endl;
		Neurones.push_back(new Neurone(0.1));
	}
    cout << "je suis dans network2 "<<endl;
    for(size_t i(0); i < 2500; ++i)
    {	
		Neurones.push_back(new Neurone(-0.5));
	}
	
	for(size_t n(0); n < Neurones.size(); ++n)
	{
		for(int i(0); i < 1000; ++i)
		{
			Neurones[uniform(0,9999)] -> get_targets().push_back(n);
		}
		for(int j(0); j < 250; ++j) 
		{
			Neurones[uniform(10000,12499)] -> get_targets().push_back(n);
		}
	}

}

void Network :: interaction()
{
	cout << "je suis dans interaction";
	int clock = 0;
	int t_stop = 500;
	double h = 0.1;
	string const valeurs_pot("valeurs.txt");
	ofstream sortie(valeurs_pot.c_str());

 
	while (clock < t_stop)
	{
		cout << "je suis dans la boucle"<< endl;
		for(size_t i(0); i < Neurones.size(); ++i)
		{	
			bool spike = Neurones[i]->update(clock); 
			if(spike)
			sortie << clock*h << "	";
			sortie << i+1 << endl;
			{
				for(size_t j(0); j < Neurones[i] -> get_targets().size(); ++j) 		
				{
					
					Neurones[Neurones[i]-> get_targets()[j]]->receive(clock,Neurones[i] -> get_J()); 
				}
			}
		}
	++clock;	
	}

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

	
	



