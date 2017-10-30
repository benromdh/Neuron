#include "Network.hpp"
#include <random>
#include <map>
#include <fstream>
using namespace std;


Network :: Network()
{
	for(size_t i(0); i < 10000; ++i)
    { Neurones.push_back(new Neurone(0.1));}
    
    for(size_t i(0); i < 2500; ++i)
    { Neurones.push_back(new Neurone(-0.5));}
    cout << "creation" << endl;
}


int uniform(int a,int b)
{
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dis(a,b);
	return dis(gen);
}


void Network :: interaction()
{
	//double start = 0.0;
	double stop = 1000;
	int clock = 0;				
	double I1;
	double I2;
	double t_start;
	double t_stop;
	double h = 0.1;
	int n;            //pas de temps
	
	cout << "please insert a start time : ";
	cin >> t_start;
	cout << "Please insert a time of stop : ";
	cin >> t_stop;
	cout << "Please insert an external current for n1 : ";
	cin >> I1;
	cout << "Please insert an external current for n2 : ";
	cin >> I2;
	n = (t_stop - t_start)/h;
	
	for(size_t i(0); i < 12500; ++i)
	{
		for(int j(0); j < 1000; ++j)
		{
			Connexions[i][uniform(1,10000)] += 1;
		}
		for(int j(0); j < 250; ++j)
		{
			Connexions[i][uniform(10001,12500)] += 1;
		}
		
	}
	
	while (clock < stop/h)
	{	
		
		if(clock >= t_start/h and clock < t_stop/h)
		{	
			for(int i(0); i < 12500; ++i)
			{	
				if(Neurones[i] -> update(clock))
				{	
					for(size_t j(0); j < 12500; ++j)
					{
						if(Connexions[i][j] > 0)
						{
							Neurones[j] -> receive(clock,Neurones[i] -> get_J()); 
						}
					}
					
				}  //si pas update ???
			}
		} 
		++clock;
		
		for (auto n : Neurones) {
				cout << "n(" << n <<")" << n->get_potential();
		}
		/*else
		{
			(*n).update(clock,0);
		}*/
		
		
	}
	
	/*while (clock < stop/h)
	{

		if(clock >= t_start/h and clock < t_stop/h)
		{
			if(n1.update(clock,I1))
			{
				n2.receive(clock,n1.get_J());
			}
		
			if(n2.update(clock,I2))
			{
				n1.receive(clock,n2.get_J());
			}
	
		cout << "n1 :   " << n1.get_potential() << endl;
		cout << "n2 :   " << n2.get_potential() << endl;
		}
		else 
		{
			n1.update(clock,0);
		}
		++clock; 
		
	}  */
	
	
}


