#include <iostream>
#include "Utils.hpp"
using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    string outputFileName = "./result.csv";
    int n = 0;
    double S=0;
    double* w = nullptr;
    double* r = nullptr;


    //Importazione dati
    if (!ImportVectors(inputFileName,n,S, w, r))
    {
        cerr<< "Errore di importazione"<< endl;
        return 1;
    }


    //Esportazione dati
    if (!ExportResult(outputFileName,n,S, w, r, portafoglio(S,n,w,r),interesse(portafoglio(S,n,w,r),S)))
    {
        cerr<< "Errore di esportazione"<< endl;
        return 1;
    }
    else
        cout<< "Esportazione eseguita con successo"<< endl;


    //Deallocazzione della memoria
    delete[] w;
    delete[] r;


    return 0;
}
