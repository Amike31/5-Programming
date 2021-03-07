#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void trapezoida(float n,float a,float b){
float h = (b-a)/n;
float l;
float sum = 0;
float x = a;
for(int i= 0;i<=n;i++){
    if(i == 0 || i == n){
        sum = sum + (x);
        x = h+x;
    }
    else{
        sum = sum + (x)*2;
        x = h+x;
    }
}
l = (h/2) * sum;
printf("Nilai h = %f dan Nilai L =%f\n", h, l);
}

int main(){
float a; float b; float n;
printf("Metode Trapezoida\n");
cin>>a; cin>>b; cin>>n;
trapezoida(n,a,b);
printf("\n");
return 0;
}