#include <stdio.h>  // Para operações de I/O (Input/Output), como printf e FILE
#include <stdlib.h> // Para a função exit()

// 1. Definição da Estrutura (Struct)
// Isso define o "molde" para um Ticket.
struct Ticket {
    char nome[100]; // Um campo para armazenar o nome (string com até 100 caracteres)
    int numero;     // Um campo para armazenar o número do ticket (inteiro)
};

int main() {

    // 2. Criação dos Vários Tickets
    // Vamos criar um array de 3 tickets para este exemplo.
    struct Ticket tickets[] = {
        {"Ana Silva", 1045},
        {"Bruno Costa", 1046},
        {"Carla Dias", 1047}
    };

    // Calcula quantos tickets temos no array
    // sizeof(tickets) -> tamanho total do array em bytes
    // sizeof(tickets[0]) -> tamanho do primeiro elemento (um struct Ticket) em bytes
    int numTickets = sizeof(tickets) / sizeof(tickets[0]);

    printf("Iniciando a geracao de %d arquivos de ticket...\n\n", numTickets);

    // 3. Loop para salvar cada ticket em um arquivo
    for (int i = 0; i < numTickets; i++) {

        // Variável para guardar o nome do arquivo (ex: "ticket1.txt")
        char nomeArquivo[20];

        // Cria o nome do arquivo dinamicamente.
        // O 'i + 1' é para começar em "ticket1.txt" (já que 'i' começa em 0)
        sprintf(nomeArquivo, "ticket%d.txt", i + 1);

        // Abre o arquivo no modo "w" (write/escrita).
        // Se o arquivo não existir, ele será criado.
        // Se já existir, será sobrescrito.
        FILE *arquivo = fopen(nomeArquivo, "w");

        // Verificação de segurança: checa se o arquivo foi aberto com sucesso
        if (arquivo == NULL) {
            printf("Erro: Nao foi possivel criar o arquivo %s!\n", nomeArquivo);
            // Pula para a próxima iteração do loop
            continue;
        }

        // Escreve os dados formatados dentro do arquivo
        fprintf(arquivo, "--- TICKET GERADO ---\n");
        fprintf(arquivo, "Numero do Ticket: %d\n", tickets[i].numero);
        fprintf(arquivo, "Nome do Cliente: %s\n", tickets[i].nome);
        fprintf(arquivo, "---------------------\n");

        // Fecha o arquivo para salvar as alterações
        fclose(arquivo);

        printf("Arquivo %s criado com sucesso para o ticket %d.\n", nomeArquivo, tickets[i].numero);
    }

    printf("\nProcesso concluido!\n");

    return 0; // Indica que o programa terminou com sucesso.
}
