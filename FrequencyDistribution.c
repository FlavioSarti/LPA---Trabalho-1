#include <stdio.h>
void gerador_de_vetor(int tamanho, int vet[]){
//essa fun��o permite a entrada de n�meros pelo usu�rio
	int i = 0;
	int aux;
		printf("\n** Digite os elementos do vetor: \n\n");
		while((i < tamanho) && (scanf("%d", &aux) > 0)) {
    		vet[i] = aux;
    		i++;
  		}
 }
void insertion(int tamanho, int vet[]){
	//essa fun��o ordena o vetor entrado pelo usu�rio
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
	//percorre o vetor contando a ocorr�ncia de cada elemento. Se esse elemento tiver o maior n�mero
	//de repeti��o, armazena-o
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
	//Essa fun��o tem o mesmo c�digo do frequencimetro, mas imprime os n�meros cuja ocorr�ncia � a mesma
	//da maior obtida na fun��o anterior.
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
		//Chamada das fun��es
		gerador_de_vetor(tamanho,vet);
		insertion(tamanho,vet);
		percorre_vetor(tamanho, vet, frequencimetro(tamanho,vet));
}
