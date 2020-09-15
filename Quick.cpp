#include <iostream>
using namespace std;

void swapp(int &a, int &b){
    int temp = a;
    a=b;
    b=temp;
}

int particion(int *A, int p, int r){
    int x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if (A[j]<=x){
            i=i+1;
            swapp(A[i],A[j]);
        }
    }
    swapp(A[i+1],A[r]);
    return i+1;
}
void quickk(int *A, int p, int r){
    int q;
    if (p<r){
        q=particion(A,p,r);
        quickk(A,p,q-1);
        quickk(A,q+1,r);
    }
}

int main(){
	int tam = 1000000;
	int *a = new int[tam];
	for (int k=0;k<tam;k++){
        cin>>a[k];            
    }//a[k]=rand();
    quickk(a,0,tam-1);
	for (int i=0;i<tam;i++)
        cout<<a[i]<<endl;
	delete[] a;


	return 0;

} 
