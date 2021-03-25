#include <iostream>
#include <unistd.h> //lib for time function
using namespace std;

float pls(float a,float b){
    return a+b; }
float mns(float a,float b){
    return a-b; }
float times(float a,float b){
    return a*b;}
float div(float a,float b){
    return a/b; }
float pangkat(float a, float b){
    //rekursif :)
    if (b == 0)  {return 1;}                  //Basis
    else  {return (a * pangkat(a,b-1));}      //Rekurens
}

main(){
  string next="y";
  while (next=="y"){             //digunakan while agar kalkulator dapat dipakai jika tidak diterminate
    float a,b;      //asumsi bilangan float
    int type;       //digunakan untuk memilih type
    cout<<"Calculator of Math"<<endl;
    cout<<"------------------------"<<endl;
    cout<<"Pilih tipe kalkulator"<<endl;
    cout<<"1. Operasi Biasa"<<endl;
    cout<<"2. Integral Tentu"<<endl;
    cout<<endl;
    cout<<"Kalkulator tipe: "; cin>>type;
    cout<<"------------------------"<<endl;

    if (type==1){
        cout<<"~~~ Kalkulator Biasa ~~~"<<endl;
        cout<<endl;
        cout<<"Operasi yang tersedia: "<<endl;
        int op;     //digunakan untuk memilih operasi
        cout<<"1. Penjumlahan"<<endl;
        cout<<"2. Pengurangan"<<endl;
        cout<<"3. Perkalian"<<endl;
        cout<<"4. Pembagian"<<endl;
        cout<<"5. Perpangkatan (b bulat, b>1)"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"Operasi ke-: ";    cin>>op;
        cout<<"Masukkan nilai a: ";    cin>>a;
        cout<<"Masukkan nilai b: ";    cin>>b;
        cout<<endl;
        sleep(1);       //digunakan agar program memiliki jeda seakan2 sedang proses
        if (op==1){
            cout<<"a+b = "<<pls(a,b);    }
        else if (op==2){
            cout<<"a-b = "<<mns(a,b);    }
        else if (op==3){
            cout<<"a*b = "<<times(a,b);    }
        else if (op==4){
            cout<<"a/b = "<<div(a,b);    }
        else if (op==5){
            cout<<"a^b = "<<pangkat(a,b);    }
        cout<<endl;
    }
    else if (type==2){
    /*Integral Tentu menggunakan metode trapesium dilakukan dengan mempartisi interval
      sebanyak n buah partisi. Lalu menggunakan aproximasi rumus luas trapesium L=h(a+b)/2 
      dan menghitung sigma dari a sampai b, sehingga menghitung Ltot dengan menjumlahkan
      semua partisi. */
    //Prekondisi pembacaan: Memahami Integral tentu menggunakan metode trapesium
        int n;      //banyak partisi berupa integer positif
        cout<<"~~~ Integral Tentu ~~~"<<endl; //Fungsi test case : f(x)= 2x+1
        cout<<endl;
        cout<<"Batas Atas: "; cin>>a;
        cout<<"Batas Bawah: "; cin>>b;
        cout<<"Banyak Partisi: "; cin>>n;
        cout<<endl;
        sleep(1);       //digunakan agar program memiliki jeda seakan2 sedang proses
        float sum=0;            //penampung luas trapesium tiap partisi
        float deltaX=(b-a)/n;   //lebar partisi yang nantinya merepresentasikan tinggi trapesium
        float X=a;              //titik uji, dari X0(a) sampai Xn(b) dengan jarak deltaX tiap titik uji
        for (int i=0;i<=n;i++){
            // untuk titik uji awal dan akhir hanya 1 kali terpakai
            if (i==0||i==n){
                sum = sum + (2*X+1);   //fungsi testcase f(x)=(2x+1)
                X = X+deltaX; // x, titik uji digeser
            }
            // untuk titik uji di tengah terpakai 2 kali
            else{
                sum = sum + 2*(2*X+1);
                X = X+deltaX; // x, titik uji digeser
            }
        }
        float total = (deltaX*sum)/2;   //hasil akhir dari integral menggunakan rumus trapesium
        cout<<"Integral tentu f(x)=2x+1 dari "<<a<<" sampai "<<b<<" = "<<total<<endl;
    }
    cout<<"------------------------"<<endl;                 //opsi untuk melanjutkan atau tidak
    cout<<"Next Calculation? (y/n)"<<endl; cin>>next; 
    cout<<endl;
    sleep(1);       //digunakan agar program memiliki jeda seakan2 sedang proses
  }
}