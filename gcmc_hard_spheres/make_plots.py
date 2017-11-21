import matplotlib.pyplot as plt
import matplotlib.patches as patches
import numpy as np

########################
####Define Constants####
#new_act_list = [0.011,0.0115,0.012,0.0095,0.009,0.0085]
#old_act = 0.010
box_dim = 50.0
sigma = 1.0
########################

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
plt.savefig('rdf.png')

#get histogram data
hist = np.genfromtxt("gcmc.hist")
minx = min(hist[:,0])
maxx = max(hist[:,0])

#plot histogram
normf = sum(hist[:,1])
normhist = np.array(hist[:,1])
normhist = normhist/normf
##plot
plt.figure()
ax1 = plt.gca()
ax1.set_xlim([minx,maxx])
ax1.set_ylim([0,1.5*max(normhist)])
plt.scatter(hist[:,0], normhist)
plt.savefig('histogram.png', dpi=300, bbox_inches='tight')

#plot log scale histogram
plt.figure()
ax2 = plt.gca()
ax2.set_xlim([minx,maxx])
plt.scatter(hist[:,0], np.log(normhist))
plt.savefig('ln_histogram.png', dpi=300, bbox_inches='tight')

#plot re-weighted histogram
"""for new_act in new_act_list:
    rewy = [None for i in range(len(hist[:,0]))]
    for i in range(len(hist[:,0])):
        rewy[i] = hist[i,1] * np.exp((np.log(new_act) - np.log(old_act)) * hist[i,0]) 
    normf = sum(rewy)
    rewyarr = np.array(rewy)
    rewyarr = rewyarr/normf
    ##plot
    plt.figure()
    ax3 = plt.gca()
    ax3.set_xlim([minx,maxx])
    ax3.set_ylim([0,1.5*max(rewyarr)])
    plt.scatter(hist[:,0], rewyarr)
    plt.savefig('rew_histogram_{}.png'.format(new_act), dpi=300, bbox_inches='tight')"""

#plot configuration
f_state = open("particles.state","r")

n = int(f_state.readline())
particles = [None for i in range(n)]
for i in range(n):        
    particles[i] = map(float, f_state.readline().strip().split())
parr = np.array(particles)

fig1 = plt.figure()
axes = fig1.add_subplot(111, aspect='equal')
axes.set_xlim([0,box_dim])
axes.set_ylim([0,box_dim])
for i in range(n):
    axes.add_patch(
    patches.Circle(
        (parr[i,0], parr[i,1]), # (x,y)
        sigma/2.0,  # radius
    )
)
fig1.savefig('particles.png', dpi=300, bbox_inches='tight')


