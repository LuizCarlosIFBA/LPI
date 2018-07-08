#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>
  	
	  
void AlunoDestaque(int n, int m,float nota[][n],float *mediaFinal,int *peso){
	 typedef struct {
        	char nome[100];
	 } Aluno;
 	 
	 //'m' recebeu os valores de TAM
         Aluno alunos[m];
          
         for(int i=0; (i < m); i++){
                printf("\nEscreva o nome do aluno(%i): ",i+1);
                scanf("%i",alunos[i].nome);
		setbuf(stdin, NULL);
		for(int j=0;j<n;j++){
			printf("\nEscreva %d º  nota: ",j+1);
   			scanf("%f",&nota[j][i]);
                        if(i % 10 == 0){
      				printf("\n");
        		} 
	        }	
        }
        //printf("\n \n");
       
       //Cálculo da média
       int aux=0;
       
       for(int j=0;j<m;j++){ 
 		for(int i=0;i<n;i++){
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
   /*
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
     /*
     printf("\n Média ordenada"); 
     for(i=0;i<m;i++){ 	  
          printf(" %.2f ",mediaFinal[i]);
     }	
     printf(" ");*/
      /*
     int destaque = 0;
     for(i=0;i<m;i++){ 
 	 for(j=0;j<m;j++){
		if(nota[i][j]>=5 && mediaFinal[i]>7){
			if(i==0){
			    printf("O aluno destaque é %s",nomes[0].nome[4]);
			    destaque++;
                        }else if(i==1){printf("O aluno destaque é %s",nomes[0].nome[4]); destaque++;}	
		}
         }
     }
     printf(destaque == 0?"Turma não tem aluno Destaque\n":" ");		
*/
 
}
void main(){
        int n = 0;
	int m = 0;

	printf("Escreva a quantidade de alunos: ");
	int TAM = 0;
	scanf("%d",&TAM);	
		
	while(TAM<=0){    
		printf("Escreva apenas números positivos : ");
		scanf("%d",&TAM);
	}
        m = TAM;  
 
        printf("Escreva a quantidade de notas(até 5 notas): ");
	scanf("%d",&n);	
	while(n>5 && n<=0){    
		printf("Escreva a quantidade de notas(até 5 notas), o número deve ser maior que 0: ");
		scanf("%d",&n);
	}
        
        int peso[n];//5 posições
	for(int i=0; i < n; i++){
                printf("\nEscreva o peso %d º: ",i+1);
                scanf("%d",&peso[i]);
        }        

	float mediaFinal[m];
	float nota[m][n];
        	
     
        AlunoDestaque(n,m,nota,mediaFinal,peso);
}
