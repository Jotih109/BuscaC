#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int elemento){
	int esquerda = 0;
	int direita = tamanho - 1;
	
	while (esquerda <= direita){
		int meio = esquerda + (direita - esquerda) / 2;
		
		if (arr[meio] == elemento) {
            return meio;
        }
        else if (arr[meio] > elemento) {
            direita = meio - 1;
        }
        else {
            esquerda = meio + 1;
        }
	}
	return - 1;
}

	int main(){
		int meuArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
		int tamanhoDoArray = sizeof(meuArray) / sizeof(meuArray[0]);
		
		int elementoProcurado = 13;
		
		int resultado = buscaBinaria(meuArray, tamanhoDoArray, elementoProcurado);
		
		if(resultado == -1){
			printf("O elemento %d nao foi encontrado na busca...", elementoProcurado);
		}
		
		else{
			printf("O elemento %d foi encontrado na busca...", elementoProcurado);
		}
	}