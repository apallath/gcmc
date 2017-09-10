#include "gcmc.h"

void gcmc(){
    for(int i = 1; i <= ncycles; i++){
        if(int(ranf() * (npav + nexc)) + 1 <= N){
            hard_displace();
        }
        else{
            hard_exchange();
        }
    }
}
