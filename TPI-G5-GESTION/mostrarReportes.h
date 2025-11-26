#ifndef MOSTRARREPORTES_H_INCLUDED
#define MOSTRARREPORTES_H_INCLUDED
#include <cstdlib> ///contiene la funcion rand()
#include <ctime> ///inicializar la semilla
#include "lotedeMarcas.h"
#include "loteDeProductos.h"
#include "loteDeFormasDePago.h"
#include "loteDeVentas.h"

    void mostrarReportes(Marcas marca[], Productos producto[], FormasDePago formaDePago[],  float totalRecaudadoPorProducto[],  int cantidadVendidaPorProducto[], float acumVentasXFP[], float& contVentasTotales, int cantTotalVendProdPorMarcaYPorFP[10][5], int cantidadDeComprasPorCliente[]);

#endif // MOSTRARREPORTES_H_INCLUDED
