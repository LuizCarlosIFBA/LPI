#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>

struct nome{
	char nome[4];
};	
	  
void AlunoDestaque(int n, int m, struct nome *nomes, float nota[][n],float *mediaFinal,int *peso){
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
   			aux+=nota[j][i]; 
		}
    
        mediaFinal[j] = aux/10; 
        //printf(" %.1f \n",mediaFinal[j]);
      }

     //-----------------------------------------------------------------------//
     //lógica para aluno destaque
     
     /*
     printf("Média não ordenada"); 
     for(i=0;i<m;i++){ 	  
          printf(" %.2f ",mediaFinal[i]);
     }   
     printf(" ");*/   
   
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
     /*
     printf("\n Média ordenada"); 
     for(i=0;i<m;i++){ 	  
          printf(" %.2f ",mediaFinal[i]);
     }	
     printf(" ");*/

     int destaque = 0;
     for(int i=0;i<m;i++){ 
 	 for(int j=0;j<m;j++){
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
 	int n = 4;	
       
        
        int peso[n];
        float mediaFinal[m];
	float nota[m][n];
        struct nome nomes[m];
		
	nomes[0].nome[4] = 'L','u','i','z';
	nomes[1].nome[4] = 'J','u','c','a';

        AlunoDestaque(n,m,nomes,nota,mediaFinal,peso);
}
