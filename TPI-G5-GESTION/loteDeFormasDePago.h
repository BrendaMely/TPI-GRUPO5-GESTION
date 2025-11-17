#ifndef LOTEDEFORMASDEPAGO_H_INCLUDED
#define LOTEDEFORMASDEPAGO_H_INCLUDED
#include <iostream>

using namespace std;
    struct FormasDePago
{
    string codigoFP;
    string nombreFP;
    int porcentajeDescuentoInteres;
};
void loteDeFormasDePago(FormasDePago formaDePago[]);

#endif // LOTEDEFORMASDEPAGO_H_INCLUDED
