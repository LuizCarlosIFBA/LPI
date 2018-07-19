#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"

void CalcularMediaFinais(int n, int m, float nota[][n],float *pMediaFinal,int *pPeso){
	//Preenchendo o vetor peso 
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
   		pPeso[i] = rand()%11;
   		if(i % 10 == 0){
      			printf("\n");
        	} 	
         
	}
       
        //----------------------------------------------------------------------//
  
        //Preenchendo a matriz nota

        float aux = 0;    
	srand(time(NULL));
	for(int j=0;j<m;j++){ 
 		for(int i=0;i<n;i++){
   			aux = 0+ 10.0*((float)(rand())/RAND_MAX);
                        nota[j][i] = aux;
                        if(i % 10 == 0){
      				printf("\n");
        		} 	
		}    
        }

       //----------------------------------------------------------------------//
      
       //Cálculo da média
       aux=0;
       
       for(int j=0;j<m;j++){ 
 		for(int i=0;i<n;i++){
   			aux+=nota[j][i]*pPeso[j]; 
		}
    
        pMediaFinal[j] = aux/10; 
      }
}

void main(){
        int m = 2;
 	int n = 4;	
       
        int peso[n];
        float mediaFinal[m];
	float nota[m][n];
	
	//Ponteiro peso, média e nota
	int *pPeso = &peso[n]; 	
	float *pMediaFinal = &mediaFinal[m];
	    
        CalcularMediaFinais(n,m,nota,pMediaFinal,pPeso);
        	
}

