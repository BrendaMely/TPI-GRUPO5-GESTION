#include <iostream>
#include "loteDeVentas.h"
using namespace std;

    void loteDeVentas(Ventas venta)
{
    string codigoFPValidos[5]= {"EF","MP","TR","TC","CT"};
    bool flagFPValido;
    cout<< "4. Cargar lote de ventas "<<endl;
    ///*****Ingreas el PRIMER número de compra*****
    do
    {
        cout<<"Ingrese el número de compra:"<<endl;
        cin>>venta.numeroCompra;
        if(venta.numeroCompra<0)
        {
            cout<<"El número de compra no puede ser negativo."<<endl;
        }
        else if(venta.numeroCompra==0)
        {
            return;
        }
    }
    while(venta.numeroCompra<0);
    ///Entra al ciclo del infierno
    do
    {
        do
        {
            cout<<"Ingresar código de producto:"<<endl;
            cin>>venta.codigoProducto;
            if(venta.codigoProducto<100||venta.codigoProducto>999)
            {
                cout<<"El codigo de producto debe ser de 3 digitos numericos."<<endl;

            }
        }
        while(venta.codigoProducto<100||venta.codigoProducto>999);

        do
        {
            flagFPValido = false;
            cout<<"Ingresar el código de forma de pago:"<<endl;
            cin.ignore();
            getline(cin, venta.formaDePago);
            for(int i=0; i<5; i++)
            {
                if(venta.formaDePago==codigoFPValidos[i])
                {
                    flagFPValido = true;
                }
            }
            if(flagFPValido==false)
            {
                cout<<"El codigo de forma de pago es invalido."<<endl;
            }
        }
        while(flagFPValido==false);

        do
        {
            cout<<"Ingresar la cantidad vendida:"<<endl;
            cin>>venta.cantidadVendida;
            if(venta.cantidadVendida<1)
            {
                cout<<"El número de compra no puede ser cero o negativo."<<endl;
            }
        }
        while(venta.cantidadVendida<1);

        do
        {
            cout<<"Ingresar el código de cliente:"<<endl;
            cin>>venta.codigoCliente;
            if(venta.codigoCliente<1||venta.codigoCliente>50)
            {
                cout<<"Codigo de cliente incorrecto. Debe ser entre el 1 al 50."<<endl;
            }
        }
        while(venta.codigoCliente<1||venta.codigoCliente>50);

        do
        {
            cout<<"Ingresar el día de la venta:"<<endl;
            cin>>venta.diaVenta;
            if(venta.diaVenta<1||venta.diaVenta>30)
            {
                cout<<"Número de día incorrecto. Debe ser entre el 1 al 30."<<endl;
            }
        }
        while(venta.diaVenta<1||venta.diaVenta>30);

        ///*****Ingresa el SIGUIENTE número de compra*****
        do
        {
            cout<<"Ingrese el número de compra:"<<endl;
            cin>>venta.numeroCompra;
            if(venta.numeroCompra<0)
            {
                cout<<"El número de compra no puede ser negativo."<<endl;
            }
        }
        while(venta.numeroCompra<0);
    }
    while(venta.numeroCompra!=0);
    return;
}

