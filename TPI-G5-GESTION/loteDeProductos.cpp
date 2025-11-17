#include <iostream>
#include "loteDeProductos.h"
using namespace std;


 void loteDeProductos(Productos producto[], bool &cargaMarcaFlag)
{
    if (cargaMarcaFlag==false)
    {
        cout<<"Debe ingresar primero el lote de marcas."<<endl;
        return;
    }

    cout<< "2. Cargar lote de productos"<<endl;
    for(int i=0; i<20; i++)
    {
        /// No lleva do-while ya que cualquier error en la carga tiene que redirigirse al menu principal
        /// mostrando el error correspondiente por consola

        cout<<"Ingresar código de producto:"<<endl;
        cin>>producto[i].codigo;
        if(producto[i].codigo<100||producto[i].codigo>999)
        {
            cout<<"El codigo de producto debe ser de 3 digitos numericos."<<endl;
            return;
        }


        // Limpiar el buffer de entrada
        cin.ignore();

        cout<<"Ingresar nombre del Producto:"<<endl;
        getline(cin, producto[i].nombre);
        if(producto[i].nombre=="")
        {
            cout<<"Por favor ingresar un nombre de producto que no sea vacío."<<endl;
            return;
        }



        cout<<"Ingresar precio de venta:"<<endl;
        cin>>producto[i].precioVenta;
        if(producto[i].precioVenta<=0)
        {
            cout<<"El precio de venta no puede ser 0 o negativo."<<endl;
            return;
        }



        cout<<"Ingresar precio de compra:"<<endl;
        cin>>producto[i].precioCompra;
        if(producto[i].precioCompra<=0)
        {
            cout<<"El precio de compra no puede ser 0 o negativo."<<endl;
            return;
        }



        cout<<"Ingrese el stock disponible:"<<endl;
        cin>>producto[i].stock;
        if(producto[i].stock<0)
        {
            cout<<"La cantidad de stock no puede ser negativa."<<endl;
            return;
        }

        cout<<"Ingrese el código de marca"<<endl;
        cin>>producto[i].codigoDeMarca;
        if(producto[i].codigoDeMarca<0||producto[i].codigoDeMarca>10)
        {
            cout<<"Debe ingresar un código de marca válido."<<endl;
            return;
        }

    }

    return;
}
