#include <iostream>
#include "loteDeFormasDePago.h"
using namespace std;

 void loteDeFormasDePago(FormasDePago formaDePago[])
{
    string codigoValidos[5]= {"EF","MP","TR","TC","CT"};
    bool flagValido=false;
    bool flagDuplicado=true;
    cout<< "3. Cargar lote de formas de pago"<<endl;
    for(int i=0; i<5; i++)
    {

        do
        {
            cout<<"Ingresar el código de forma de pago:"<<endl;
            cin.ignore();
            getline(cin, formaDePago[i].codigoFP);
            for(int j=0; j<5; j++)
            {
                if(codigoValidos[j]==formaDePago[i].codigoFP)
                {
                    flagValido=true;
                }
            }
            if(flagDuplicado==true)
            {
                if(i==0)
                {
                    flagDuplicado=false;
                }
                else
                {
                    for(int k=0; k<i; k++)
                    {
                        if(formaDePago[k].codigoFP!=formaDePago[i].codigoFP)
                        {
                            flagDuplicado=false;
                        }
                    }
                }
            }
            if(flagDuplicado==true)
            {
                cout<<"Código duplicado"<<endl;
            }
            if(flagValido==false)
            {
                cout<<"Código invalido."<<endl;
            }

        }
        while(flagValido==false||flagDuplicado==true);


        do
        {
            cout<<"Ingresar nombre de la forma de pago:"<<endl;
            getline(cin, formaDePago[i].nombreFP);
            if(formaDePago[i].nombreFP=="")
            {
                cout<<"El nombre de la forma de pago no debe ser vacío."<<endl;
            }
        }
        while(formaDePago[i].nombreFP=="");

        cout<<"Ingresar porcentaje de descuento o interés:"<<endl;
        cin>>formaDePago[i].porcentajeDescuentoInteres;

    }
    return;
}
