#include <iostream>
#include "loteDeFormasDePago.h"
using namespace std;

 void cargarLoteDeFormasDePago(FormasDePago formaDePago[], bool& loteDeFormasDePagoCargado)
    {

    string codigoValidos[5]= {"EF","MP","TR","TC","CT"};

    cout<< "3. Cargar lote de formas de pago"<<endl;

    ///CODIGO DE FORMA DE PAGO

    for(int i=0; i<5; i++){
                bool codValido; ///verificar
                bool codDuplicado;

            do{
                codValido=false;
                codDuplicado=false;

                cout<<"Ingresar el código de forma de pago:"<<endl;

                if(i==0){
                   cin.ignore();
                }


                getline(cin, formaDePago[i].codigoFP);

                for(int j=0; j<5; j++){
                    if(codigoValidos[j]==formaDePago[i].codigoFP){
                        codValido=true;
                        break;
                    }
                }

                if(codValido==false){
                cout<<"Error: El codigo ingresado es invalido, ingrese otro codigo (EF, MP, TR, TC, CT)"<<endl;
                }

                ///BUSCAR SI SE INGRESO EL CODIGO ANTERIORMENTE

                if(codDuplicado==false){
                    if(i==0){
                        codDuplicado=false;
                    }
                    if(codValido==true && i>0){
                        for(int k=0; k<i; k++){
                            if(formaDePago[i].codigoFP==formaDePago[k].codigoFP){
                                codDuplicado=true;
                                break;
                            }
                        }
                    }
                }

                if(codDuplicado==true){
                cout<<"Error: El codigo ingresado ya esta cargado, ingrese otro codigo"<<endl;
                }

            }
            while(codValido==false||codDuplicado==true);







            ///NOMBRE DE FORMA DE PAGO

        do
        {
            cout<<"Ingresar nombre de la forma de pago:"<<endl;

            getline(cin, formaDePago[i].nombreFP);

            if(formaDePago[i].nombreFP==""||formaDePago[i].nombreFP==" ")
            {
                cout<<"Error. El nombre de la forma de pago no puede estar vacío."<<endl;
            }
        }
        while(formaDePago[i].nombreFP==""||formaDePago[i].nombreFP==" ");



        ///PORCENTAJE DE INTERES O DESCUENTO

        cout<<"Ingresar porcentaje de descuento o interés:"<<endl;
        cin>>formaDePago[i].porcentajeDescuentoInteres;
        cin.ignore();

    }
    loteDeFormasDePagoCargado=true;
    return;
}
