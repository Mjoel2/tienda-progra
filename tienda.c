// trabajo de Mateo Acero :)
#include <stdio.h>
// dentro de int main declaro todo
// Todo bien ordenado e iterado, para que el codigo este bello. 
int main() {
    //Datos del producto 
    int id = 0;
    char nombre[30];
    int stock = 0;
    float precio = 0;

    //Datos de las ventas 
    float ganancias = 0;
    int vendidas = 0;
    int registrado = 0;    

    //Variablesssss
    int opcion = 0;
    int cantidad = 0;
    int descuento = 0;
    float precioFinal = 0;
    float totalVenta = 0;
// En do-while, para que el usuario se quede dentro, hasta que elija la opcion de SALIR obvio
    do {
        printf("\n=================================\n");
        printf("\tMENU PRINCIPAaL\n");
        printf("=================================\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Consultar producto\n");
        printf("5. Ver ganancias\n");
        printf("6. Salir\n");
        printf("Elija una opcin: ");

        opcion = 0;
        scanf("%d", &opcion);
        while (getchar() != '\n');  
        // ocupo switch para empezar el menu y poner las opciones
        switch (opcion) {
        case 1: 
            if (registrado == 1) {
                printf("\nYa hay un producto registrado.\n");
                break;
            }
            printf("\nID: ");
            id = 0;
            scanf("%d", &id);
            while (getchar() != '\n');
            if (id <= 0) {
                printf("Error: el ID debe ser un numero mayor que 0.\n");
                break;
            }

            printf("Nombre (una palabra): ");
            scanf("%29s", nombre);
            while (getchar() != '\n'); //Aqui se limpia el buffer de entrada para evitar problemas con fgets, porque se ponia medio mal

            printf("Stock inicial: ");
            stock = -1;
            scanf("%d", &stock);
            while (getchar() != '\n'); // SIempre limpiar el buffer de entrada por si acasooo
            if (stock < 0) {
                printf("Error: el stock debe ser 0 o mayor.\n");
                break;
            }

            printf("Precio unitario: ");
            precio = 0;
            scanf("%f", &precio);
            while (getchar() != '\n');
            if (precio <= 0) {
                printf("Error: el precio debe ser mayor que 0.\n");
                break;
            }

            registrado = 1;
            printf("\nProducto registrado correctamente.\n");
            break;

        case 2: //venta 
            if (registrado == 0) {
                printf("\nPrimero registre el producto.\n");
                break;
            }
            printf("\nStock disponible: %d\n", stock);
            printf("Cantidad a vender: ");
            cantidad = 0;
            scanf("%d", &cantidad);
            while (getchar() != '\n');

            if (cantidad <= 0) {
                printf("Error: la cantidad debe ser mayor que 0.\n");
                break;
            }
            if (cantidad > stock) {
                printf("Error: no hay stock suficiente.\n");
                break;
            }

            printf("Descuento en porcentaje (0 a 100): ");
            descuento = -1;
            scanf("%d", &descuento);
            while (getchar() != '\n');
            if (descuento < 0 || descuento > 100) { //veo que el descuento este entre 0 y 100
                printf("Error: el descuento debe estar entre 0 y 100.\n");
                break;
            }
                //calculo de precios finales y para actualizar el stock, por ejemplo si vendo 5, se restan 5
            precioFinal = precio - precio * descuento / 100;
            totalVenta = precioFinal * cantidad;
            stock = stock - cantidad;
            vendidas = vendidas + cantidad;
            ganancias = ganancias + totalVenta;

            printf("\nVenta realizada\n");
            printf("\tPrecio final:\t$%.2f\n", precioFinal);
            printf("\tTotal venta:\t$%.2f\n", totalVenta);
            printf("\tStock actual:\t%d\n", stock);
            break;

        case 3: //reabastecimiento
            if (registrado == 0) {
                printf("\nPrimero registre el producto.\n");
                break;
            } 
            printf("\nCantidad a agregar: ");
            cantidad = 0;
            scanf("%d", &cantidad);
            while (getchar() != '\n');
            if (cantidad <= 0) {
                printf("Error: la cantidad debe ser mayor que 0.\n");
                break;
            }
            stock = stock + cantidad;
            printf("Stock actualizado: %d\n", stock);
            break;

        case 4: //consultar
            if (registrado == 0) {
                printf("\nPrimero registre el producto.\n");
                break;
            }
            printf("\n=== Datos del producto ===\n");
            printf("\tID:\t%d\n", id);
            printf("\tNombre:\t%s\n", nombre);
            printf("\tStock:\t%d\n", stock);
            printf("\tPrecio:\t$%.2f\n", precio);
            break;

        case 5: //ganancias 
            printf("\n--- Ganancias ---\n");
            printf("\tUnidades vendidas:\t%d\n", vendidas);
            printf("\tGanancias totales:\t$%.2f\n", ganancias);
            break;

        case 6: //salimos del programa
            printf("\nGracias por usar el programa.\n");
            break;

        default: //opcion invalida, porque el usuario siempre puede equivocarse 
            printf("\nOpcion invalida. Elija un numero del 1 al 6.\n");
            break;
        } // fin del switch
    } while (opcion != 6); // fin del do-while

    return 0;
}
