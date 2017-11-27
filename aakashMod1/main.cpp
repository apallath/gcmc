/* Grand Canonical Monte Carlo simulation for hard-sphere systems
   @author: Akash Pallath */


#include "common_params.h"
#include "mc_moves.h"
#include "read.h"
#include "logging.h"
#include "gcmc.h"
#include "interaction.h"
#include "sampling.h"
#include "state.h"
#include<time.h>

using namespace std;

int main(){
    start = clock();
    read();
    if(read_from_file){
        collect();
    }
    log_init();
    sample_init();
    gcmc();
    log_finalize();
    sample_finalize();
    save();
    return 0;
}
