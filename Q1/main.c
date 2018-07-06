#include <stdio.h>

void CalcularMediaFinal(int n, float nota[][n], int m,float peso[], float mediaFinal[]){
  mediaFinal[0] = ((nota[0][1]*peso[1])+(nota[0][2]*peso[2])+(nota[0][3]*peso[3])+(nota[0][4]*peso[4]))/10;  
  mediaFinal[1] = ((nota[1][1]*peso[1])+(nota[1][2]*peso[2])+(nota[1][3]*peso[3])+(nota[1][4]*peso[4]))/10;   
}

void main(){
	int m = 2;
 	int n = 4;	
       
        float mediaFinal[m];
 	float nota[m][m];
	float peso[n];
        
        nota[m][n] = 10,10,10,10;10,8,6,6;
        peso[n] = 6,4,8,10;
	
	
       CalcularMediaFinal(n,nota,m,peso,mediaFinal);
}

