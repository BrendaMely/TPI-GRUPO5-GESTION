#include <iostream>
#include "loteDeVentas.h"
using namespace std;

    void procesarLoteDeVentas(Marcas marca[], bool& loteDeMarcasCargado, Productos producto[], bool& loteDeProductosCargado, FormasDePago formaDePago[], bool& loteDeFormasDePagoCargado,  float totalRecaudadoPorProducto[], int cantidadVendidaPorProducto[], float acumVentasXFP[], float& contVentasTotales, int cantTotalVendProdPorMarcaYPorFP[10][5], int cantidadDeComprasPorCliente[]){

    int nroCompra;
    int codProductoVendido;
    string formaPagoPV;
    int cantVendida;
    int codClienteV; ///1-50
    int diaVenta; ///1-30

    ///VERIFICAR QUE LOS LOTES ESTEN CARGADOS
    if(loteDeMarcasCargado==false || loteDeProductosCargado==false || loteDeFormasDePagoCargado==false){
        cout<<"Los Lotes de Marcas, Productos y Formas de pago deben estar cargados previamente"<<endl;
        cout<<"Redirigiendo al Menú Principal "<<endl;
        system("pause");
        return;
    }

    cout<<"Ingresa el Numero de Compra: "<<endl;
    cin>>nroCompra;

    while(nroCompra!=0){

            ///INGRESO Y VALIDACION DE COD DE PRODUCTO

            int indiceDelProducto;

            do{
                cout<<"Ingrese el Codigo de Producto Vendido :"<<endl;
                cin>>codProductoVendido;

                indiceDelProducto=-1;

                for(int i=0; i<20; i++){
                    if(codProductoVendido==producto[i].codProd){
                    indiceDelProducto=i; ///i en lote de productos
                    break;
                    }
                }
                if(indiceDelProducto==-1){
                    cout<<"Error: El codigo de producto ingresado no esta cargado en el lote de productos, ingrese otro codigo"<<endl;
                }

            }
            while(indiceDelProducto==-1);



            ///INGRESO Y VALIDACION DE FORMA DE PAGO

            int indiceDeFormaDePago;
            do{
                cout<<"Ingrese la Forma de pago:"<<endl;
                cin.ignore();
                getline(cin, formaPagoPV);

                indiceDeFormaDePago=-1;

                for(int i=0; i<5; i++){
                    if(formaPagoPV==formaDePago[i].codigoFP){
                        indiceDeFormaDePago=i;
                        break;
                    }
                }
                if(indiceDeFormaDePago==-1){
                    cout<<"Error: El codigo de forma de pago ingresado no esta cargado en el lote de formas de pago, ingrese otro codigo"<<endl;
                }
            }
            while(indiceDeFormaDePago==-1);

            ///PUNTO 2 - Porcentaje de ventas por forma de pago:
            acumVentasXFP[indiceDeFormaDePago]++; ///acumula la cantidad de ventas segun indice del Lote de FP

            ///CANTIDAD VENDIDA
            do{
                cout<<"Ingrese la Cantidad Vendida:"<<endl;
                cin>>cantVendida;

                if(cantVendida<0){
                    cout<<"Error: Ingrese una cantidad vendida mayor a 0"<<endl;
                }
            }
            while(cantVendida<0);

            ///CODIGO DE CLIENTE (1-50)

            do{
                cout<<"Ingrese el Codigo de Ciente:"<<endl;
                cin>>codClienteV;

                if(codClienteV<1 || codClienteV>50){
                    cout<<"Error: El codigo de cliente es un numero entre 1 y 50, ingrese nuevamente el codigo de cliente: "<<endl;
                }
            }
            while(codClienteV<1 || codClienteV>50);


            ///DIA DE VENTA (1-30)

            do{
                cout<<"Ingrese el  Dia de la Venta:"<<endl;
                cin>>diaVenta;
                if(diaVenta<1||diaVenta>30){
                    cout<<"El dia de venta es un numero entre 1 y 30, ingrese nuevamente el dia de venta"<<endl;
                }
            }
            while(diaVenta<1||diaVenta>30);

        ///PUNTO 1 - Emitir un listado con el total recaudado por producto ordenado de mayor a menor por cantidad vendida.

        totalRecaudadoPorProducto[indiceDelProducto]+=cantVendida*producto[indiceDelProducto].precioVenta; ///segun indice en lote de productos
        cantidadVendidaPorProducto[indiceDelProducto]+=cantVendida; ///segun indice en lote de productos

        ///PUNTO 2 - Porcentaje de ventas por forma de pago:
        contVentasTotales++;

        ///PUNTO 3 - La cantidad total vendida de productos de cada marca discriminada por forma de pago.

        ///TENGO COD PROD VENDIDO ///NECESITO EL INDICE DEL CODIGO DE MARCA DEL LOTE DE MARCA PARA ACUMULAR  LA CANT VENDIDA X PROD

        ///1- con el indice del producto saco el codigo de marca del lote de producto

        int codigoMarcaProducto= producto[indiceDelProducto].codDeMarca; ///cod de la marca del lote de producto

        ///busco el indice de codigo de marca del lote de marca (para acumular la cant vendida) comparandolo con cod de la marca del lote de producto
        int indiceMarca=-1;
        for(int i=0; i<10; i++){
            if(marca[i].codMarca==codigoMarcaProducto){
                indiceMarca=i;
                break;
            }
        }

        cantTotalVendProdPorMarcaYPorFP[indiceMarca][indiceDeFormaDePago]+=cantVendida;

        ///PUNTO 5 - Calcular el top 10 de clientes con más compras realizadas (por cantidad de compras).

        cantidadDeComprasPorCliente[codClienteV]++; ///SEGUN COD CLIENTE (1-50) ACUMULO LA CANT COMPRAS TIENE


        cout<<"Ingresa el Numero de Compra: "<<endl;
        cin>>nroCompra;
    }


    return;
    }

