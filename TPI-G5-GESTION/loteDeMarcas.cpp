#include <iostream>
#include "lotedeMarcas.h"
using namespace std;



void loteDeMarcas(Marcas marca[], bool &cargaMarcaFlag)
{
    cout<< "1. Cargar lote de marcas"<<endl;
    for(int i=0; i<10; i++)
    {

        do
        {
            cout<<"Ingresar código de marca:"<<endl;
            cin>>marca[i].codigo;
            if(marca[i].codigo<1||marca[i].codigo>10)
            {
                cout<<"Por favor ingresar un código de marca del 1 al 10."<<endl;
            }
        }
        while(marca[i].codigo<1||marca[i].codigo>10);

        // Limpiar el buffer de entrada
        cin.ignore();

        do
        {
            cout<<"Ingresar nombre de marca:"<<endl;
            getline(cin, marca[i].nombre);
            if(marca[i].nombre=="")
            {
                cout<<"Por favor ingresar un nombre de marca que no sea vacío."<<endl;
            }
        }
        while(marca[i].nombre=="");
    }

    cargaMarcaFlag=true;

    return;
}




