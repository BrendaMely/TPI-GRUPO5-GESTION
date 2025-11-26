#include <iostream>
#include "lotedeMarcas.h"
#include "loteDeProductos.h"
#include "loteDeFormasDePago.h"
#include "loteDeVentas.h"
#include "mostrarReportes.h"
#include <locale> /// Para las letras en español

using namespace std;

int main()
{
    setlocale(LC_ALL, "Spanish");


    int opcion;

    Marcas marca[10]= {};
    bool loteDeMarcasCargado=false;

    Productos producto[20]= {};
    bool loteDeProductosCargado=false;

    FormasDePago formaDePago[5]= {};
    bool loteDeFormasDePagoCargado=false;

    ///ACUMULADORES PARA REPORTES:
    ///Punto 1
    float totalRecaudadoPorProducto[20]={};
    int cantidadVendidaPorProducto[20]={};

    ///Punto 2
    float acumVentasXFP[5]={};
    float contVentasTotales=0;

    ///Punto 3
    int cantTotalVendProdPorMarcaYPorFP[10][5]={};

    ///Punto 5

    int cantidadDeComprasPorCliente[51]={};


    do{
        system("cls"); ///limp pant
        cout<<" MENU PRINCIPAL"<<endl;
        cout<<endl;
        cout<< "1. Cargar lote de marcas"<<endl;
        cout<< "2. Cargar lote de productos"<<endl;
        cout<< "3. Cargar lote de formas de pago"<<endl;
        cout<< "4. Cargar lote de ventas "<<endl;
        cout<< "5. Mostrar reportes "<<endl;
        cout<< "0. Salir"<<endl;
        cout<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
            cargarLoteDeMarcas(marca, loteDeMarcasCargado);
            break;
        case 2:
            cargarLoteDeProductos(producto, loteDeProductosCargado, marca, loteDeMarcasCargado);
            break;
        case 3:
            cargarLoteDeFormasDePago(formaDePago, loteDeFormasDePagoCargado);
            break;
        case 4:
            procesarLoteDeVentas(marca, loteDeMarcasCargado, producto, loteDeProductosCargado, formaDePago, loteDeFormasDePagoCargado, totalRecaudadoPorProducto, cantidadVendidaPorProducto, acumVentasXFP, contVentasTotales, cantTotalVendProdPorMarcaYPorFP, cantidadDeComprasPorCliente);
            break;
        case 5:
            mostrarReportes(marca, producto, formaDePago, totalRecaudadoPorProducto, cantidadVendidaPorProducto, acumVentasXFP, contVentasTotales, cantTotalVendProdPorMarcaYPorFP, cantidadDeComprasPorCliente);
            break;
        case 0:
            cout<<"Saliendo del programa.."<<endl;
            break;
        default:
        cout<<"Opcion no valida!"<<endl;
        break;
        }
        ///system("pause"); ///Deja en pausa para que no desaparesca todo por el system("clr");
    }while(opcion!=0);
    return 0;
}
