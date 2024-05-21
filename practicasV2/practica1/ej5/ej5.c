#include <stdio.h>

void total(float weight, float pricePerKg, int *amount);

int main() {
    float weight, pricePerKg;
    int amount;

    printf("Ingrese:\n\tPeso del producto en Kg: ");
    scanf("%f", &weight);

    printf("\n\tPrecio por Kg del mismo: ");
    scanf("%f", &pricePerKg);

    total(weight, pricePerKg, &amount);
    printf("El importe final es de $%d\n", amount);

    return 0;
}

void total(float weight, float pricePerKg, int *amount) {
    *amount = weight * pricePerKg;
    if(*amount > 100){
        *amount = *amount - (*amount * 0.10);
    }
}