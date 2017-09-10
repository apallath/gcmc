/* Grand Canonical Monte Carlo simulation for hard-sphere systems
   @author: Akash Pallath */

#include<bits/stdc++.h>
#include "common_params.h"
#include "mc_moves.h"
#include "read.h"
#include "logging.h"
#include "gcmc.h"
#include "interaction.h"
#include<time.h>

using namespace std;

int main(){
    start = clock();
    read();
    log_init();    
    //gcmc_init_config();
    gcmc();
    log_finalize();
    return 0;
}
