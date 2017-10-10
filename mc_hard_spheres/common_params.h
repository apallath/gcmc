#ifndef COMMON_PARAMS
#define COMMON_PARAMS

#include<random>
using namespace std;

//potential
extern int potential_type;

//For random number generation
extern random_device rd;  //used to obtain seed
extern mt19937 gen; //mersenne_twister_engine
extern uniform_real_distribution<> zero_one; //uniform real distribution from [0,1]
double ranf();

//Common simulation parameters
extern double sigma; //particle radius
extern double bfactor; //box scaling factor
extern double L; //box dimension
extern int N; //no of particles
extern bool periodic; //periodic boundary conditions, enabled by default
extern int ncycles;
extern double delta;
extern double zz; //activity, exp(beta*mu)/lambda^3

//GCMC parameters
extern int npav; //average number of particles
extern int nexc; //average number of exchanges

//Particles
extern vector<vector<double> > particles;

//Time
extern double start;

//Statistics
extern int att_disp; //displacements attempted
extern int att_ins; //insertions attempted
extern int att_del; //deletions attempted
extern int succ_disp; //successful displacements
extern int succ_ins; //successful insertions
extern int succ_del; //successful deletions

#endif
