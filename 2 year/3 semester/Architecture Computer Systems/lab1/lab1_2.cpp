#include <bits/stdc++.h>
using namespace std;

void display(double a[],int n){
    static int licznik = 1;
    double sum=0;
    for( int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum==137){
        cout<<licznik<<". ";
        for (int i = 0; i < n; i++)
        {   
            if(i<n-1)
                cout<<a[i]<<"  +  ";
            else
                cout<<a[i]<<"  =  ";
        }
        cout<<sum;
        cout << endl;
        licznik++;
    }
}
void findPermutations(double a[], int n){
    sort(a,a+n);
    cout<<"Posible permutations:\n";
    do{
        display(a,n);
    }while(next_permutation(a, a+n));
}

int main(){
    double a[] = {1.00E+21, 17.0, -10.0, 130.0, -1.00E+21};
    int n= sizeof(a)/sizeof(a[0]);    
    findPermutations(a,n);
    return 0;   
}