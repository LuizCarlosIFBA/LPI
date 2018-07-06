#include <stdio.h>

#include<stdlib.h>

void leia () {
	int num[7][7],i,j,b=1;//*Carrega a matrix 7x7 digitada pelo usuario *//

	for (i=0;i<7;i++){
		for (j=0;j<7;j++){
                        printf ("digite o %d numero:",b);
			scanf("%d",& num[i][j]); b++;
		}

	}

}


void valor(){
	int num[7][7],i,j;

	printf("\nmatriz digitada:\n");

	for (i=0;i<7;i++){
		printf("|");
                for (j=0;j<7;j++){
			printf(" %d ",num[i][j]);
                }//*mostra a matrix 7x7*//

	        printf("|\n");

        }

}

void ordem(){

	int num[7][7],i,j,a,aux;
	printf("\nmatriz ordenada:\n");

	for (i=0;i<49;i++){	
		for (j=0;j<7;j++){
			for(a=0;a<6;a++){
				if (num[j][a]> num[j][a+1]){
					aux= num[j][a];
					num[j][a]= num[j][a+1];
					num[j][a+1]= aux;
				}

				if (a==5 && j<6){
					if(num[j][a+1]> num[j+1][0]){
						aux= num[j+1][0];
						num[j+1][0]= num[j][a+1];
                                                num[j][a+1]= aux;

					}

				}

		        }

         }}

         printf("\n");

         for(i=0;i<7;i++){
         	printf("|");
                for(j=0;j<7;j++){
        		printf(" %d ",num[i][j]);
        	}//*mostra a matrix 7x7 ordenada*//

		printf("|\n\n");
	}

}

void main(){//*Função principal que vai chamar as outras*//

leia();

valor();

ordem();

system("pause");

}
