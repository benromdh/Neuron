#include <iostream>
#include "Network.hpp"
//#include "constantes.cc"
#include <cmath>
using namespace std;


void Network :: interaction()
{
	double start = 0.0;
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
	
	
	
	
	while (clock < stop/h)
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
	}
	
	
}


