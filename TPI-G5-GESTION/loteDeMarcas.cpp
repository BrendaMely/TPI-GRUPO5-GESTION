#include <iostream>
#include "lotedeMarcas.h"

using namespace std;


void cargarLoteDeMarcas(Marcas marca[], bool& loteDeMarcasCargado)
{
    cout<< "1. Cargar lote de marcas"<<endl;

        for(int i=0; i<10; i++){

        ///CODIGO MARCA
        do
        {
            cout<<"Ingresar código de marca:"<<endl;
            cin>>marca[i].codMarca;

            if(marca[i].codMarca<1||marca[i].codMarca>10)
            {
                cout<<"Error: Ingrese un código de marca del 1 al 10."<<endl;
            }
        }
        while(marca[i].codMarca<1||marca[i].codMarca>10); ///VI

        ///Limpiar el buffer de entrada
        cin.ignore();

        ///NOMBRE MARCA
        do
        {
            cout<<"Ingresar nombre de marca:"<<endl;

            getline(cin, marca[i].nombreMarca); ///LE

            if(marca[i].nombreMarca==""|| marca[i].nombreMarca==" ")
            {
                cout<<"Error: Ingresar un nombre de marca (no puede estar vacio)."<<endl;
            }
        }
        while(marca[i].nombreMarca==""|| marca[i].nombreMarca==" ");
    }

    loteDeMarcasCargado=true;

    return;
}




