#ifndef LOTEDEVENTAS_H_INCLUDED
#define LOTEDEVENTAS_H_INCLUDED
#include <iostream>

using namespace std;
    struct Ventas
    {
    int numeroCompra;
    int codigoProducto;
    string formaDePago;
    int cantidadVendida;
    int codigoCliente;
    int diaVenta;
    };
    void loteDeVentas(Ventas venta);

#endif // LOTEDEVENTAS_H_INCLUDED
