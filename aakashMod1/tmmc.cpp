/*
 * tmmc.cpp
 *
 *  Created on: 19-Nov-2017
 *      Author: ishan
 */
#include "tmmc.h"
#include "common_params.h"
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void tmmc_update(double accProb,bool inc,bool UpdateNorm){
	if (inc){
		if( Nmax<N+1){
			Nmax=N;
			tmmcC.push_back({0,0,0});
			tmmcN.push_back({0,0,0});
		}
		tmmcC[N][0] = tmmcC[N][0] + accProb ;
		tmmcC[N][1] = tmmcC[N][1] + 1 - accProb ;
	}
	else {
		tmmcC[N][2] = tmmcC[N][2] + accProb ;
		tmmcC[N][1] = tmmcC[N][1] + 1 - accProb ;
	}
	if (UpdateNorm){
         for (int i=0;i<=Nmax;i+=1){
        	 tmmcRsum = tmmcC[i][0]+tmmcC[i][1]+tmmcC[i][2];
             tmmcN[i][0]=tmmcC[i][0]/tmmcRsum;
             tmmcN[i][1]=tmmcC[i][1]/tmmcRsum;
             tmmcN[i][2]=tmmcC[i][2]/tmmcRsum;
         	 }


	}
}
