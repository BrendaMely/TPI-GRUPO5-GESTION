#include <iostream>
#include "loteDeProductos.h"
using namespace std;


 void cargarLoteDeProductos(Productos producto[], bool& loteDeProductosCargado, Marcas marca[], bool& loteDeMarcasCargado)
{
   ///VERIFICA LA CARGA DE LOTE DE MARCAS

    if (loteDeMarcasCargado==false)
    {
        cout<<"Error: El lote de marcas no esta cargado"<<endl;
        cout<<"Redirigiendo al Menú Principal"<<endl;

        system("pause");
        return;
    }

    ///INICIALIZA AL SALIR SI UNA VALIDACION NO SE CUMPLE
    for(int i=0; i<20; i++){
        producto[i]={};
    }

    loteDeProductosCargado=false;

    cout<< "2. Cargar lote de productos"<<endl;

    for(int i=0; i<20; i++){

        /// Si hubiese un error en una validació, redirigir al menú principal para que se vuelva a ejecutar el proceso de carga desde cero.

        ///CODIGO PRODUCTO: Entero, 3 digitos, no consecutivos
        cout<<"Ingresar código de producto:"<<endl;
        cin>>producto[i].codProd;

        if(producto[i].codProd<100||producto[i].codProd>999)
        {
            cout<<"El codigo de producto debe ser de 3 digitos"<<endl;
            cout<<"Redirigiendo al Menú Principal"<<endl;

            system("pause");
            return;
        }
        ///no consecutivos
         if(i>0){
                if(producto[i].codProd==producto[i-1].codProd+1||producto[i].codProd==producto[i-1].codProd-1){
                    cout<<"El codigo de producto no puede ser consectivo al codigo de producto anterior."<<endl;
                    cout<<"El codigo de producto anterior es: "<<producto[i-1].codProd<<endl;
                    cout<<"Redirigiendo al Menú Principal"<<endl;

                    system("pause");
                    return;
                }
        }


        ///Limpiar el buffer de entrada
        cin.ignore();

        ///NOMBRE DE PRODUCTO
        cout<<"Ingresar nombre del Producto:"<<endl;
        getline(cin, producto[i].nombreProd);

        if(producto[i].nombreProd==""||producto[i].nombreProd==" ")
        {
            cout<<"Error: Ingresar un nombre de producto (no puede estar vacio)."<<endl;
            cout<<"Redirigiendo al Menú Principal"<<endl;

            system("pause");
            return;
        }


        ///PRECIO DE VENTA
        cout<<"Ingresar precio de venta:"<<endl;
        cin>>producto[i].precioVenta;

        if(producto[i].precioVenta<=0)
        {
            cout<<"Error: El precio de venta no puede ser 0 o negativo."<<endl;
            cout<<"Redirigiendo al Menú Principal"<<endl;

            system("pause");
            return;
        }


        ///PRECIO DE COMPRA
        cout<<"Ingresar precio de compra:"<<endl;
        cin>>producto[i].precioCompra;
        if(producto[i].precioCompra<=0)
        {
            cout<<"Error: El precio de compra no puede ser 0 o negativo."<<endl;
            cout<<"Redirigiendo al Menú Principal"<<endl;

            system("pause");
            return;
        }


        ///STOCK DISPONIBLE
        cout<<"Ingrese el stock disponible:"<<endl;
        cin>>producto[i].stockDisp;

        if(producto[i].stockDisp<0)
        {
            cout<<"Error: La cantidad de stock no puede ser negativa."<<endl;
            cout<<"Redirigiendo al Menú Principal"<<endl;

            system("pause");
            return;
        }

        ///CODIGO DE MARCA
        cout<<"Ingrese el código de marca"<<endl;
        cin>>producto[i].codDeMarca;

        ///CODIGO DE MARCAS DEBE EXISTIR EN EL LOTE DE MARCAS CARGADO PREVIAMENTE
        bool existeCodigoDeMarca= false;

        for(int j=0; j<10; j++){
             if(producto[i].codDeMarca==marca[j].codMarca){
            existeCodigoDeMarca= true;
            break;
            }
        }

        if(existeCodigoDeMarca==false){
                cout<<"Error: Debe ingresar un código de marca válido."<<endl;

                cout<<"Redirigiendo al Menú Principal"<<endl;

                system("pause");
                return;
        }


    }
    loteDeProductosCargado=true;
    return;
}
