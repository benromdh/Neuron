# Neuron

Welcome to my "Neuron" repository attached with the course "project in informatics" of SV BA3 epfl.
Our program was created to simulate a network of neurons according to the "Brunel paper".
These can interact with each others by "spiking".
Here, we programed a neuron as an object caracterized by it's membrane potential V, and it's nature :
either excitatory or inhibitory.(See the Neurone class for more details).
Basically, what we're doing is that we set up a network of neurons, establishing connexions between them.
Indeed, each neuron has it's own targets with whom it can interact, by firing to them (see class network),
but receives also imput from the external parts of the brain (background noise poisson distributed).

In the main, for a given time of simulation given by the user, the class will run the simulation and update 
each neuron for every time step. When one spikes,it either excitate or inhibitate it's targets depending on it's nature.

 All this will enable to generate 4 plots (A,B,C and D) representing for each step of time,all the spiking neurons.
 The plots will differ by the values of "eta" that will define the rate at wich the rest of the brain fires (V_ext) it's excitatory signal
 to each connected neuron, and the value of "g" that define the value of inhibition "J_in" ("J_ext" constant).
 So each of the values :
 -t_stop (time interval of the simulation)
 -eta = V_ext/V_thr
 -g
 will be introduced by the users.
 
 The combinations of (eta,g) for each of the plots according to Brunel is :
 A : (g = 3,eta = 2)     
 B : (g = 6,eta = 4)
 C : (g = 5,eta = 2)
 D : (g = 4.5,eta = 0.9)
..wich also takes an interval of time equal to 100 ms (1000 steps) for the fig.A and 200 ms (2000 steps) for the others.

Then the program automatically write into a document the indexes of the spiking neurons for each time step.
However, we uploaded these documents made for each plot named respectively "valeursA",...,"valeursD".
From those, I drawn the 4 plots using jupiter and uploaded them as a single pdf file ("PlotsA,B,C,D) to reproduce the Brunel patterns.
Otherwise, I also uploaded a python document named "Plots.py" if you wish to generate the plots from it, using the documents stated, or other
you might want to create using the program.
For this, just add the name of the document under genfromtxt('doc.txt').
The code to draw the plots takes 50 neurons from the network (as in Brunel), so I set d[1] < 50.

Have fun..

