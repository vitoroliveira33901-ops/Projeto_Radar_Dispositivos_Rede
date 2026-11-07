#include <stdio.h>

int main() {
    int n, i;
    int estado[10]; // Correção: mantido o vetor original para armazenar os estados
    int ativos = 0;
    int inativos = 0;
    float porcentagem;

    printf("RADAR DE DISPOSITIVOS DA REDE\n");

    printf("Quantos dispositivos deseja verificar (1 a 10)? ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Quantidade invalida!\n");
    } else {

        for (i = 0; i < n; i++) {
            // Repete a pergunta ate que o usuario digite 0 ou 1
            do {
                printf("Dispositivo %d (1 = ativo / 0 = inativo): ", i + 1);
                scanf("%d", &estado[i]);
                
                if (estado[i] != 0 && estado[i] != 1) {
                    printf("Opcao invalida! Digite apenas 0 ou 1.\n");
                }
            } while (estado[i] != 0 && estado[i] != 1);

            if (estado[i] == 1) {
                ativos++;
            } else {
                inativos++;
            }
        }

        // Nova logica usando a alternativa comum (multiplicar por 100.0 primeiro)
        porcentagem = (ativos * 100.0) / n;

        printf("\n--- RESULTADO DO RADAR ---\n");
        printf("Dispositivos ativos: %d\n", ativos);
        printf("Dispositivos inativos: %d\n", inativos);
        printf("Porcentagem de ativos: %.1f%%\n", porcentagem);

        if (inativos >= 2) {
            printf("ALERTA: Dois ou mais dispositivos estao inativos!\n");
        } else {
            printf("Situacao normal: menos de dois dispositivos inativos.\n");
        }
    }

    return 0;
}

