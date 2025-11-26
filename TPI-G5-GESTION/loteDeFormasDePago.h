#ifndef LOTEDEFORMASDEPAGO_H_INCLUDED
#define LOTEDEFORMASDEPAGO_H_INCLUDED

using namespace std;
    struct FormasDePago
    {
    string codigoFP;
    string nombreFP;
    int porcentajeDescuentoInteres;
    };

    void cargarLoteDeFormasDePago(FormasDePago formaDePago[], bool& loteDeFormasDePagoCargado);

#endif // LOTEDEFORMASDEPAGO_H_INCLUDED
