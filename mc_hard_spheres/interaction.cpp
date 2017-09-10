#include "interaction.h"

bool overlap(vector<double> newp, int p){
    double deltax = abs(newp[0] - particles[p][0]);
    double deltay = abs(newp[1] - particles[p][1]);
    double deltaz = abs(newp[2] - particles[p][2]);
    bool olap = (pow(min(deltax, L-deltax),2) + pow(min(deltay, L-deltay),2), pow(min(deltaz, L-deltaz),2) < 4.0 * pow(sigma,2));
    return olap;
}
