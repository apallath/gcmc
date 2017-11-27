#ifndef COMMON_PARAMS
#define COMMON_PARAMS

#include<random>
#include<list>
using namespace std;

//potential
extern int potential_type;

//For random number generation
extern random_device rd;  //used to obtain seed
extern mt19937 gen; //mersenne_twister_engine
extern uniform_real_distribution<> zero_one; //uniform real distribution from [0,1]
double ranf();

//Common simulation parameters
extern double sigma; //particle diameter
extern double bfactor; //box scaling factor
extern double L; //box dimension
extern int N; //no of particles
extern bool periodic; //periodic boundary conditions, enabled by default
extern int ncycles;
extern int samp_ival; //interval for sampling averages
extern double delta;
extern double zz; //activity, exp(beta*mu)/lambda^3

//Optimization: Cell list
extern int ncells; //number of cells per dimension (user-specified)
extern double cell_list_div; //size of a single cell list division along a dimension (calculated)
extern vector<list<vector<double> > > cell_list;

//GCMC parameters
extern double exc_disp_ratio;

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

//RDF plot parameters
extern int rmax_factor;
extern int dr_factor;

//Logging
extern int logging; //off by default

//Resume from state
extern bool read_from_file;

//TMMC parameters
extern vector<vector<double>> tmmcC;
extern vector<vector<double>> tmmcN;
extern int Nmax;
extern double tmmcRsum ;
extern bool inc ;


extern int sampleNo;

#endif
