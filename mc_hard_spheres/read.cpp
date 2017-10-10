#include "read.h"

void read(){
    int nparams = 9;
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
    zz = stod(input[5]);
    npav = stoi(input[6]);
    nexc = stoi(input[7]);
    delta = stod(input[8]);

    L = bfactor * sigma; 
}
