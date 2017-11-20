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
int samp_ival = 0;
double delta = 0;
double zz;

//Optimization: Cell list
int ncells;
double cell_list_div;
vector<list<vector<double> > > cell_list;

//GCMC parameters
double exc_disp_ratio = 0.6; //ratio of exchanges to displacements

//Particles
vector<vector<double> > particles;

//Time
double start;

//Statistics
int att_disp; 
int att_ins;
int att_del;
int succ_disp;
int succ_ins;
int succ_del;

//RDF computation
int rmax_factor;
int dr_factor;

//Logging
int logging = 0;

//Resume from state
bool read_from_file = false;

//TMMC parameters
vector<vector<double>> tmmcC={{0,0,0}};
vector<vector<double>> tmmcN={{0,0,0}};
int Nmax=0;
double tmmcRsum = 0 ;
bool usesTmmc = true ;
bool updateTmmcN= true ;
bool startTmmc = false ;
bool tmmcBias = true;
double bias = 1;
bool startTmmcBias = false;
bool inc = false ;

//Loop counter
int sampleNo=0;

