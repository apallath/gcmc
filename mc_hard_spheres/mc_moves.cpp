#include "mc_moves.h"

void hard_displace(){
    att_disp+=1;
    if(N == 0) return;

    int p = int(ranf() * N); //0 to N-1
    
    vector<double> newp = {particles[p][0] + (ranf()-0.5)*2*delta, particles[p][1] + (ranf()-0.5)*2*delta, particles[p][2] + (ranf()-0.5)*2*delta};
    newp = {fmod(newp[0] + L, L), fmod(newp[1] + L, L), fmod(newp[2] + L, L)}; //prevent overflow    

    int e_new = energy_hard_displace(newp,p); //energy on displacing p to newp

    if(e_new == 0){
        cell_list_remove(particles[p]);
        particles[p] = newp;
        cell_list_insert(particles[p]);

        succ_disp += 1;
        log_current_config(1);
    }        
}

void hard_exchange(){
    if(ranf() > 0.5){ //insert
        att_ins += 1;

        vector<double> newp = {ranf()*L, ranf()*L, ranf()*L};

        int e_new = energy_hard_insert(newp); //energy on inserting newp         

        if(e_new == 0){
            double arg = (pow(L,3) * zz)/(N+1);
            if(ranf() >= arg){
                cout << "Rejected by rule: " << ranf() << " " << arg << endl;
            }
            if(ranf() < arg) { //acceptance condition
                particles.push_back(newp); N+=1;
                cell_list_insert(newp);

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
            cell_list_remove(particles[p]);
            particles.erase(particles.begin() + p); N-=1;

            succ_del += 1;
            log_current_config(3);    
        }    
    }    
}
