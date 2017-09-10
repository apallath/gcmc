#include "read.h"

void read(){
    int nparams = 11;
    string comment[nparams];
    string input[nparams];

    for(int i = 0; i < nparams; i++){
        getline(cin, comment[i]);
        getline(cin, input[i]);
    }

    potential_type = stoi(input[0]); 
    sigma = stod(input[1]);
    bfactor = stod(input[2]);
    periodic = (bool) stod(input[3]);
    ncycles = stoi(input[4]);
    T = stod(input[5]);
    m = stod(input[6]);
    mu = stod(input[7]);
    npav = stoi(input[8]);
    nexc = stoi(input[9]);
    delta = stod(input[10]);

    L = bfactor * sigma;

    //Boltzmann constant 
    const double kB = 1.3806503e-23;
    //pi
    const double pi = 3.14159265;
    //planck's constant, h
    const double h = 6.626176e-34;

    beta = 1/(kB * T);  
    lambda = h / sqrt(2*pi*m*kB*T);
    zz = exp(beta * mu) / pow(lambda,3); 
}
