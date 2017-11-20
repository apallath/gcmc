#include "gcmc.h"
#include "common_params.h"

void gcmc(){
    make_cell_list();
    for(int i = 1; i <= ncycles; i++){
    	sampleNo+=1;
        if(ranf() <= exc_disp_ratio){
            hard_exchange();
        }
        else{
            hard_displace();
        }
        if (i%samp_ival == 0){
            sample_rdf(L/rmax_factor, L/dr_factor);
        }
    }
}
