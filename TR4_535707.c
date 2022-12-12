#include "ordvetor.h"
//cria a struct com todos os parametros para o vetor ordenado
VETORORD* VETORD_create(int n, COMP* compara) {
	//Pega um tamanho para o vetor
	VETORORD* vetor = malloc(sizeof(VETORORD));
	//Tamanho maximo 
	vetor->N = n;
	//Tamanho atual
	vetor->P = 0;
	//Pega um tamanho para os elementos
	vetor->elems = malloc(n * sizeof(void*));
	//Função que compara dois elementos
	vetor->comparador = compara;
	return vetor;
}
//Função que adiciona elementos de forma ordenada
void VETORD_add(VETORORD* vetor, void* newelem) {
	//Cofere se a posição atual é menor que o tamanho maiximo
	if (vetor->P < vetor->N) {
		int posicao = vetor->P;
	
		for (int i = 0; i < vetor->P; i++) {
			if (vetor->comparador(vetor->elems[i], newelem) == -1) {
				posicao = i;
				break;
			}
		}

		for (int i = vetor->P; i > posicao; i--) {
			vetor->elems[i] = vetor->elems[i - 1];
		}
		vetor->elems[posicao] = newelem;
		vetor->P++;
	}	
}
// Função de remover do vetor ordenado
void* VETORD_remove(VETORORD* vetor) {
	void* menor = vetor->elems[0];

	for (int i = 0; i < vetor->P - 1; i++) {
		vetor->elems[i] = vetor->elems[i + 1];
	}
	
	vetor->P--;

	return menor;
}
