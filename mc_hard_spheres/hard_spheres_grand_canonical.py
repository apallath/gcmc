""" Implementation of Metropolis Monte-Carlo Algorithm for hard spheres in Grand Canonical Ensemble
    @author: Akash Pallath
"""
import random

#Simulation parameters
samp_ival = 1

ncycles = 100000

npav = 80 #average number of particles
nexc = 40 #average number of exchanges to attempt

rad = 0.004 #in reduced units
delta = 0.005 #in reduced units

particles = []

#Collecting statistics
disp_att = 0
disp_acc = 0

rem_att = 0
rem_acc = 0

ins_att = 0
ins_acc = 0

def overlap(a,b): #periodic boundary conditions
    xdist = min((a[0] - b[0] + 1.0) % 1.0, (b[0] - a[0] + 1.0) % 1.0)
    ydist = min((a[1] - b[1] + 1.0) % 1.0, (b[1] - a[1] + 1.0) % 1.0)
    zdist = min((a[2] - b[2] + 1.0) % 1.0, (b[2] - a[2] + 1.0) % 1.0)
    return (xdist**2 + ydist**2 + zdist**2) < 4.0 * rad**2 

def mc_init(): #generate a starting configuration
    particles.append([random.uniform(-1,1), random.uniform(-1,1), random.uniform(-1,1)])
    for i in range(npav - 1):
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
        ran = int(random.uniform(0,npav + nexc))
        if ran <= len(particles):
            mc_displace()
        else:
            mc_exchange()

        if i%samp_ival == 0:
            sample()
    
def mc_displace():
    global disp_att, disp_acc
    disp_att += 1

    if len(particles) == 0:
        return

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
        disp_acc += 1
    #else reject move

def mc_exchange():
    global rem_att, rem_acc, ins_att, ins_acc

    remove = [True,False]
    if random.choice(remove):
        rem_att += 1
        if len(particles) == 0:
            return
        particles.pop(random.randrange(len(particles))) #remove particle
        print particles
        rem_acc += 1
    else: #attempt random particle insertion
        ins_att += 1
        olap = False
        a = [random.uniform(-1,1), random.uniform(-1,1), random.uniform(-1,1)]
        for b in particles:
            if overlap(a,b):
                olap = True
        if not olap:
            particles.append(a)   
            ins_acc += 1
            print particles
        
#Sample
def sample():
    pass

mc()
print "Dispacements: ", disp_acc, "/", disp_att, " = ", disp_acc * 1.0 / disp_att
print "Removals: ", rem_acc, "/", rem_att, " = ", rem_acc * 1.0 / rem_att
print "Insertions: ", ins_acc, "/", ins_att, " = ", ins_acc * 1.0 / ins_att
    
    
    
    



