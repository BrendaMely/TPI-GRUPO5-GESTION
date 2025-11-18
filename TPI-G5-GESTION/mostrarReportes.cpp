#include <iostream>
#include "mostrarReportes.h"
#include "recaudacionPorProducto.h"
#include "porcentajeDeVentasPorFP.h"
#include "ventasPorMarcayPorFP.h"
#include "productosSinVentas.h"
#include "top10ClientesMasSorteos.h"
using namespace std;

void mostrarReportes(){
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
            recaudacionPorProducto();
            break;
        case 'B':
            porcentajeDeVentasPorFP();
            break;
        case 'C':
            ventasPorMarcayPorFP();
            break;
        case 'D':
            productosSinVentas();
            break;
        case 'E':
            top10ClientesMasSorteo();
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
