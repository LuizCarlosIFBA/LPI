#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>
void desvioPadrao(float *pMedFinal,int m, float *pMedia, float *pDPadrao){
	float soma = 0;
        float termo = 0;
	float *pSoma = &soma;
	float *pTermo = &termo;

        int i;
	for(i=0;i<m;i++){
		*pSoma += pMedFinal[i];
		
	}
	*pMedia = *pSoma/m;
       
        *pSoma = 0;
        *pTermo = 0;
 	for(i=0;i<m;i++){
		*pTermo = pMedFinal[i]-(*pMedia);
		*pSoma += pow(*pTermo,2);
	}
      
        //não é a coisa mais aconselhável a fazer, porém está ok 
	//na variável diz somo, mas não foi somente essa operação 
        //realizada, mesmo assim o cálculo está certo. 
	*pDPadrao = *pSoma/(m-1);
        	
        printf("A média aritmética é: %.1f \n",*pMedia);
	printf("O desvio padrão é: %.1f \n",sqrt(*pDPadrao));
}

void main(){
        int m = 2;         
        int aux = 0; 
	float Media = 0;
	float DPadrao = 0;
		
	//ponteiro para variáveis 
	float *pMedia = &Media;
	float *pDPadrao = &DPadrao;
	// -----------------------
	
	float MedFinal[m];
	
	//ponteiro vetor
	float *pMedFinal = MedFinal;
	//------------------------

	srand((unsigned)time(NULL));
	for(int i=0;i<m;i++){
   		aux = 0+ 10.0*((float)(rand())/RAND_MAX);
                pMedFinal[i] = aux;
                //printf("%d º média final %.1f\n",i+1,MedFinal[i]);
   		if(i % 10 == 0){
      			printf("\n");
        	} 	
         
   		
	}
  
	desvioPadrao(pMedFinal,m,pMedia,pDPadrao);
}

// gcc -o main main.c -lm

