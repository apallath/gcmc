#include "logging.h"

ofstream config_log;
ofstream hgram_data;
vector<int> npart;
map<int,int> hgram;

void log_init(){
    const time_t ctt = time(0);
    cout << "Ensemble: Grand Canonical" << endl;
    cout << "Hard spheres? " << potential_type << endl;
    cout << endl;
    cout << "Radius: " << sigma << endl;
    cout << "Box length: " << L << endl;
    cout << "Displacement magnitude: " << delta << endl;
    cout << "Periodic boundary conditions? " << periodic << endl;
    cout << "Number of MC cycles: " << ncycles << endl;
    cout << "npav: " << npav << endl;
    cout << "nexc: " << nexc << endl;
    cout << "Activity: " << zz << endl;
    cout << endl;
    cout << "Average density: " << (npav * 4.0 / 3.0 * M_PI * pow(sigma,3)) / (pow(L,3)) << endl << endl;    
    config_log.open ("gcmc.log");  
    hgram_data.open("gcmc.hist"); //data for histogram
    
}

void log_current_config(int move_type){
    string smtype;
    switch(move_type){
        case 0: 
            smtype = "INIT";
            break;
        case 1:
            smtype = "DISPLACE";
            break;
        case 2:
            smtype = "INSERT";
            break;
        case 3:
            smtype = "REMOVE";
            break;
        default:
            smtype = "NO MOVE";
            break;
    }
    config_log << "[[ Move type: " << smtype << "; Time elapsed since start: " << (clock() - start)/CLOCKS_PER_SEC << " ]]" << endl;
    for(vector<vector<double> >::iterator it = particles.begin(); it < particles.end(); it++){
        config_log << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << endl;   
    }
    config_log << "[[ No. of particles = " << N << " ]]" << endl;
    config_log << endl;
    npart.push_back(N);
}

void log_histogram(){
    for(int i = 0; i < npart.size(); i++){
        hgram[npart[i]] += 1;    
    }
    map<int,int>::iterator it;
    for(it = hgram.begin(); it!= hgram.end(); it++){
        hgram_data << it->first << " " << it->second << endl;
    }
}

void log_finalize(){
    cout << "----STATISTICS----" << endl;
    printf("Acceptance:: Displacements: %d/%d = %lf, Insertions: %d/%d = %lf, Removals: %d/%d = %lf\n", succ_disp, att_disp, (double) 1.0*succ_disp/att_disp, succ_ins, att_ins, (double) 1.0*succ_ins/att_ins, succ_del, att_del, (double) 1.0*succ_del/att_del);
    double npartsum = 0;
    for(int i = 0; i < npart.size(); i++){
        npartsum += npart[i];   
    }
    cout << "Average number of particles = " << npartsum/npart.size() << endl;
    log_histogram();
    config_log.close();
    hgram_data.close();        
}
