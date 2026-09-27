#include <stdio.h>
#include <time.h>
#include <string.h>


typedef struct {
    char regiao[15];
    struct tm data_compra;
    struct tm data_entrega;
    int dias_prazo;
} Pedido;


int obter_prazo_dias(const char *regiao) {
    if (strcasecmp(regiao, "Sul") == 0) return 3;
    if (strcasecmp(regiao, "Sudeste") == 0) return 2;
    if (strcasecmp(regiao, "Norte") == 0) return 7;
    if (strcasecmp(regiao, "Nordeste") == 0) return 5;
    return -1; 
}


struct tm calcular_data_entrega(struct tm data_inicial, int dias_uteis) {
    time_t tempo_epoch = mktime(&data_inicial);
    int dias_adicionados = 0;

    while (dias_adicionados < dias_uteis) {
       
        tempo_epoch += 86400;
        
        
        struct tm *data_temp = localtime(&tempo_epoch);

        
        if (data_temp->tm_wday != 0 && data_temp->tm_wday != 6) {
            dias_adicionados++;
        }
    }

    return *localtime(&tempo_epoch);
}

int main() {
    Pedido pedido;

   
    time_t agora = time(NULL);
    pedido.data_compra = *localtime(&agora);

    printf("========================================\n");
    printf("     SISTEMA DE ENTREGAS - E-COMMERCE   \n");
    printf("========================================\n");

   
    char buffer_compra[100];
    strftime(buffer_compra, sizeof(buffer_compra), "%d/%m/%Y às %H:%M:%S", &pedido.data_compra);
    printf("Data e hora da compra: %s\n\n", buffer_compra);

    
    printf("Informe a regiao de entrega (Sul, Sudeste, Norte, Nordeste): ");
    scanf("%14s", pedido.regiao);

    pedido.dias_prazo = obter_prazo_dias(pedido.regiao);

    if (pedido.dias_prazo == -1) {
        printf("\nErro: Regiao '%s' invalida ou nao atendida.\n", pedido.regiao);
        return 1;
    }

    
    pedido.data_entrega = calcular_data_entrega(pedido.data_compra, pedido.dias_prazo);

    
    char buffer_entrega[100];
    strftime(buffer_entrega, sizeof(buffer_entrega), "%d/%m/%Y ate as %H:%M:%S", &pedido.data_entrega);

    printf("\n----------------------------------------\n");
    printf("RESUMO DO PRAZO DE ENTREGA:\n");
    printf("Regiao solicitada : %s\n", pedido.regiao);
    printf("Prazo estimado    : %d dias uteis\n", pedido.dias_prazo);
    printf("Entrega prevista  : %s\n", buffer_entrega);
    printf("----------------------------------------\n");

    return 0;
}