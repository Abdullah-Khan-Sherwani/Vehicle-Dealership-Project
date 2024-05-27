#ifndef globals_h
#define globals_h

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "vehicle.h"
using namespace std;

extern double saleswallet;
extern map<string, vector<string>> CompanyLog; /*Will store information of all sales with customer mail as key. Will be used by employees only*/
//extern vehicles vehicle; // global variable since static not implemented in vehicle class

#endif /* globals_h */
