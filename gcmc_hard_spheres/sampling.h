#ifndef SAMPLING
#define SAMPLING

#define _USE_MATH_DEFINES

#include<iostream>
#include<fstream>
#include<cstdio>
#include<time.h>
#include<cmath>
#include<map>
#include "common_params.h"
#include "interaction.h"

using namespace std;

//initialize sampling output streams
void sample_init();
//sampling functions
void sample_rdf(double,double); //radial distribution function
//finalize sampling output streams
void sample_finalize();

#endif
