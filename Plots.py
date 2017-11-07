import numpy as np
import matplotlib.pyplot as pl

data=np.genfromtxt('valeursA.txt')

select=np.array([d for d in data if d[1]<50])
data1=select.transpose()

pl.scatter(0.1*data1[0],data1[1],s = 4,alpha=0.8, edgecolors='none');
pl.show();

n,bins,patches = pl.hist(0.1*data1[0], 100,normed=0, alpha=0.75)
pl.show();
