#ifndef LOTEDEVENTAS_H_INCLUDED
#define LOTEDEVENTAS_H_INCLUDED
#include "lotedeMarcas.h"
#include "loteDeProductos.h"
#include "loteDeFormasDePago.h"

using namespace std;

    void procesarLoteDeVentas(Marcas marca[], bool& loteDeMarcasCargado, Productos producto[], bool& loteDeProductosCargado, FormasDePago formaDePago[], bool& loteDeFormasDePagoCargado,  float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[],  float acumVentasXFP[], float& contVentasTotales, int cantTotalVendProdPorMarcaYPorFP[10][5], int cantidadDeComprasPorCliente[]);

    ///Los registros de este lote, a diferencia de los lotes anteriores, se cargan pero no se guardan.

#endif // LOTEDEVENTAS_H_INCLUDED
