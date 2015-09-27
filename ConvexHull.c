#include <stdio.h>
#include <stdlib.h>

// Tipo Ponto 2D (X, Y)
typedef struct {
	int x;
	int y;
} ponto;


// Produto vetorial entre OA e AB
// Resultados positivos significam que o �ngulo entre vetores gira no sentido hor�rio
int produtoVetorial (ponto o, ponto a, ponto b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}


int comparaPontos (const void *a, const void *b) {
	// transforma ponteiros void pra ponteiros ponto
	ponto *pa = (ponto *) a;
	ponto *pb = (ponto *) b;
	// diferen�a de coordenadas
	int dx = pa->x - pb->x;
	int dy = pa->y - pb->y;

	// X tem prefer�ncia
	if (dx != 0) {
		return dx;
	}
	// mas se dX for 0, ordena em rela��o a Y
	else {
		return dy;
	}
}


int main () {
	// l� o n�mero de pontos
	int n;
	printf("** Digite a quantidade de coordenadas:\n");
	scanf ("%d", &n);

	// vetor de n pontos
	ponto todosPontos[n];

	// l� os pontos
	int i;
	printf("\n** Digite as coordenadas:\n");
	for (i = 0; i < n; i++) {
		scanf ("%d %d", &todosPontos[i].x, &todosPontos[i].y);
	}

	/* Algor�timo de Cadeia Mon�tona pra achar Convex Hulls */
	// para que o algor�timo funcione, precisamos que os pontos
	// estejam ordenados por X e por Y (nessa ordem)
	qsort (todosPontos, n, sizeof (ponto), comparaPontos);

	// lista de pontos abaixo
	ponto abaixo[n];
	int pontosAbaixo = 0;
	for (i = 0; i < n; i++) {
		while (pontosAbaixo >= 2 && produtoVetorial (abaixo[pontosAbaixo - 2],
				abaixo[pontosAbaixo - 1], todosPontos[i]) >= 0) {
			pontosAbaixo--;
		}
		abaixo[pontosAbaixo] = todosPontos[i];
		pontosAbaixo++;
	}

	// lista de pontos acima
	ponto acima[n];
	int pontosAcima = 0;
	for (i = n - 1; i >= 0; i--) {
		while (pontosAcima >= 2 && produtoVetorial (acima[pontosAcima - 2],
				acima[pontosAcima - 1], todosPontos[i]) >= 0) {
					pontosAcima--;
				}
		acima[pontosAcima] = todosPontos[i];
		pontosAcima++;
	}

	// imprime pontos abaixo, ignorando o �ltimo (que � o primeiro dos acima)
	printf("\n** Imprimindo os pontos:\n");
	for (i = 0; i < pontosAbaixo - 1; i++) {
		printf ("(%d,%d)\n", abaixo[i].x, abaixo[i].y);
	}
	// imprime pontos acima, ignorando o �ltimo (que � o primeiro dos abaixo)
	for (i = 0; i < pontosAcima - 1; i++) {
		printf ("(%d,%d)\n", acima[i].x, acima[i].y);
	}

	return 0;
	system("PAUSE");
}
