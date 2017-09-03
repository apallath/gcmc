""" Implementation of Metropolis Monte-Carlo Algorithm for hard spheres in Canonical Ensemble
    @author: Akash Pallath
"""
import random

#Simulation parameters
samp_ival = 1
ncycles = 100000
npart = 4
rad = 0.042 #in reduced units
delta = 0.05 #in reduced units

particles = []

acc_ct = 0

def overlap(a,b): #periodic boundary conditions
    xdist = min((a[0] - b[0] + 1.0) % 1.0, (b[0] - a[0] + 1.0) % 1.0)
    ydist = min((a[1] - b[1] + 1.0) % 1.0, (b[1] - a[1] + 1.0) % 1.0)
    zdist = min((a[2] - b[2] + 1.0) % 1.0, (b[2] - a[2] + 1.0) % 1.0)
    return (xdist**2 + ydist**2 + zdist**2) < 4.0 * rad**2 

def mc_init(): #generate a starting configuration
    particles.append([random.uniform(-1,1), random.uniform(-1,1), random.uniform(-1,1)])
    for i in range(npart - 1):
        attempt = True
        while attempt:
            olap = False
            a = [random.uniform(-1,1), random.uniform(-1,1), random.uniform(-1,1)]
            for b in particles:
                if overlap(a,b):
                    olap = True
                    break
            if not olap:
                particles.append(a)
                attempt = False                 
        
def mc():
    mc_init()

    for i in range(ncycles):
        mc_displace()
        if i%samp_ival == 0:
            sample()
    
def mc_displace():
    global acc_ct
    p = random.choice(particles);
    new = [p[0] + random.uniform(-delta, delta), p[1] + random.uniform(-delta, delta), p[2] + random.uniform(-delta, delta)]
    olap = False
    for a in particles:
        if overlap(a,new):
            olap = True
            break
    if not olap:
        p[:] = new[:] #move accepted
        print particles
        acc_ct += 1
    #else reject move

#Sample
def sample():
    pass

mc()
print "No. of accepted moves:", acc_ct, " Acceptance ratio: ", acc_ct*1.0/ncycles
    
    
    
    



