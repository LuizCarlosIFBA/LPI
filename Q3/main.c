#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>

struct nome{
	char nome[4];
};	
	  
void AlunoDestaque(int n, int m, struct nome *nomes, float **nota,float *mediaFinal,int *peso){
	//Preenchendo o vetor peso 
	int i,j; 
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
   		peso[i] = rand()%11;
   		if(i % 10 == 0){
      			//printf("\n");
        	} 	
         
   	}
   
       //----------------------------------------------------------------------//
  
        //Preenchendo a matriz nota

        float aux = 0;    
	srand(time(NULL));
	for(j=0;j<m;j++){ 
 		for(i=0;i<n;i++){
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
       
       for(j=0;j<n;j++){ 
 		for(i=0;i<n;i++){
   			aux+=nota[j][i]; 
		}
    
        mediaFinal[j] = aux/10; 
      }

     //-----------------------------------------------------------------------//
     //lógica para aluno destaque
     
     for(int i=0;i<m;i++){ 
 	 for(int j=0;j<m;j++){
   	 	aux = 0;
		if(mediaFinal[i]<mediaFinal[j]){
			aux = mediaFinal[j];
                        mediaFinal[j] = mediaFinal[i];
			mediaFinal[i] = aux;
		}		
	 }    
     }
	
   
     int destaque = 0;
     for(int j=0;j<n;j++){
         if(mediaFinal[m]>=7){
	     destaque = nota[m][j]<=5?destaque+0:destaque+1;	
	 }
     }
		
     if(destaque>0){
	printf("Os alunos destaque são:");     
	printf("%c",nomes[m].nome[50]);
     }else printf("Não houve aluno destaque\n");

     
     for(int j=m-1;j==0;j--){
	destaque = 0;
	if(mediaFinal[j]>=7 && mediaFinal[j]==mediaFinal[m]){
        	if(mediaFinal[m]>=7){
	     		destaque = nota[m][j]<=5?destaque+0:destaque+1; 
		}  	
	}
	
        if(destaque>0){
	    printf("%c",nomes[j].nome[50]);
        }
     }		 
}

void main(){
        int m = 2;
 	int n = 2;
	
	//vetores e matriz dinâmica 
        int peso[n];
        float mediaFinal[n];
	float **nota;

	//aloco vetor principal
	nota = malloc(2 *sizeof(sizeof(float *)));
	
	//aloco cada vetor linha
	for(int i=0; i<2; i++){
		nota[i] = (float *)malloc(2* sizeof(float));
	}
	
	//Ponteiro peso, média e nota
	int *pPeso = &peso[n]; 	
	float *pMediaFinal = &mediaFinal[m];
	  

        struct nome nomes[m];
		
	nomes[0].nome[4] = 'L','u','i','z';
	nomes[1].nome[4] = 'J','u','c','a';

        AlunoDestaque(n,m,nomes,nota,pMediaFinal,peso);
}
