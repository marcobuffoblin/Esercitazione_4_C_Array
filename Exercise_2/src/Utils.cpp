#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<iomanip>
using namespace std;



bool ImportVectors(const string& inputFilePath,int& n,double& S, double*& w,double*& r)
{
    //Apertura file corretta
    ifstream file;
    file.open(inputFilePath);
    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
    //Analizziamo le tre righe di intestazione del file
        // Estraggo una sottostringa dalla prima riga
    string line;
    getline(file,line);
    stringstream ss1;
    ss1<<line.substr(2,line.size());
    ss1>>S;
        // Estraggo una sottostringa dalla seconda riga
    getline(file,line);
    stringstream ss2;
    ss2<<line.substr(2,line.size());
    ss2>>n;
        // Trascuro la terza riga
    getline(file,line);
    // Analizzo i dati contenuti nei due vettori w e r
    w= new double[n];
    r= new double[n];
    int i=0;
    while (getline(file,line)){
        stringstream stringa(line);
        string val_da_prendere;
        getline(stringa,val_da_prendere,';');
        w[i]=stod(val_da_prendere); // stod:coverte la stinga in un double
        getline(stringa,val_da_prendere);
        r[i]=stod(val_da_prendere); // stod:coverte la stinga in un double
        i++;
    }
    // Chiusura file
    file.close();
    return true;
}



double portafoglio(const double S,const int n,double* w, double* r)
{
    double contatore=0;
    for (int i=0;i<n;i++){
        double valore_ptr_w=*w;
        double valore_ptr_r=*r;
        double portafoglio_parziale=(S*valore_ptr_w)*(1+valore_ptr_r);
        contatore=contatore+portafoglio_parziale;
        *w++;
        *r++;
    }
    return contatore;
}



double interesse(double portafoglio,double S)
{
    return (portafoglio/S)-1;
}



bool ExportResult(const string& outputFilePath,const int& n,const double& S,double*& w,double*& r,const double& portafoglio, const double& interesse)
{
    // Apertura file
    ofstream file;
    file.open(outputFilePath);
    if (file.fail())
    {
        cerr<< "Errore di apertura del file"<< endl;
        return false;
    }
    //Scrittura file
    file<< "S="<<fixed<<setprecision(2)<<S<<", n="<<n<<endl;
    file.unsetf(ios::fixed);
    file<< "w=[";
    for (int i = 0; i < n; i++)
        file<<w[i]<<" ";
    file<<"]"<< endl;
    file<< "r=[";
    for (int i = 0; i < n; i++)
        file<< r[i]<<" ";
    file<<"]"<< endl;
    file<< "Rate of return of the portfolio:"<<setprecision(4)<<interesse<<endl;
    file<< "V:"<<fixed<<setprecision(2)<<portafoglio<< endl;
    //Chiusura file
    file.close();
    return true;
}

