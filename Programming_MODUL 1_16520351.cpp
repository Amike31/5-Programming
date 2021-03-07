// Nama         : Rahmat Rafid Akbar
// NIM          : 16520351
// Program      : Apakah Tahun Kabisat
// Spesifikasi  : Mengetahui apakah sebuah tahun adalah tahun kabisat atau bukan

#include<iostream>
using namespace std;

int main(){
    int n;
    cout <<"Banyak Tahun: "; cin >> n;
    int year[n];        // Deklarasi Array
    
    // Looping
    for (int i=0;i<n;++i){
        cout<<"Tahun ke-"<<i+1<<": ";
        cin>>year[i]; }

    for (int i=0;i<n;++i)
    {
        if (year[i]%4==0 && year[i]%100!=0) {
            cout<<"Leap Year"<<endl; }
        else if (year[i]%400==0) {
            cout<<"Leap Year"<<endl; }
        else {
            cout<<"Not a Leap Year"<<endl; }
    }
}