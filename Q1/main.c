#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"

void CalcularMediaFinais(int n, int m, float nota[][n],float *mediaFinal,int *peso){
	//Preenchendo o vetor peso 
	int i,j; 
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
   		peso[i] = rand()%11;
   		if(i % 10 == 0){
      			printf("\n");
        	} 	
         
   		//printf(" %3d",peso[i]);
	}
        //printf("\n \n");
       
        //----------------------------------------------------------------------//
  
        //Preenchendo a matriz nota

        float aux = 0;    
	srand(time(NULL));
	for(j=0;j<m;j++){ 
 		for(i=0;i<n;i++){
   			aux = 0+ 10.0*((float)(rand())/RAND_MAX);
                        nota[j][i] = aux;
                        if(i % 10 == 0){
      				printf("\n");
        		} 	
   		//printf(" %.1f",nota[j][i]);
		}    
        }
        //printf("\n \n");
       //----------------------------------------------------------------------//
      
       //Cálculo da média
       aux=0;
       
       for(j=0;j<m;j++){ 
 		for(i=0;i<n;i++){
   			aux+=nota[j][i]*peso[j]; 
		}
    
        mediaFinal[j] = aux/10; 
        //printf(" %.1f \n",mediaFinal[j]);
      }
}

void main(){
        int m = 2;
 	int n = 4;	
       
        
        int peso[n];
        float mediaFinal[m];
	float nota[m][n];

    
        CalcularMediaFinais(n,m,nota,mediaFinal,peso);
        	
}

