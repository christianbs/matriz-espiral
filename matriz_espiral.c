#include <stdlib.h>
#include <stdio.h>

int main() {

	int linhas;
	int colunas;

	printf("Digite a quantidade de linhas: ");
	scanf("%d", &linhas);
	printf("\n");
	
	printf("Digite a quantidade de colunas: ");
	scanf("%d", &colunas);
	printf("\n");
	
	printf("Matriz %d x %d\n", linhas, colunas);
	
	int matriz[linhas][colunas];
	
	int linha_inicial = 0;
	int coluna_inicial = 0;
	int contador = 1;
	int fase = 1;
	int x = 1;
	int y = 0;

	while(contador < (linhas * colunas)) {	
		switch (fase) {
			case 1:
				for (coluna_inicial = coluna_inicial; coluna_inicial < colunas - x; coluna_inicial++) {
					matriz[linha_inicial][coluna_inicial] = contador;
					contador++;
				}
				fase = 2;
				break;
			case 2:
				for (linha_inicial = linha_inicial; linha_inicial < linhas - x; linha_inicial++) {
					matriz[linha_inicial][coluna_inicial] = contador;
					contador++;
				}
				fase = 3;
				break;
			case 3:
				for (coluna_inicial = coluna_inicial; coluna_inicial > y; coluna_inicial--) {
					matriz[linha_inicial][coluna_inicial] = contador;
					contador++;
				}
				fase = 4;
				break;
			case 4:
				for (linha_inicial = linha_inicial; linha_inicial > y; linha_inicial--) {
					matriz[linha_inicial][coluna_inicial] = contador;
					contador++;
				}
				fase = 1;
				x++;
				y++;
				linha_inicial++;
				coluna_inicial++;
				break;
		}
	}
	matriz[linha_inicial][coluna_inicial] = contador;

	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			if (matriz[i][j] < 10) {
				printf("0%d", matriz[i][j]);
				printf("|");
			} else {
				printf("%d", matriz[i][j]);
				printf("|");
			}
		}
		printf("\n");
	}
	return 0;
}