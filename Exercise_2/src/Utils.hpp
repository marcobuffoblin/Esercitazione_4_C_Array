#pragma once
#include <iostream>
using namespace std;

bool ImportVectors(const string& inputFilePath,int& n,double& S,double*& w, double*& r);
double portafoglio(const double S,const int n,double* ptr_w, double* ptr_r);
double interesse(double portafoglio,double S);
bool ExportResult(const string& outputFilePath,const int& n,const double& S,double*& w,double*& r,const double& portafoglio, const double& interesse);

