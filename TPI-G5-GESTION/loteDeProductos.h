#ifndef LOTEDEPRODUCTOS_H_INCLUDED
#define LOTEDEPRODUCTOS_H_INCLUDED
#include "lotedeMarcas.h"

using namespace std;

    struct Productos{
    int codProd;
    string nombreProd;
    float precioVenta;
    float precioCompra;
    int stockDisp;
    int codDeMarca;
    };

    void cargarLoteDeProductos(Productos producto[], bool& loteDeProductosCargado, Marcas marca[], bool& loteDeMarcasCargado);

#endif // LOTEDEPRODUCTOS_H_INCLUDED
