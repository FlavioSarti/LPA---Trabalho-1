#include <stdio.h>
void gerador_de_vetor(int tamanho, int vet[]){
	//Essa função monta o vetor a partir do teclado do usuário
	int i = 0;
	int aux;
		printf("\n** Digite o seu vetor:\n");
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
int repete_ou_nao(int tamanho, int vet[]){
	//Essa função imprime os algarismos com ocorrência única
	int count=0; int i=0;					//a variável count simboliza quantos números tem ocorrência única
	if(tamanho==1 || tamanho==2){           //condição para a entrada de vetores unitários ou binários
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
					i=i+2;                      //OTIMIZAÇÃO: pula-se dois elementos se o da direita for igual
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
	if(tamanho!=0){                        //Condiçao para um vetor não nulo
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
