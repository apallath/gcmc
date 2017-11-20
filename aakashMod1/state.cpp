#include "state.h"

void save(){
    ofstream state_file;
    state_file.open("particles.state");
    state_file << N << endl;
    for(vector<vector<double> >::iterator it = particles.begin(); it < particles.end(); it++){
        state_file << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << endl;   
    }
    state_file.close();            
}

void collect(){
    ifstream state_file;
    state_file.open("particles.state");
    state_file >> N;
    cout << "Reading in " << N << " particles from state file." << endl;
    for(int i = 0; i < N; i++){
        vector<double> newp(3);
        state_file >> newp[0] >> newp[1] >> newp[2];
        particles.push_back(newp);
    }
    cout << "Finished reading. Updated particle list with " << particles.size() << " particles." << endl;
    state_file.close();    
}
