#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

void trapezoida(float n,float a,float b){
float h = (b-a)/n;
float l;
float sum = 0;
float x = 0;
for(int i= 0;i<=n;i++)
{
if(i == 0 || i == n)
{
sum = sum + (x*x);
x = h+x;
}
else
{
sum = sum + (x*x)*2;
x = h+x;
}
}
l = (h/2) * sum;
printf("Nilai h = %f dan Nilai L =%f\n", h, l);
}

int main(){
printf("Metode Trapezoida\n");
trapezoida(10, 0, 1);
trapezoida(20, 0, 1);
trapezoida(30, 0, 1);
trapezoida(50, 0, 1);
trapezoida(100, 0, 1);
trapezoida(1000, 0, 1);
trapezoida(10000, 0, 1);
printf("\n");
return 0;
}