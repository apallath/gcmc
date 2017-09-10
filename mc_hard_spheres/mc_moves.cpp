#include "mc_moves.h"

void hard_displace(){
    att_disp+=1;
    if(N == 0) return;
    int p = int(ranf() * N); //0 to N-1
    
    vector<double> newp = {particles[p][0] + (ranf()-0.5)*2*delta, particles[p][1] + (ranf()-0.5)*2*delta, particles[p][2] + (ranf()-0.5)*2*delta};

    bool olap = false;

    for(int j = 0; j < particles.size(); j++){
        if(j==p) continue; //don't check overlap with the particle that is being moved
        if(overlap(newp, j)){
            olap = true;
            break;
        }
    } 

    if(!olap){
        particles[p] = newp;
        succ_disp += 1;
        log_current_config(1);
    }        
}

void hard_exchange(){
    if(ranf() > 0.5){ //insert
        att_ins += 1;

        vector<double> newp = {ranf()*L, ranf()*L, ranf()*L};

        bool olap = false;

        for(int j = 0; j < particles.size(); j++){
            if(overlap(newp, j)){
                olap = true;
                break;
            }
        } 

        if(!olap){
            double arg = (pow(L,3) * zz)/(N+1);

            if(ranf() < arg) { //acceptance condition
                particles.push_back(newp); N+=1;
                succ_ins += 1;
                log_current_config(2);
            }
        }
        
    }
    else{ //remove
        att_del += 1;
        if(N==0) return;

        double arg = N/(pow(L,3) * zz);

        if(ranf() < arg){ //acceptance condition
            int p = int(ranf() * N); 
            particles.erase(particles.begin() + p); N-=1;
            succ_del += 1;
            log_current_config(3);    
        }    
    }    
}
