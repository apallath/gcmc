#include "sampling.h"

ofstream rdf_data;

void sample_init(){
    //functions for RDF calculation
    rdf_data.open("rdf.dat");
    rdf_data << ncycles/samp_ival << endl;
}

void sample_rdf(double r_max, double dr){
//calculate the rdf at multiple points, append output to the rdf file  
    double rho = (N * 4.0 / 3.0 * M_PI * pow(sigma,3)) / (pow(L,3));
    
    //redundant, but still
    if(rho <= 0){
        return;
    }

    int rdf_len = (int) r_max/dr;
    
    //select reference particles such that a sphere of radius r_max will not cross the boundaries
    vector<int> reference_parts(0);


    for(int i = 0; i < N; i++){
        if(particles[i][0] > r_max && particles[i][0] < L - r_max && 
           particles[i][1] > r_max && particles[i][1] < L - r_max &&
           particles[i][2] > r_max && particles[i][2] < L - r_max){
            reference_parts.push_back(i);    
        }
    }

    if(reference_parts.size() == 0){
        return;
    }

    vector<double> rdf_template(rdf_len,0);

    vector<vector<double> > rdf;
    for(int i = 0; i < reference_parts.size(); i++){
        rdf.push_back(rdf_template);
    }
    vector<double> avg_rdf(rdf_len,0);

    //calculate pair correlation for each reference particle
    for(int i = 0; i < reference_parts.size(); i++){
        int p = reference_parts[i];
        double xp = particles[p][0]; double yp = particles[p][1]; double zp = particles[p][2];

        for(int rpt = 0; rpt < rdf_len; rpt++){
            double r = rpt*dr + dr;
            for(int j = 0; j < N; j++){      
                double x = particles[j][0]; double y = particles[j][1]; double z = particles[j][2];    
                double dist = sqrt( pow((x - xp),2) + pow((y - yp),2) + pow((z - zp),2) );     
                if(dist > r && dist < r+dr){
                    rdf[i][rpt] += 1;   
                }    
            }
            rdf[i][rpt] = rdf[i][rpt]/(rho * 4 * M_PI * pow(r,2) );
            avg_rdf[rpt] += rdf[i][rpt];
        }
    }
    
    //finalize averages and write out data
    cout << "Writing out rdf. Currently " << N << " particles in system, rho = " << rho << endl;
    for(int rpt = 0; rpt < rdf_len; rpt++){
        rdf_data << (rpt*dr) << " ";
    }
    rdf_data << endl;
    for(int rpt = 0; rpt < rdf_len; rpt++){
        avg_rdf[rpt] = avg_rdf[rpt]/reference_parts.size();
        rdf_data << avg_rdf[rpt] << " ";
    }
    rdf_data << endl;

}

void sample_finalize(){    
    rdf_data.close();
}
