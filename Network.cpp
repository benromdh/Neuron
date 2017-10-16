#include <iostream>
#include "Network.hpp"
#include "constantes.cc"
#include <cmath>
using namespace std;


void Network :: interaction()
{
	double start = 0.0;
	double stop = 1000;
	int clock = 0.0;				
	double I1;
	double I2;
	double t_start;
	double t_stop;
//	double J = 0.1;
//  double d = 0.1;
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
	
	
	if (t_start >= start and t_stop <= stop)
	{
	
	while (clock < n)
	{
	
		if(n1.update(clock,I1))
		{
			n2.receive();
			//clock += d;
		}
		
		if(n2.update(clock,I2))
		{
			n1.receive();
			//clock += d;
		}
		//else {t += h;}
		
		cout << "n1 : " << n1.get_potential() << endl;
		cout << "n2 : " << n2.get_potential() << endl;
	
	}
	
	}
	
}


	
	/*double stop = 1000;
	double start = 0;
	double I1;
	double I2;
	double t1;
	double t2;
	double d = 1.5;
	int clock;

	//string const valeurs_pot("valeurs.txt");
	//ofstream sortie(valeurs_pot.c_str());
	
	cout << "please insert a start time : ";
	cin >> t1;
	cout << "Please insert a time of stop : ";
	cin >> t2;
	cout << "Please insert an external current for n1 : ";
	cin >> I1;
	cout << "Please insert an external current for n2 : ";
	cin >> I2;
	
	if (t1 >= start and t2 <= stop)
	{
	
	while (t < t2)
	{ */
