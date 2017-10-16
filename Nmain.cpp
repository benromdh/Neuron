#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Network.cpp"
#include "neurones.cpp"
//#include "constantes.cc"
using namespace std;

void rien(){}s

int main()
{
	Neurone n1;
	double start = 0.0;
	double stop = 1000;
	int clock = 0.0;				
	double I1;
	double I2;
	double t_start;
	double t_stop;
	//double J = 0.1;
	double d = 0.1;
	int n;            //pas de temps

	string const valeurs_pot("valeurs.txt");
	ofstream sortie(valeurs_pot.c_str());
	
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
			n1.update(clock,I1);
			if(sortie)
			sortie << clock * h << "     " << "n1 : " << n1.get_potential() << endl;
			else
			cout << "Erreur";
			
			++clock;
		}
			
	sortie.close();
	
	for(auto t_spike : n1.get_tab())
	cout << t_spike << endl;
	
	}
	
	
	/* Network simulation;
	simulation.interaction();
	*/
	return 0; 
	
	
}
