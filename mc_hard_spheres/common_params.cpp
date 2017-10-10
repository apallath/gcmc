#include "common_params.h"

//potential type
int potential_type = 0;

//For random number generation
random_device rd; 
mt19937 gen(rd()); 
uniform_real_distribution<> zero_one(0,nextafter(1, std::numeric_limits<double>::max())); 

double ranf(){
    return zero_one(gen);
}    

//Common simulation parameters
double sigma = 0;
double bfactor = 0;
double L = 0;
int N = 0;
bool periodic = true;
int ncycles = 0;
double delta = 0;
double zz;

//GCMC parameters
int npav = 0;
int nexc = 0;

//Particles
vector<vector<double> > particles;

//Time
double start;

int att_disp; 
int att_ins;
int att_del;
int succ_disp;
int succ_ins;
int succ_del;
