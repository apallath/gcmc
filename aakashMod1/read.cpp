#include "read.h"

void read(){
    int nparams = 14;
   /* string comment[nparams];
    string input[nparams];

    for(int i = 0; i < nparams; i++){
        getline(cin, comment[i]);
        getline(cin, input[i]);
    }*/

    cin>>potential_type;
    cin>>sigma;
    cin>>bfactor;
    cin>>ncells ;
    cin>>periodic;
    cin>>ncycles;
    cin>>samp_ival;
    cin>>zz;
    cin>>exc_disp_ratio;
    cin>>delta;
    cin>>rmax_factor;
    cin>>dr_factor;
    cin>>logging;
    cin>>read_from_file;

    L = bfactor * sigma; 
}
