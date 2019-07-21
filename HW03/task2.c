#include <stdio.h>
#include<time.h>

void outputT2 (double solution [], double differenz, int s )
{
	printf ("%f",  differenz);
	for (int j = 0; j <s; j++)
	{
    		printf("%f \n", solution[j]); 
    	}
 }
 
 double  randomT2  (double **matrix, int size)
 {
     // write matrix with random number
    for (int i =0; i < size; i++)
    {
        for (int j = 0; j <size; j++)
	{
            double var1 = rand() ;
            double var2 = rand() ;
            double var = var1/var2;
            matrix [i][j] =  var;
       
        }
    }
    return **matrix;
 }
 
 
int main()
{   
    int size = 1000; // matrix and vector dimension
    double **matrix;
    double *vector;
    double *solution;
    vector = (double*) malloc(size*sizeof(double));
    solution = (double*) malloc(size*sizeof(double));
    matrix = (double**) malloc(size *sizeof(double *));
    
    for(int i=0;i<size;i++)
    {
    matrix[i]=(double *) malloc(20*sizeof(double));
    }
    // write vector
    for (int j = 1; j <size+1; j++){
        double a = 0.5;
            if (j%2==0){
                vector[j] = -a;
            }
            else {
                vector[j] = a;
                
            }
            
    }
    randomT2(matrix, size);
    //start time measuring
    clock_t start = clock();
    // calculate solution
    for (int i =0; i < size; i++){
        for (int j = 0; j <size; j++){
            solution[i] = solution[i] + matrix[i][j]*vector[j];
             
        }
    }
    clock_t end = clock();
    // end of time measure
    double differenz = (double)(end-start)/CLOCKS_PER_SEC;
    
    outputT2(solution, differenz, size);

    return 0;
}
