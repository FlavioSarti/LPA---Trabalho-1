#include <stdio.h>
void gerador_de_vetor(int tamanho, int vet[]){
	//Essa função monta o vetor a partir do teclado do usuário
	int i = 0;
	int aux;
		printf("\n** Digite o seu vetor:\n\n");
		while((i < tamanho) && (scanf("%d", &aux) > 0)) {
    		vet[i] = aux;
    		i++;
  		}
}
void insertion(int tamanho, int vet[]){
	//Essa função ordena o vetor de forma crescente
	int i, j, aux;
   	for (i = 1; i < tamanho; i++){
      	aux = vet[i]; 
      	j = i - 1;
      	while ((j>=0) && (aux < vet[j])) { 
        	 vet[j+1] = vet[j];
         	j--;
      	  }
      	vet[j+1] = aux; 
   	   }	
}
void diferenciador(int tamanho, int vet[]){
	//Essa função procura a menor diferença e imprime quais pares correspondem à essa diferença
	int i, menor_dif=vet[1]-vet[0];
	for(i=2;i<tamanho;i++){   //Esse loop procura a menor diferença e armazena em menor_dif
		if (vet[i]-vet[i-1]<menor_dif){
			menor_dif = vet[i]-vet[i-1];
		}
	}
	for(i=1;i<tamanho;i++){    //Esse loop procura e imprime os pares cuja diferença é igual à menor_dif
		if(vet[i]-vet[i-1]==menor_dif){
			printf("\n(%d,%d)",vet[i-1],vet[i]);
		}
	}
}
void main(){
	int tamanho;
	printf("** Digite o tamanho:\n\n");
	scanf("%d",&tamanho);
	int vet[tamanho];
		if (tamanho>1)
		{   //chamada das funções
			gerador_de_vetor(tamanho, vet);
			insertion(tamanho, vet);
			printf("\n** Pares mais pr%cximos:\n",162);
			diferenciador(tamanho,vet);
		}
		else{
			printf("\n\n** Entre um vetor v%clido",160);
		}
}
