#include<stdio.h>
void imprimir (int filas, int columnas, float *);

 
void pivotear (int filas, int columnas, float *, float *, float *, int j);

 
 
main () 
{
  
 
    // TamaC1o de matriz y ingreso de datos
  int filas = 0, columnas = 0;
 
printf ("Digita lo que se te pide :3");
  
 
printf ("\nIngresa el numero de filas: ");
  
 
scanf ("%i", &filas);
  
 
printf ("\nIngresa el numero de columanas: ");
  
 
scanf ("%i", &columnas);
  
 
columnas = columnas + 1;
  
 
float MatrizA[filas][columnas];
  
 
 
printf ("\nIngresa los valores de la matriz :");
  
 
for (int j = 0; j < columnas; j++)
    
 
    {
      
 
for (int i = 0; i < filas; i++)
	
 
	{
	  
 
if (columnas - 1 == j)
	    
 
	    {
	      
 
printf ("\nIngresa el valor despues del igual =");
	    
 
}
	  
 
printf ("\nIngresa el valor de en (%i,%i): ", i + 1, j + 1);
	  
 
scanf ("%f", &MatrizA[i][j]);
	
 
}
    
 
}
  
 
    // Se muestra la matriz con la que se inicia
    printf ("Matriz Principal\n");
  
 
imprimir (filas, columnas, &MatrizA[0][0]);
  
 
printf ("\n");
  
 
 
    //Aqui se empieza con el metodo de gauss-jordan
  
float pivoteaux = 0;
  
 
float vectorPivote[columnas];
  
 
float vectorPivoteaux[columnas];
  
 
float n = 0;
  
 
 
 
for (int j = 0; j < columnas - 1; j++)
    
 
    {
      
 
	// Se le da j a el vector pivote
	pivotear (filas, columnas, &MatrizA[0][0], &vectorPivote[0],
		  
&vectorPivoteaux[0], j);
      
 
 
for (int i = 0; i < filas; i++)
	
 
	{
	  
 
printf ("\n(%d,%d)\n", i + 1, j + 1);
	  
 
	    //En el caso de que "i" sea diferente de "j" se le da
	    //un valor a "n"
	    if (i != j && j < columnas - 1)
	    
 
	    {
	      
 
n = MatrizA[i][j];
	    
 
 
}
	  
 
 
for (int k = 0; k < columnas; k++)
	    
 
	    {
	      
 
MatrizA[i][k] = (-1 * n * vectorPivote[k]) + MatrizA[i][k];
	  
 
 
} 
 
if (i == j)
	    
 
	    {
	      
 
for (int l = 0; l < columnas; l++)
		
 
		{
		  
 
MatrizA[i][l] = vectorPivoteaux[l];
		  
 
if (MatrizA[i][l] == -0)
		    
 
		    {
		      
 
MatrizA[i][l] = 0;
		    
 
}
		
 
 
}
	    
 
}
	  
 
imprimir (filas, columnas, &MatrizA[0][0]);
	
 
}
      
 
n = 0;
      
 
for (int k = 0; k < columnas; k++)
	
 
	{
	  
 
vectorPivote[k] = 0;

 
} 
} 
 
} 
 
void 


imprimir (int filas, int columnas, float *MatrizA) 
{
  
 
printf ("\n\n");
  
 
int contar = 0;
  
 
 
for (int i = 0; i < filas * columnas; i++)
    
 
    {
      
 
if (contar < columnas)
	
 
	{
	  
 
printf (" %f ", MatrizA[i]);
	  
 
contar++;
	
 
}
      
 
      else
	
 
	{
	  
 
contar = 0;
	  
 
printf ("\n");
	  
 
printf (" %f ", MatrizA[i]);
	  
 
contar++;
	
 
}
    
 
 
}

 
 
}


 
 
 
void 
pivotear (int filas, int columnas, float *MatrizA, float *vectorPivote,
	  
float *vectorPivoteaux, int j) 
{
  
 
float pivoteaux = 0;
  
 
float matrizTemporal[filas][columnas];
  
 
int sumi = 0;
  
 
    //se copia los datos de la Matriz Principala una matriz temporal 
    //para evitar que se envie como apuntador y se convierte en un vector.
    
for (int i = 0; i < filas; i++)
    
 
    {
      
 
for (int k = 0; k < columnas; k++)
	
 
	{
	  
 
matrizTemporal[i][k] = MatrizA[sumi];
	  
 
sumi++;
  
 
} 
} 
for (int i = 0; i < filas; i++)
    
 
    {
      
 
if (i == j)
	
 
	{
	  
 
pivoteaux = matrizTemporal[i][j];
	  
 
printf ("Pivote: %f\n", pivoteaux);
	  
 
for (int l = 0; l < columnas; l++)
	    
 
	    {
	      
 
matrizTemporal[i][l] = matrizTemporal[i][l] / pivoteaux;
	      
 
vectorPivote[l] = matrizTemporal[i][l];
	      
 
vectorPivoteaux[l] = matrizTemporal[i][l];
	
 
 
} 
}
    
 
} 
//Luego los datos de la matriz principal se le dan a una nueva matriz
    sumi = 0;
  
 
 
for (int i = 0; i < filas; i++)
    
 
    {
      
 
for (int k = 0; k < columnas; k++)
	
 
	{
	  
 
MatrizA[sumi] = matrizTemporal[i][k];
	  
 
sumi++;

 
} 
} 
 
 
} 
