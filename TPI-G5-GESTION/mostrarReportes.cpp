#include <iostream>
#include "mostrarReportes.h"

using namespace std;

///PUNTO 1
void recaudacionPorProducto(Productos producto[], float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[]);

///PUNTO 2
void porcentajeDeVentasPorFP(FormasDePago formaDePago[], float acumVentasXFP[], float& contVentasTotales);

///PUNTO 3
void ventasPorMarcayPorFP(Marcas marca[], FormasDePago formaDePago[], int cantTotalVendProdPorMarcaYPorFP[10][5]);

///PUNTO 4
void productosSinVentas(Productos producto[], int cantidadVendidaPorProducto[]);

///PUNTO 5
void top10ClientesMasSorteo(int cantidadDeComprasPorCliente[]);

void mostrarReportes(Marcas marca[], Productos producto[], FormasDePago formaDePago[],  float totalRecaudadoPorProducto[],  int cantidadVendidaPorProducto[], float acumVentasXFP[], float& contVentasTotales, int cantTotalVendProdPorMarcaYPorFP[10][5], int cantidadDeComprasPorCliente[]){



    ///SUBMENU REPORTES

    setlocale(LC_ALL, "Spanish");
    char opcion;

    do{
        system("cls"); ///limp pant
        cout<<" REPORTES DISPONIBLES"<<endl;
        cout<<endl;
        cout<< "A. Recaudación por producto"<<endl;
        cout<< "B. Porcentaje de ventas por forma de pago"<<endl;
        cout<< "C. Ventas por marca y forma de pago"<<endl;
        cout<< "D. Productos sin ventas "<<endl;
        cout<< "E. Top 10 clientes + sorteo de cupones "<<endl;
        cout<< "0. Volver al menu principal"<<endl;
        cout<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;

        switch (opcion){
        case 'A':
            recaudacionPorProducto(producto, totalRecaudadoPorProducto, cantidadVendidaPorProducto);
            break;
        case 'B':
            porcentajeDeVentasPorFP(formaDePago, acumVentasXFP, contVentasTotales);
            break;
        case 'C':
            ventasPorMarcayPorFP(marca, formaDePago, cantTotalVendProdPorMarcaYPorFP);
            break;
        case 'D':
            productosSinVentas(producto, cantidadVendidaPorProducto);
            break;
        case 'E':
            top10ClientesMasSorteo(cantidadDeComprasPorCliente);
            break;
        case '0':
            cout<<"Volviendo al menu principal"<<endl;
            break;
        default:
        cout<<"Opcion no valida!"<<endl;
        break;
        }
        system("pause");
    }while(opcion!='0');


}

///DESARROLLO PUNTOS

///PUNTO 1 - Emitir un listado con el total recaudado por producto ordenado de mayor a menor por cantidad vendida.

void recaudacionPorProducto(Productos producto[], float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[]){

    struct RecaudacionProducto{
        int codProductoRXP;
        string nombreProductoRXP;
        float totalRecaudadoRXP;
        int cantidadVendidaRXP;
        int stockRemanenteRXP;
    };

    RecaudacionProducto recaudacion[20]={}; ///inic?

    for(int i=0; i<20; i++){
        recaudacion[i].codProductoRXP = producto[i].codProd;
        recaudacion[i].nombreProductoRXP = producto[i].nombreProd;
        recaudacion[i].totalRecaudadoRXP = totalRecaudadoPorProducto[i]; ///Se guardaba segun indice en lote de prod
        recaudacion[i].cantidadVendidaRXP = cantidadVendidaPorProducto[i]; ///Se guardaba segun indice en lote de prod
        recaudacion[i].stockRemanenteRXP= producto[i].stockDisp - cantidadVendidaPorProducto[i];
    }

    ///ORDENAR EL STRUC COMPLETO DE MAYOR A MENOR POR CANTIDAD VENDIDA

    for(int i=0; i<19; i++){///20 max 19 vueltas para ordenar
        bool intercambio=false;

        for(int j=0; j<19-i; j++){

            if(recaudacion[j].cantidadVendidaRXP<recaudacion[j+1].cantidadVendidaRXP){ ///actual j con el siguiente

                RecaudacionProducto aux={}; ///para mover todo cant, cod, nombre, etc. Va asignando

                aux=recaudacion[j];///el menor
                recaudacion[j]=recaudacion[j+1];///el mayor queda en j
                recaudacion[j+1]=aux; ///el menor en j+1
                intercambio=true; ///si hubo intercambio
            }

        }

        if(intercambio==false) break; ///si ya esta ordenado (si en todo i no hubo intercambio)
    }

    ///MOSTRAR REPORTE TOTAL RECAUDADO POR PRODUCTO ORDENADO DE MAYOR A MENOR POR CANTIDAD VENDIDA
    cout<<"RECAUDACIÓN POR PRODUCTO ORDENADO POR CANTIDAD DE MAYOR A MENOR: "<<endl<<endl;
    for(int i=0; i<20; i++){
        cout<<"Codigo del Producto: "<<recaudacion[i].codProductoRXP<<endl;
        cout<<"Nombre del Producto:"<<recaudacion[i].nombreProductoRXP<<endl;
        cout<<"Total Recaudado:"<<recaudacion[i].totalRecaudadoRXP <<endl;
        cout<<"Cantidad Vendida:"<<recaudacion[i].cantidadVendidaRXP<<endl;
        cout<<"Stock Remanente:"<<recaudacion[i].stockRemanenteRXP<<endl;
        cout<<endl;

    }
         system("pause");

       /* ///ORDENADO POR TOTAL RECAUDADO DE MENOR A MAYOR
       for(int i=0; i<20; i++){
            bool intercambio=false;

            for(int j=0; j<19-i; j++){
                if(totalRecaudadoPorProducto[j]>totalRecaudadoPorProducto[j+1]){
                    int aux = totalRecaudadoPorProducto[j+1];///aux 1-
                    totalRecaudadoPorProducto[j+1]=totalRecaudadoPorProducto[j]; ///2-
                    totalRecaudadoPorProducto[j]=aux; ///1-
                    intercambio=true;
                }
            }
            if(intercambio==false) break;

            ///ORDENADO POR TOTAL RECAUDADO DE MAYOR A MENOR
            for(int i = 0; i < 20; i++) {
        bool intercambio = false;

        for(int j = 0; j < 19 - i; j++) {

        if(totalRecaudadoPorProducto[j] < totalRecaudadoPorProducto[j+1]) {
            int aux = totalRecaudadoPorProducto[j+1]; ///EL MAYOR QUEDA EN AUX
            totalRecaudadoPorProducto[j+1] = totalRecaudadoPorProducto[j]; ///QUEDA EL MENOR
            totalRecaudadoPorProducto[j] = aux; ///QUEDA EL MAYOR
            intercambio = true;
        }
    }
    if(intercambio == false) break;
}
        }*/

}

///PUNTO 2 - Porcentaje de ventas por forma de pago:
void porcentajeDeVentasPorFP(FormasDePago formaDePago[], float acumVentasXFP[], float& contVentasTotales){

    struct PorcentajeVentasXFP{
    string nombreFDP;
    float porcentajeVentasFDP;
    };

    PorcentajeVentasXFP porcentaje[5]={};

    for(int i=0; i<5; i++){
        porcentaje[i].nombreFDP=formaDePago[i].nombreFP;

        if(contVentasTotales>0){
          porcentaje[i].porcentajeVentasFDP=acumVentasXFP[i]*100/contVentasTotales; ///acumulaba la cantidad de ventas segun indice del Lote de FP
        }
    }

    ///MOSTRAR
    cout<<"PORCENTAJE DE VENTAS POR FORMA DE PAGO: "<<endl<<endl;
    for(int i=0; i<5; i++){
        cout<<"Nombre de Forma de Pago: "<<porcentaje[i].nombreFDP<<endl;
        cout<<"Porcentaje de ventas: "<<porcentaje[i].porcentajeVentasFDP<<endl;
    }
    system("pause");
}

///PUNTO 3 La cantidad total vendida de productos de cada marca discriminada por forma de pago.


void ventasPorMarcayPorFP(Marcas marca[], FormasDePago formaDePago[], int cantTotalVendProdPorMarcaYPorFP[10][5]){

cout<<"CANTIDAD TOTAL VENDIDA DE PRODUCTOS POR MARCA Y FORMA DE PAGO: "<<endl<<endl;

    for(int i=0; i<10; i++){
        cout<<"LA CANTIDAD TOTAL DE PRODUCTOS VENDIDOS DE LA MARCA: "<<marca[i].nombreMarca<<endl;
        for(int j=0; j<5; j++){
            cout<<" De Forma de Pago "<<formaDePago[j].nombreFP<<": es de: "<<cantTotalVendProdPorMarcaYPorFP[i][j]<<" productos."<<endl;
        }
        cout<<"\t"<<endl;
    }
    system("pause");

}

///PUNTO 4 - Emitir un listado con los productos que no registraron ninguna venta. Incluir el código y nombre del producto.

void productosSinVentas(Productos producto[], int cantidadVendidaPorProducto[]){ ///DEL PUNTO 1
    cout<<"PRODUCTOS SIN VENTAS: "<<endl;

    for(int i=0; i<20; i++){
        if(cantidadVendidaPorProducto[i]==0){
            cout<<"El codigo "<<producto[i].codProd<<" que corresponde al producto: "<<producto[i].nombreProd<<", no registro ventas"<<endl;
        }
    }
    system("pause");
}

///PUNTO 5 - Calcular el top 10 de clientes con más compras realizadas (por cantidad de compras).○
///Elegir aleatoriamente 3 de ellos y otorgarles un cupón de descuento.
///Mostrar el top 10 y los 3 ganadores con su código de cliente y cantidad de compras

void top10ClientesMasSorteo(int cantidadDeComprasPorCliente[]){
    struct Clientes{
    int codCliente;
    int cantCompras;
    };

    Clientes cliente[50]={};
    for(int i=0; i<50; i++){
        cliente[i].codCliente=i;
        cliente[i].cantCompras=cantidadDeComprasPorCliente[i]; ///ACUMULADOR DEL LOTE VENTA
    }

    ///ORDENAR DE MAYOR A MENOR TODO EL STRUCT POR CANTIDAD DE COMPRAS POR CLIENTE
    for(int i=0; i<49; i++){
        bool intercambio=false;

        for(int j=0; j<49-i; j++){
            if(cliente[j].cantCompras<cliente[j+1].cantCompras){

                Clientes aux={};

                aux=cliente[j];///elm menor
                cliente[j]=cliente[j+1];///queda el mayor
                cliente[j+1]=aux; ///queda el menor
                intercambio=true;
            }
        }
        if(intercambio==false) break;
    }

    ///MUESTRO LOS PRIMEROS 10 CLIENTES (LAS PRIMERAS 10 POSICIONES)

    cout<<"El top 10 clientes que realizarón más compras son: "<<endl;

    srand(time(NULL)); ///inicializar srand() con el tiempo actual

    for(int i=0; i<10; i++){
        cout<<"El cliente: "<<cliente[i].codCliente<<" con "<<cliente[i].cantCompras<<" compras"<<endl;
    }

    ///TOP 3 SORTEO
    for(int i=0; i<3; i++){
        int indiceAleatorio= rand()%10; ///entre 10 elige 3 aleatoriamente

        cout<<"El ganador N-: "<<i+1<<" del cupón de descuento , es el Cliente: "<<cliente[indiceAleatorio].codCliente<<" con "<<cliente[indiceAleatorio].cantCompras<<" compras."<<endl;
    }
    system("pause");

}







