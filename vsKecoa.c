/*
Nama    :Bryan Bernigen
NIM     :16520237
*/

/*
READ ME
Fungsi yang akan dijalankan adalah int main() <-Fungsi Utama
Sisanya merupakan fungsi tambahan yang akan dipanggal di fungsi utama
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <math.h>

//Fungsi Player
//Menampilkan peta 10x10
int peta(int map[10][10])
{
    int i,j;
        for (j=9;j>=0;j--)
    {
        for (i=0;i<10;i++)
        {
            printf("%d ",map[j][i]);
        }
        printf("\n");
    }

}
//Mengembalikan kordinat x tempat player berada
int xplayer(int map[10][10])
{
    int i,j;
        for (j=9;j>=0;j--)
    {
        for (i=0;i<10;i++)
        {
            if (map[j][i]==1)
            {
                return i;
            }
        }
    }
}
//Mengembalikan kordinatal y tempat player berada
int yplayer(int map[10][10])
{
    int i,j;
        for (j=9;j>=0;j--)
    {
        for (i=0;i<10;i++)
        {
            if (map[j][i]==1)
            {
                return j;
            }
        }
    }
}
//Fungsi pilihan gerakan player
int gerak(int map[10][10], int xplayer, int yplayer, int xkecoa, int ykecoa,int jarak,int healthKecoa,int kill,int healthPlayer)
{
    system("cls");
    peta(map);
    char gerakan;
    printf("------Control------\n");
    printf("   (w)     (e) - Shoot\n");
    printf("(a)   (d)  \n");
    printf("   (s)     (q) - Quit\n");
    printf("Range: %d\n",jarak);
    printf("Nyawa Kecoa: %d\n",healthKecoa);
    printf("Jumlah Kill: %d\n",kill);
    printf("Nyawa User : %d\n",healthPlayer);
    printf("Move: ");
    //user diminta menginput "w,a,s,d" untuk bergerak, "s" untuk menembak, "q" untuk keluar aplikasi
    gerakan=_getch();
    //"w,a,s,d" tidak akan menggerakan player apabila player bergerak keluar peta atau player bergerak menabrak kecoa
    switch (gerakan)
    {
    case 'w': //bergerak ke atas
        if (yplayer==9)
        {
            return 1;
        }
        else if (yplayer+1==ykecoa && xplayer==xkecoa)
        {
            return 1;
        }     
        else
        {
            map[yplayer][xplayer]=0;
            map[yplayer+1][xplayer]=1;
            return 1;
        }
    case 'a': //bergerak ke kiri
        if (xplayer==0)
        {
            return 1;
        }
        else if (xplayer-1==xkecoa && yplayer==ykecoa)
        {
            return 1;
        }      
        else
        {
            map[yplayer][xplayer]=0;
            map[yplayer][xplayer-1]=1;
            return 1;
        }
    case 's': //bergerak ke belakang
        if (yplayer==0)
        {
            return 1;
        }
        else if (yplayer-1==ykecoa && xplayer==xkecoa)
        {
            return 1;
        }
        else
        {
            map[yplayer][xplayer]=0;
            map[yplayer-1][xplayer]=1;
            return 1;
        }
    case 'd': //bergerak ke kanan
        if (xplayer==9)
        {
            return 1;
        }
        else if (xplayer+1==xkecoa && yplayer==ykecoa)
        {
            return 1;
        }
        else
        {
            map[yplayer][xplayer]=0;
            map[yplayer][xplayer+1]=1;
            return 1;
        }
    case 'e': //menembak
    {
        return 2;
    }
    case 'q': //keluar
        {
        return 0;
        }
    default: //salah input
        return 1;
    }
}
//fungsi menembak kecoa
int shoot(int map[10][10], int jarak, int healthKecoa)
{
    if (jarak<=4) //jika player menembak kecoa dengan jarak<=3 maka nyawa kecoa akan berkurang 1
    {
        return healthKecoa-1;
    }
    else //jika player menembak kecoa dengan jarak>3 maka nyawa kecoa akan bertambah 1
    {
        return healthKecoa+1;
    }
    
}

//Fungsi Kecoa
//Mengembalikan kordinat x tempat kecoa berada
int xkecoa(int map[10][10])
{
    int i,j;
        for (j=9;j>=0;j--)
    {
        for (i=0;i<10;i++)
        {
            if (map[j][i]==2)
            {
                return i;
            }
        }
    }
}
//Mengembalikan kordinat y tempat kecoa berada
int ykecoa(int map[10][10])
{
    int i,j;
        for (j=9;j>=0;j--)
    {
        for (i=0;i<10;i++)
        {
            if (map[j][i]==2)
            {
                return j;
            }
        }
    }
}
//Fungsi memunculkan kecoa di peta
int spawnKecoa(int map[10][10],int xplayer, int yplayer)
{
    int xkecoa; //kordinat x kecoa pada peta
    int ykecoa; //kordinat y kecoa pada peta
    int ulang=1; 
    while (ulang==1) // kordinat (x,y) kecoa akan dibuat secara random
    {
    xkecoa=rand()%10;
    ykecoa=rand()%10;
    //Jika kordinat (x,y) kecoa digenerate di 8 kotak sekitar player atau di kordinat player,
    //Maka kordinat kecoa akan digenerate ulang
    if(xkecoa==xplayer && ykecoa==yplayer)
    {
        ulang=1;
    }
    else if (ykecoa+1==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa+1==xplayer)
        {
            ulang=1;
        }
        else
        {
            ulang=1;
        }
        
    }
    else if (ykecoa==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa+1==xplayer)
        {
            ulang=1;
        }
        else
        {
            ulang=1;
        }
        
    }
    else if (ykecoa-1==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa==xplayer)
        {
            ulang=1;
        }
        else if (xkecoa+1==xplayer)
        {
            ulang=1;
        }
        else
        {
            ulang=1;
        }
        
    }
    else
    {
        ulang=0;
    }
    }
    //memasukkan kecoa di peta
    map[ykecoa][xkecoa]=2;
}
//Fungsi mengitung jarak kecoa dengan player (bukan jarak secara diagonal)
int jarakKecoa(int xplayer, int yplayer, int xkecoa, int ykecoa)
{
    return abs((xkecoa-xplayer))+abs(ykecoa-yplayer);
}
//Fungsi menggerakan kecoa secara random
int moveKecoa(int map[10][10],int xkecoa, int ykecoa, int xplayer, int yplayer)
{
    int randomMove;
    randomMove=rand()%4;
    switch (randomMove)
    //menggerakan kecoa secara random dengan syarat:
    //kecoa tidak bergerak ke luar peta dan kecoa tidak bergerak menabrak player
    //jika syarat tidak terpenuhi, kecoa tidak akan bergerak
    {
    case 0: //menggerakan kecoa ke atas
        if (ykecoa==9)
        {
            return 1;
        }
        else if (ykecoa+1==yplayer && xkecoa==xplayer)
        {
            return 1;
        }     
        else
        {
            map[ykecoa][xkecoa]=0;
            map[ykecoa+1][xkecoa]=2;
            return 1;
        }
    case 1: //menggerakan kecoa ke kiri
        if (xkecoa==0)
        {
            return 1;
        }
        else if (xkecoa-1==xplayer && ykecoa==yplayer)
        {
            return 1;
        }      
        else
        {
            map[ykecoa][xkecoa]=0;
            map[ykecoa][xkecoa-1]=2;
            return 1;
        }
    case 2: //menggerakan kecoa ke belakang
        if (ykecoa==0)
        {
            return 1;
        }
        else if (ykecoa-1==yplayer && xkecoa==xplayer)
        {
            return 1;
        }
        else
        {
            map[ykecoa][xkecoa]=0;
            map[ykecoa-1][xkecoa]=2;
            return 1;
        }
    case 3: //menggerakan kecoa ke kanan
        if (xkecoa==9)
        {
            return 1;
        }
        else if (xkecoa+1==xplayer && ykecoa==yplayer)
        {
            return 1;
        }
        else
        {
            map[ykecoa][xkecoa]=0;
            map[ykecoa][xkecoa+1]=2;
            return 1;
        }
    case 'q':
        {
            return 0;
        }
    default:
        return 1;
    }

}
//Fungsi damage dari kecoa
int damageKecoa(int xkecoa,int ykecoa, int xplayer, int yplayer, int healthPlayer)
{
    //kecoa akan mendamage player (nyawa player -1) jika player berada di 8 kotak sekitar kecoa
    if (ykecoa+1==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa+1==xplayer)
        {
            return healthPlayer-1;
        }
        else
        {
            return healthPlayer;
        }
        
    }
    else if (ykecoa==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa+1==xplayer)
        {
            return healthPlayer-1;
        }
        else
        {
            return healthPlayer;
        }
        
    }
    else if (ykecoa-1==yplayer)
    {
        if (xkecoa-1==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa==xplayer)
        {
            return healthPlayer-1;
        }
        else if (xkecoa+1==xplayer)
        {
            return healthPlayer-1;
        }
        else
        {
            return healthPlayer;
        }
        
    }
    else
    {
        return healthPlayer;
    }
}
















//Fungsi Utama
int main()
{
    int map[10][10]={0}; //Menginisialisi peta 10x10 yang berisi 0
    int quit=0; //Menginisialisasi quit yang membuat program berhenti ketika quit != 0
    int healthKecoa=3; //Menginisialisasi Nyawa Kecoa. Ketika nyawa kecoa=0, kill bertambah 1
    int kill=0; //Menginisialiasi jumlah kecoa yang player bunuh. Akan bertambah ketika Nyawa kecoa==0
    int healthPlayer=3; //Menginisialisasi nyawa awal player. Program akan selesai ketika nyawa player==0
    int baruSpawnKecoa=0;//Mengecek apakah kecoa baru spawn. Jika baru spawn, kecoa tidak akan bergerak
    srand(time(NULL)); //Menginisialiasi seed agar dapat mengeluarkan angka random (berfungsi dalam memunculkan kecoa dan menggerakan kecoa)
    map[0][0]=1; //Menginisialisasi player di kordinat (0,0)
    spawnKecoa(map,xplayer(map),yplayer(map)); //Menginisialisasi kecoa di lokasi acak yang tidak sekitar player
    
    //Membuat fungsi yang akan terus memutar selama quit!=0
    while (quit==0)
    {
    //switch berfungsi untuk menentukan apakah player mau bergerak(1), menenbak(2), keluar(0)
    switch (gerak(map,xplayer(map),yplayer(map),xkecoa(map),ykecoa(map),jarakKecoa(xplayer(map),yplayer(map),xkecoa(map),ykecoa(map)),healthKecoa,kill,healthPlayer))
    {
    case 0: //player memilih untuk quit pada fungsi gerakan
        quit=1;
        break;
    case 2: //Player memilih untuk menembak kecoa
        //nyawa kecoa akan betambah atau berkurang tergantung hasil fungsi tembakan
        healthKecoa=shoot(map,jarakKecoa(xplayer(map),yplayer(map),xkecoa(map),ykecoa(map)),healthKecoa);
        if (healthKecoa==0) //jika berhasil membunuh kecoa
        {
            map[ykecoa(map)][xkecoa(map)]=0; //menghapus kecoa dari peta
            kill++; //kill player bertambah 1
            healthKecoa=3; //memunculkan kembali kecoa di lokasi random dengan nyawa 3
            spawnKecoa(map,xplayer(map),yplayer(map));
            baruSpawnKecoa=1;
            break;
        }
        quit=0;
        break;
    case 1: //Player memilih untuk Bergerak
    {
        quit=0;
        break;
    }
    default:
        quit=0;
        break;
    }
    //setelah player memilih untuk bergerak/menembak/keluar(quit)
    //Kecoa akan bergerak secara random sesuai fungsi menggerakan kecoa
    if (baruSpawnKecoa==0)
    {
    moveKecoa(map,xkecoa(map),ykecoa(map),xplayer(map),yplayer(map));
    }
    //Nyawa player akan berkurang/tetap susai fungsi damage kecoa
    healthPlayer=damageKecoa(xkecoa(map),ykecoa(map),xplayer(map),yplayer(map),healthPlayer);
    baruSpawnKecoa=0;
    if (healthPlayer==0) //jika payaer mati (nyawa player==0), maka program akan selesai dan menampilkan tulisan dibawah ini ke layar
    {
        system("cls");
        peta(map);
        printf("------Control------\n");
        printf("   (w)     (e) - Shoot\n");
        printf("(a)   (d)  \n");
        printf("   (s)     (q) - Quit\n");
        printf("Range: %d\n",jarakKecoa(xplayer(map), yplayer(map), xkecoa(map),ykecoa(map)));
        printf("Nyawa Kecoa: %d\n",healthKecoa);
        printf("Jumlah Kill: %d\n",kill);
        printf("Nyawa User : %d\n",healthPlayer);
        printf("-----You  Died-----");
        quit=1;
    }
    }
}