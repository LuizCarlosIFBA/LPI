#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"

void CalcularMediaFinais(int n, int m, float  **nota,float *pMediaFinal,int *pPeso){
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
        int m = 4;
 	int n = 4;	
        
	//vetores e matriz dinâmica 
        int peso[n];
        float mediaFinal[m];
	float **nota;
	
	//aloco vetor principal
	nota = malloc(4 *sizeof(sizeof(float *)));
	
	//aloco cada vetor linha
	for(int i=0; i<4; i++){
		nota[i] = (float *)malloc(4 * sizeof(float));
	}

	//Ponteiro peso e média 
	int *pPeso = &peso[n]; 	
	float *pMediaFinal = &mediaFinal[m];
	  
	void CalcularMediaFinais(int n, int m, float **nota,float *pMediaFinal,int *pPeso);  
        CalcularMediaFinais(n,m,nota,pMediaFinal,pPeso);
        	
}

