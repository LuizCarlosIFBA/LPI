#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>

struct nome{
	char nome[4];
};	
	  
void AlunoDestaque(int *n, int *m, struct nome *nomes, float **nota,float *mediaFinal,int *peso){
	//Preenchendo o vetor peso 
	int i,j; 
	srand((unsigned)time(NULL));
	for(i=0;i<*n;i++){
   		peso[i] = rand()%11;
   		if(i % 10 == 0){
      			//printf("\n");
        	} 	
         
   	}
   
       //----------------------------------------------------------------------//
  
        //Preenchendo a matriz nota

        float aux = 0;    
	srand(time(NULL));
	for(j=0;j<*m;j++){ 
 		for(i=0;i<*n;i++){
   			aux = 0+ 10.0*((float)(rand())/RAND_MAX);
                        nota[j][i] = aux;
                        if(i % 10 == 0){
      				//printf("\n");
        		} 	
		}    
        }

       //----------------------------------------------------------------------//
      
       //Cálculo da média
       aux=0;
       
       for(j=0;j<*m;j++){ 
 		for(i=0;i<*n;i++){
   			aux+=nota[j][i]; 
		}
    
        mediaFinal[j] = aux/10; 
      }

     //-----------------------------------------------------------------------//
     //lógica para aluno destaque
     
     for(int i=0;i<*m;i++){ 
 	 for(int j=0;j<*m;j++){
   	 	aux = 0;
		if(mediaFinal[i]<mediaFinal[j]){
			aux = mediaFinal[j];
                        mediaFinal[j] = mediaFinal[i];
			mediaFinal[i] = aux;
		}		
	 }    
     }

     int destaque = 0;
     for(int i=0;i<*m;i++){ 
 	 for(int j=0;j<*m;j++){
		if(nota[i][j]>=5 && mediaFinal[i]>7){
			if(i==0){
			    printf("O aluno destaque é %s",nomes[0].nome[4]);
			    destaque++;
                        }else if(i==1){printf("O aluno destaque é %s",nomes[0].nome[4]); destaque++;}	
		}
         }
     }
     printf(destaque == 0?"Turma não tem aluno Destaque\n":" ");		 
}

void main(){
        int m = 2;
 	int n = 2;
	
	//ponteiro para variáveis 
	int *pM = &m; 
	int *pN = &n;	
	// -----------------------

	
	//vetores e matriz dinâmica 
        int peso[*pN];
        float mediaFinal[*pN];
	float **nota;

	//aloco vetor principal
	nota = malloc(2 *sizeof(sizeof(float *)));
	
	//aloco cada vetor linha
	for(int i=0; i<2; i++){
		nota[i] = (float *)malloc(2* sizeof(float));
	}
	
	//Ponteiro peso, média e nota
	int *pPeso = &peso[*pN]; 	
	float *pMediaFinal = &mediaFinal[*pM];
	  

        struct nome nomes[m];
		
	nomes[0].nome[4] = 'L','u','i','z';
	nomes[1].nome[4] = 'J','u','c','a';

        AlunoDestaque(pN,pM,nomes,nota,pMediaFinal,peso);
}
