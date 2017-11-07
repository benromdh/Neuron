#include "Neuron.hpp"
#include <gtest/gtest.h>


TEST(NeuronTest1, PositiveInput)
{ 
	Neurone n(0.0); // J equal to 0 here we don't test network
	
	//we update for the first time, so V = 0 and only the member involving the current (1.0) remains
	n.update_Test(1,1.0);
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), n.get_V());
	
	//Test after numerous updates for same current(1.0).
	//We expect v-->20 but never reach it
	n.update_Test(10000,1.0);
	EXPECT_EQ(0, n.get_spikes()); //we expect the neuron to never spike
	
	//here the potential membrane should tend to 0 and we wait 10*tau.
	//so we update the neuron 2000 times starting from t = 0
	n.update_Test(2000,0.0);
	EXPECT_NEAR(0, n.get_V(), 1e-3); //a value really close to 0.

}

TEST(NeuronTest2, SpikeTimes)
{
	Neurone n(0.0);
	//the first spike occurs at T=92.4ms, or t=924 steps
	n.update_Test(924,1.01);
	EXPECT_EQ(0,n.get_spikes());//should be 0
	
	//Thus updating another step of time should make the neuron spike.
	//The potential is reset to 0
	n.update_Test(1,1.01);
	EXPECT_EQ(0.0, n.get_V());
	
	//we should have a spike
	n.update_Test(943,1.01);
	EXPECT_EQ(1,n.get_spikes());
	
	//we should now have a second spike
	n.update_Test(1,1.01);
	EXPECT_EQ(2, n.get_spikes());
	
}

TEST(Test_for_two_neurons1, delay)
{
	//we set an excitatory neuron that will fire J_ext after spiking to 
	//n2.
	Neurone n1(0.1); 
	Neurone n2(0.0);
	int d = 15; //we had set the delay to 1.5 ms so 15 steps
	for(int i(0); i < 925 + d; ++i)//at t = 924, n1 should spike and send it's J_ext to n2..
	{
		if(n1.update_Test(1,1.01)) //we set a current of 1.01 for n1
		{
			n2.receive(i,0.1);			//it send it's J value to n2
			EXPECT_EQ(0.0, n1.get_V()); //thus the potential membrane goes to 0
		}
		
	//n2 should receive the given imput after the delay is passed
		n2.update_Test(1,0.0); 
	}
	// given no current and updated 1 time each, the expected value for V is 0.1
	EXPECT_EQ(0.1, n2.get_V());
	
}

TEST(Test_for_two_neurons2, delay)
{
	Neurone n1(0.1);
	Neurone n2(0.0);
	int d = 15; //we had set the delay to 1.5 ms so 15 steps
	//the second spike for n1 should happen at T = 186.8ms, or t = 1868 steps
	//we test the first spike of n2 after n1 spikes 2 times
	for(int i(0); i < 1869 + d; ++i)
	{
		if(n1.update_Test(1,1.01)) //current I = 1.01 for n1
		{
			n2.receive(i,0.1); 
			EXPECT_EQ(0.0, n1.get_V());
		}
		n2.update_Test(1,1.0); //we set a current of 1.0 for n2
	}
	//1 step before n2 spikes
	EXPECT_EQ(0, n2.get_spikes());
	n2.update_Test(1,1.0);
	EXPECT_EQ(0, n2.get_V());
	EXPECT_EQ(1, n2.get_spikes());
}
	
	
	
	



