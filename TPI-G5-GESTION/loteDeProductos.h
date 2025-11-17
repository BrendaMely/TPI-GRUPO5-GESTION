#ifndef LOTEDEPRODUCTOS_H_INCLUDED
#define LOTEDEPRODUCTOS_H_INCLUDED
#include <iostream>

using namespace std;

        struct Productos{
    int codigo;
    string nombre;
    float precioVenta;
    float precioCompra;
    int stock;
    int codigoDeMarca;
    };
    void loteDeProductos(Productos producto[], bool &cargaMarcaFlag);

#endif // LOTEDEPRODUCTOS_H_INCLUDED
