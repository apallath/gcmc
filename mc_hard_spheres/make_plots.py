import matplotlib.pyplot as plt
import numpy as np

f_rdf = open("rdf.dat","r")

#plot rdf
n = int(f_rdf.readline())
x = [None for i in range(n)]
y = [None for i in range(n)]
for i in range(n):        
    x[i] = map(float, f_rdf.readline().strip().split())
    y[i] = map(float, f_rdf.readline().strip().split())
xarr = np.array(x[0])
yarrs = np.array(y)

yarr = np.mean(yarrs, axis=0)

plt.figure()
plt.scatter(xarr,yarr)
plt.plot(xarr,yarr)
plt.savefig('rdf.png')

#plot histogram
hist = np.genfromtxt("gcmc.hist")
plt.figure()
plt.scatter(hist[:,0], hist[:,1])
plt.plot(hist[:,0], hist[:,1])
plt.savefig('histogram.png')

#plot log scale histogram
plt.figure()
plt.plot(hist[:,0], np.log(hist[:,1]))
plt.savefig('ln_histogram.png')


