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
    bool cargaMarcaFlag=false;

    Productos producto[20]= {};

    FormasDePago formaDePago[5]= {};

    Ventas venta= {};

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
            loteDeMarcas(marca, cargaMarcaFlag);
            break;
        case 2:
            loteDeProductos(producto, cargaMarcaFlag);
            break;
        case 3:
            loteDeFormasDePago(formaDePago);
            break;
        case 4:
            loteDeVentas(venta);
            break;
        case 5:
            mostrarReportes();
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
