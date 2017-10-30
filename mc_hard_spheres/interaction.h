#ifndef INTERACTION
#define INTERACTION

#include "common_params.h"
#include<cmath>
#include<vector>
#include<list>

using namespace std;
//optimization: cell list
void make_cell_list();
int map_box(vector<int>);
void cell_list_insert(vector<double>);
void cell_list_remove(vector<double>);

double dist(vector<double>,vector<double>);
bool overlap(vector<double>,vector<double>);
int energy_hard_displace(vector<double>,int);
int energy_hard_insert(vector<double>);

#endif
