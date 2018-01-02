#include <iostream>
#include "pmt.h"



using namespace std;

int main()
{

    //SEMIGLOBE
    //string dataRef = "\"12/19/2017 03:00\"";    //SEMIGLOBE
    string dataRef = "\"2017-11-30 23:42:13\""; //TGR

    string ufCliente = "GO";
    string ufServidor = "AC";
    //opmm::layout tipoLayout = opmm::layout::SEMIGLOBE;
    opmm::layout tipoLayout = opmm::layout::TGR;

    opmm::PMT claro(dataRef, ufServidor, ufCliente, tipoLayout);




    cout << "Hello World!" << endl;
    return 0;
}
