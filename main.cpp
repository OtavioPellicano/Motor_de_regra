#include <iostream>
#include "pmt.h"



using namespace std;

int main()
{

    //SEMIGLOBE
    string dataRef = "\"12/19/2017 03:00\"";
    string ufCliente = "GO";
    string ufServidor = "AC";
    opmm::layout tipoLayout = opmm::layout::SEMIGLOBE;

    opmm::PMT sky(dataRef, ufServidor, ufCliente, tipoLayout);




    cout << "Hello World!" << endl;
    return 0;
}
