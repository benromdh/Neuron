#include <fstream>
#include <string>
#include "Network.hpp"
//#include "constantes.cc"
using namespace std;

int main()
{
	double eta;
	int t_stop;
	int g;
	cout << "Please enter a time for the simulation (steps) : " << endl;
	cin >> t_stop;
	cout << "Please enter a value for eta : " << endl;
	cin >> eta;
	cout << "Please enter a value for g : " << endl;
	cin >> g;
	
	Network simulation(eta,g);		//We create a network
	simulation.interaction(t_stop);
	
	return 0; 
	
}
