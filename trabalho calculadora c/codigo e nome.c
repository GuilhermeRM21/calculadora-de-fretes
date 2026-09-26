#include <stdio.h>

int main() {
    char codigoLimao[] = "111";
    char codigoMaca[] = "112";
    char codigoLaranja[] = "113";
    char codigoMelao[] = "114";

    char nomeLimao[] = "Limao";
    char nomeMaca[] = "Maca";
    char nomeLaranja[] = "Laranja";
    char nomeMelao[] = "Melao";

    float pesoLimao = 0.10;
    float pesoMaca = 0.20;
    float pesoLaranja = 0.25;
    float pesoMelao = 1.50;

    float precoLimao = 1.50;
    float precoMaca = 3.00;
    float precoLaranja = 2.50;
    float precoMelao = 9.50;

    printf("Codigo: %s - Produto: %s - Peso: %.2f kg - Preco: R$ %.2f\n", codigoLimao, nomeLimao, pesoLimao, precoLimao);
    printf("Codigo: %s - Produto: %s - Peso: %.2f kg - Preco: R$ %.2f\n", codigoMaca, nomeMaca, pesoMaca, precoMaca);
    printf("Codigo: %s - Produto: %s - Peso: %.2f kg - Preco: R$ %.2f\n", codigoLaranja, nomeLaranja, pesoLaranja, precoLaranja);
    printf("Codigo: %s - Produto: %s - Peso: %.2f kg - Preco: R$ %.2f\n", codigoMelao, nomeMelao, pesoMelao, precoMelao);

    return 0;
}
