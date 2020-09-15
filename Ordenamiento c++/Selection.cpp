#include <iostream>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int *arr, int n)  
{  
    int i, j, min_idx;  
    for (i = 0; i < n-1; i++){  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

int main(){
	int tam = 1000000;
	int *a = new int[tam];
    
    
    
	for (int k=0;k<tam;k++){
        cin>>a[k];            
    }//a[k]=rand();
    selectionSort(a,tam);
	for (int i=0;i<tam;i++)
        cout<<" "<<a[i]<<" ";
	delete[] a;


	return 0;

} 
