/*
  ISWZ1102 - Programacion I
  Ejercicio: gestion de venta de un producto
  Autor: Nombre Apellido
*/
#include <stdio.h>

int main() {
    /* Datos del producto */
    int id = 0;
    char nombre[30];
    int stock = 0;
    float precio = 0;

    /* Datos de las ventas */
    float ganancias = 0;
    int vendidas = 0;
    int registrado = 0;      /* 0 = no hay producto, 1 = ya se registro */

    /* Variables auxiliares */
    int opcion = 0;
    int cantidad = 0;
    int descuento = 0;
    float precioFinal = 0;
    float totalVenta = 0;

    do {
        printf("\n=================================\n");
        printf("\tMENU PRINCIPAL\n");
        printf("=================================\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer stock\n");
        printf("4. Consultar producto\n");
        printf("5. Ver ganancias\n");
        printf("6. Salir\n");
        printf("Elija una opcion: ");

        opcion = 0;
        scanf("%d", &opcion);
        while (getchar() != '\n');   /* borra lo que sobre (por ejemplo, letras) */

        switch (opcion) {
        case 1: /* ----- Registrar ----- */
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
            while (getchar() != '\n');

            printf("Stock inicial: ");
            stock = -1;
            scanf("%d", &stock);
            while (getchar() != '\n');
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

        case 2: /* ----- Vender ----- */
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
            if (descuento < 0 || descuento > 100) {
                printf("Error: el descuento debe estar entre 0 y 100.\n");
                break;
            }

            precioFinal = precio - precio * descuento / 100;
            totalVenta = precioFinal * cantidad;

            /* solo se actualiza si la venta es valida */
            stock = stock - cantidad;
            vendidas = vendidas + cantidad;
            ganancias = ganancias + totalVenta;

            printf("\nVenta realizada\n");
            printf("\tPrecio final:\t$%.2f\n", precioFinal);
            printf("\tTotal venta:\t$%.2f\n", totalVenta);
            printf("\tStock actual:\t%d\n", stock);
            break;

        case 3: /* ----- Reabastecer ----- */
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

        case 4: /* ----- Consultar ----- */
            if (registrado == 0) {
                printf("\nPrimero registre el producto.\n");
                break;
            }
            printf("\n--- Datos del producto ---\n");
            printf("\tID:\t%d\n", id);
            printf("\tNombre:\t%s\n", nombre);
            printf("\tStock:\t%d\n", stock);
            printf("\tPrecio:\t$%.2f\n", precio);
            break;

        case 5: /* ----- Ganancias ----- */
            printf("\n--- Ganancias ---\n");
            printf("\tUnidades vendidas:\t%d\n", vendidas);
            printf("\tGanancias totales:\t$%.2f\n", ganancias);
            break;

        case 6: /* ----- Salir ----- */
            printf("\nGracias por usar el programa.\n");
            break;

        default:
            printf("\nOpcion invalida. Elija un numero del 1 al 6.\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}
