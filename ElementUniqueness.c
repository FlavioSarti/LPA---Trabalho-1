#include <stdio.h>
void gerador_de_vetor(int tamanho, int vet[]){
	//Essa fun��o monta o vetor a partir do teclado do usu�rio
	int i = 0;
	int aux;
		printf("\n** Digite o seu vetor:\n");
		while((i < tamanho) && (scanf("%d", &aux) > 0)) {
    		vet[i] = aux;
    		i++;
  		}
}
void insertion(int tamanho, int vet[]){
	//Essa fun��o ordena o vetor de forma crescente
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
int repete_ou_nao(int tamanho, int vet[]){
	//Essa fun��o imprime os algarismos com ocorr�ncia �nica
	int count=0; int i=0;					//a vari�vel count simboliza quantos n�meros tem ocorr�ncia �nica
	if(tamanho==1 || tamanho==2){           //condi��o para a entrada de vetores unit�rios ou bin�rios
		if (tamanho==1){
			printf("->%d",vet[0]);	
			count++; 
		}
		else{
			if(vet[0]!=vet[1]){
				printf("->%d->%d",vet[0],vet[1]);
				count = count+2;
			}
		}
				
	}
	else{		
		while(i<tamanho){
			if(i==0 || i==tamanho-1){                //essa etapa serve para o primeiro e ultimo elemento:
				if(vet[i]!=vet[i+1] || vet[tamanho-1] != vet[tamanho-2]){
					printf("->%d",vet[i]);  		
					count++;
				}
			i++;
			}
			else{								//essa etapa serve para os demais:
				if(vet[i+1]!=vet[i]){			//primeiro verifica o numero a direita, para otimizar o processo
					if(vet[i-1]!=vet[i]){
						printf("->%d",vet[i]);
						count++;
					}
					i++; 						//pula-se um elemento se o da esquerda for igual
				}
				else{
					i=i+2;                      //OTIMIZA��O: pula-se dois elementos se o da direita for igual
				}
			}
		}
	}
return count;

}
int main(){
	int i=0; int contador = 0; int tamanho;
	printf("** Digite o tamanho do vetor:\n\n");
	scanf("%d",&tamanho);
	if(tamanho!=0){                        //Condi�ao para um vetor n�o nulo
		int vet[tamanho];
		gerador_de_vetor(tamanho,vet);
		insertion(tamanho, vet);
		contador = repete_ou_nao(tamanho, vet);
		if (contador>0){
			printf("  (n\243meros que n\706o se repetem no vetor)\n\n** Num de ocorr\210ncias: %d",contador);
		}
		else{
			printf("\n** Todos os n\243meros repetem, ao menos, uma vez.");
		}
	}	
getch();
}
