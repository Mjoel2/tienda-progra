# Gestión de venta de un producto en C

Ejercicio de programación — **ISWZ1102 Programación I** (UDLA).

Programa de consola que permite a un pequeño comerciante administrar un único producto.

## Funcionalidades

1. **Registrar producto:** ID, nombre, stock y precio unitario.
2. **Vender:** verifica que haya stock suficiente y permite aplicar un descuento (0–100 %) en cada venta.
3. **Reabastecer:** agrega unidades al stock.
4. **Consultar** la información actualizada del producto.
5. **Ver ganancias** acumuladas y unidades vendidas.
6. **Salir.**

Las entradas se validan con `if`: el programa rechaza números negativos, letras y valores fuera de rango.

## Compilar y ejecutar

```bash
gcc -o tienda tienda.c
./tienda          # en Windows: tienda.exe
```

## Archivos

| Archivo | Descripción |
|---|---|
| `tienda.c` | Código fuente del programa |
| `capturas/` | Capturas de los escenarios de prueba |

## Autor

Mateo Acero
