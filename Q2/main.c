#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>


void AlunoDestaque(char *nome1, char *nome2,int n, int m, float nota[][n],float *mediaFinal,int *peso){
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
        printf(" %.1f \n",mediaFinal[j]);
      }

     //-----------------------------------------------------------------------//
     //lógica para aluno destaque
     
     /*
     printf("Média não ordenada"); 
     for(i=0;i<m;i++){ 	  
          printf(" %.2f ",mediaFinal[i]);
     }   
     printf(" ");*/   
   
     for(i=0;i<m;i++){ 
 	 for(j=0;j<m;j++){
   	 	aux = 0;
		if(mediaFinal[i]<mediaFinal[j]){
			aux = mediaFinal[j];
                        mediaFinal[j] = mediaFinal[i];
			mediaFinal[i] = aux;
		}		
	 }    
     }
     
     int destaque = 0;
     /*printf("\n Média ordenada"); 
     for(i=0;i<m;i++){ 	  
          //printf(" %.2f ",mediaFinal[i]);
     }	
     printf(" ");*/

     
     for(i=0;i<m;i++){ 
 	 for(j=0;j<m;j++){
		if(nota[i][j]>=5 && mediaFinal[i]>7){
			if(i==0){
			    printf("O aluno destaque é %s",nome1[6]);
			    destaque++;
                        }else if(i==1){printf("O aluno destaque é %s",nome1[6]); destaque++;}	
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

       
	char nome1[6] = "João";
	char nome2[6] = "Lucas";
       
        AlunoDestaque(nome1,nome2,n,m,nota,mediaFinal,peso);
}


