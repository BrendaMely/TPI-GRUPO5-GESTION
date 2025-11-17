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
    int opcion;

    do{
        system("cls"); ///limp pant
        cout<<" REPORTES DISPONIBLES"<<endl;
        cout<<endl;
        cout<< "1. Recaudación por producto"<<endl;
        cout<< "2. Porcentaje de ventas por forma de pago"<<endl;
        cout<< "3. Ventas por marca y forma de pago"<<endl;
        cout<< "4. Productos sin ventas "<<endl;
        cout<< "5. Top 10 clientes + sorteo de cupones "<<endl;
        cout<< "0. Salir"<<endl;
        cout<<endl;
        cout<< "Ingrese opcion: ";
        cin>>opcion;

        switch (opcion){
        case 1:
            recaudacionPorProducto();
            break;
        case 2:
            porcentajeDeVentasPorFP();
            break;
        case 3:
            ventasPorMarcayPorFP();
            break;
        case 4:
            productosSinVentas();
            break;
        case 5:
            top10ClientesMasSorteo();
            break;
        case 0:
            cout<<"Saliendo del programa.."<<endl;
            break;
        default:
        cout<<"Opcion no valida!"<<endl;
        break;
        }
        system("pause");
    }while(opcion!=0);




}
