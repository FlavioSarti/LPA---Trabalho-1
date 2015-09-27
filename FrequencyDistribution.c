#include <stdio.h>
void gerador_de_vetor(int tamanho, int vet[]){
//essa função permite a entrada de números pelo usuário
	int i = 0;
	int aux;
		printf("\n** Digite os elementos do vetor: \n\n");
		while((i < tamanho) && (scanf("%d", &aux) > 0)) {
    		vet[i] = aux;
    		i++;
  		}
 }
void insertion(int tamanho, int vet[]){
	//essa função ordena o vetor entrado pelo usuário
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
int frequencimetro(int tamanho, int vet[]){
	//percorre o vetor contando a ocorrência de cada elemento. Se esse elemento tiver o maior número
	//de repetição, armazena-o
	int cont=0, maior_freq=0, i=0, j=0;
	while(i<tamanho){
		for(j=i;j<tamanho;j++){
			if(vet[j]==vet[i]){
				cont++;
				if(cont>maior_freq){ //se for maior, armazena
					maior_freq=cont;
				}
			}
			else{ 				//se encontrar um num diferente, para-se o loop e zera o contador
				cont=0; 
				i=j-1;
				break;
			}
		}
		i++;
	}
	return maior_freq;
}
void percorre_vetor(int tamanho, int vet[], int num_ocor){
	//Essa função tem o mesmo código do frequencimetro, mas imprime os números cuja ocorrência é a mesma
	//da maior obtida na função anterior.
	int cont=0, maior_freq=0, i=0, j=0;
	printf("\n** Elementos com maior ocorr%cncia:",136);
	while(i<tamanho){
		for(j=i;j<tamanho;j++){
			if(vet[j]==vet[i]){
				cont++;
				if(cont>maior_freq){
					maior_freq=cont;
				}
				if(cont==num_ocor){
					printf("\n->%d",vet[j]);
				}
			}
			else{
				cont=0;
				i=j-1;
				break;
			}
		}
		i++;
	}
}
void main(){
	int tamanho, result;
	printf("** Digite o tamanho do vetor: \n\n");
	scanf("%d",&tamanho);
	int vet[tamanho];
		//Chamada das funções
		gerador_de_vetor(tamanho,vet);
		insertion(tamanho,vet);
		percorre_vetor(tamanho, vet, frequencimetro(tamanho,vet));
}
