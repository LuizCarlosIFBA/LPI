#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>
void desvioPadrao(float *MedFinal,int m, float Media, float DPadrao){
	float soma = 0;
        float termo;
        int i;
	for(i=0;i<m;i++){
		soma += MedFinal[i];
		
	}
	Media = soma/m;
       
        soma = 0;
        termo = 0;
 	for(i=0;i<m;i++){
		termo = MedFinal[i]-Media;
		soma += pow(termo,2);
	}
      
        //não é a coisa mais aconselhável a fazer, porém está ok 
	//na variável diz somo, mas não foi somente essa operação 
        //realizada, mesmo assim o cálculo está certo. 
	DPadrao = soma/(m-1);
        	
        printf("A média aritmética é: %.1f \n",Media);
	printf("O desvio padrão é: %.1f \n",sqrt(DPadrao));
}

void main(){
        int m = 2;         
          
        float Media;
	float MedFinal[m];
	float DPadrao;

	int i, aux; 
	srand((unsigned)time(NULL));
	for(i=0;i<m;i++){
   		aux = 0+ 10.0*((float)(rand())/RAND_MAX);
                MedFinal[i] = aux;
                //printf("%d º média final %.1f\n",i+1,MedFinal[i]);
   		if(i % 10 == 0){
      			printf("\n");
        	} 	
         
   		
	}
  
	desvioPadrao(MedFinal,m,Media,DPadrao);
}

// gcc -o main main.c -lm

