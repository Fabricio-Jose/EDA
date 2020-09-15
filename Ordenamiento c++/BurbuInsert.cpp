#include <iostream>

void insercion(int* A,int n)
{
	int i, x, j;  
    for (i = 1; i < n; i++) 
    {  
        x = A[i];  
        j = i - 1;  
        while (j >= 0 && A[j] > x) 
        {  
            A[j + 1] = A[j];  
            j = j - 1;  
        }  
        A[j + 1] = x;  
    } 
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  


void burbuja(int *A,int n)
{
	int i, j;  
    for (i = 0; i < n-1; i++)      
    	for (j = 0; j < n-i-1; j++)  
        	if (A[j] > A[j+1])  
            	swap(&A[j], &A[j+1]);
}
int main()
{
	return 0;
}