#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#include "time.h"
#include <string.h>

struct nome{
	char nome[50];
};

void desvioPadrao(float *pMedFinal,int *m, float *pMedia, float *pDPadrao){
	float soma = 0;
        float termo = 0;
	float *pSoma = &soma;
	float *pTermo = &termo;

        int i;
	for(i=0;i<*m;i++){
		*pSoma += pMedFinal[i];
		
	}
	*pMedia = *pSoma/(*m);
       
        *pSoma = 0;
        *pTermo = 0;
 	for(i=0;i<*m;i++){
		*pTermo = pMedFinal[i]-(*pMedia);
		*pSoma += pow(*pTermo,2);
	}
      
        //não é a coisa mais aconselhável a fazer, porém está ok 
	//na variável diz somo, mas não foi somente essa operação 
        //realizada, mesmo assim o cálculo está certo. 
	*pDPadrao = *pSoma/(*m-1);
        	
        printf("A média aritmética é: %.1f \n",*pMedia);
	printf("O desvio padrão é: %.1f \n",sqrt(*pDPadrao));
}			     	

void AlunoDestaque(int *n, int *m, float **nota,float *mediaFinal,int *peso){
	 typedef struct {
        	char nome[100];
	 } Aluno;
 	 
	 //'m' recebeu os valores de TAM
         Aluno alunos[*m];
         
        
         for(int i= 0;i<*m;i++){
		printf("\nEscreva o nome do aluno(%i): ",i+1);
                  setbuf(stdin, NULL);
                 scanf("%[^\n]i",alunos[i].nome);
		 setbuf(stdin, NULL);	
         }
	
		 setbuf(stdin, NULL);         
	int i,j; 
	i = 0;
	do{
		for(j=0;j<*n;j++){
			printf("\nEscreva %d º  nota: ",j+1);
   			scanf("%f",&nota[j][i]);
                        if(i % 10 == 0){
      				printf("\n");
        		} 
	        }
	i++;
	}while(i<(*m));	

	//Preenchendo o vetor peso 

	srand((unsigned)time(NULL));
	for(i=0;i<*n;i++){
   		peso[i] = rand()%11;
   		if(i % 10 == 0){
      			//printf("\n");
        	} 	
         
   	}
   
       //----------------------------------------------------------------------//
  
       //Cálculo da média
       float aux=0;
       
       for(j=0;j<*n;j++){ 
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
     for(int j=0;j<*n;j++){
         if(mediaFinal[*m]>=7){
	     destaque = nota[*m][j]<=5?destaque+0:destaque+1;	
	 }else printf("Não houve aluno destaque");
     }
    
     if(destaque>0){
	printf("Os alunos destaque são:");     
	printf("%c",alunos[*m].nome[100]);
     }

     
     for(int j=*m-1;j==0;j--){
	destaque = 0;
	if(mediaFinal[j]>=7 && mediaFinal[j]==mediaFinal[*m]){
        	if(mediaFinal[*m]>=7){
	     		destaque = nota[*m][j]<=5?destaque+0:destaque+1; 
		}  	
	}
	
        if(destaque>0){
	    printf("%c",alunos[j].nome[100]);
        }
     }	
     //-------------------------------------

     float Media = 0;
     float DPadrao = 0;
	
     //Ponteiros média e Dpadrão
     float *pMedia = &Media;
     float *pDPadrao = &DPadrao; 
     printf("\n");
     desvioPadrao(mediaFinal,m,pMedia,pDPadrao);		 
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
        
	//ponteiro TAM
	int *pTAM = &m;	
	int *pN = &n;	
	// -----------------------
	
     	//vetores e matriz dinâmica 
        int peso[*pN];
        float mediaFinal[*pTAM];
	float **nota;

	//aloco vetor principal
	nota = malloc((*pN) *sizeof(sizeof(float *)));
	
	//aloco cada vetor linha
	for(int i=0; i<*pN; i++){
		nota[i] = (float *)malloc((*pTAM)* sizeof(float));
	}
	
	//Ponteiro peso, média e nota
	int *pPeso = &peso[*pN]; 	
	float *pMediaFinal = &mediaFinal[*pTAM];


        AlunoDestaque(pN,pTAM,nota,pMediaFinal,pPeso);
}
// gcc -o main main.c -lm
