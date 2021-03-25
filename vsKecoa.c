/*
Nama    :Bryan Bernigen
NIM     :16520237
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include <math.h>

//Fungsi Player
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
    gerakan=_getch();
    switch (gerakan)
    {
    case 'w':
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
    case 'a':
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
    case 's':
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
    case 'd':
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
    case 'e':
    {
        return 2;
    }
    case 'q':
        {
        return 0;
        }
    default:
        return 1;
    }
}
int shoot(int map[10][10], int jarak, int healthKecoa)
{
    if (jarak<=3)
    {
        return healthKecoa-1;
    }
    else
    {
        return healthKecoa+1;
    }
    
}

//Fungsi Kecoa
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
int spawnKecoa(int map[10][10],int xplayer, int yplayer)
{
    int xkecoa, ykecoa, ulang=1;
    while (ulang==1)
    {
    xkecoa=rand()%10;
    ykecoa=rand()%10;
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
    map[ykecoa][xkecoa]=2;
}
int jarakKecoa(int xplayer, int yplayer, int xkecoa, int ykecoa)
{
    return abs((xkecoa-xplayer))+abs(ykecoa-yplayer);
}
int moveKecoa(int map[10][10],int xkecoa, int ykecoa, int xplayer, int yplayer)
{
    int randomMove;
    randomMove=rand()%4;
    switch (randomMove)
    {
    case 0:
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
    case 1:
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
    case 2:
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
    case 3:
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
int damageKecoa(int xkecoa,int ykecoa, int xplayer, int yplayer, int healthPlayer)
{
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

















int main()
{
    int map[10][10]={0},quit=0,healthKecoa=3,kill, healthPlayer=3;
    srand(time(NULL));
    map[0][0]=1;
    kill=0;
    spawnKecoa(map,xplayer(map),yplayer(map));
    while (quit==0)//quit - 1, shoot - 2
    {
    switch (gerak(map,xplayer(map),yplayer(map),xkecoa(map),ykecoa(map),jarakKecoa(xplayer(map),yplayer(map),xkecoa(map),ykecoa(map)),healthKecoa,kill,healthPlayer))
    {
    case 0:
        quit=1;
        break;
    case 2:
        healthKecoa=shoot(map,jarakKecoa(xplayer(map),yplayer(map),xkecoa(map),ykecoa(map)),healthKecoa);
        if (healthKecoa==0)
        {
            map[ykecoa(map)][xkecoa(map)]=0;
            kill++;
            healthKecoa=3;
            spawnKecoa(map,xplayer(map),yplayer(map));
            break;
        }
        quit=0;
        break;
    case 1:
    {
        quit=0;
        break;
    }
    default:
        quit=0;
        break;
    }
    moveKecoa(map,xkecoa(map),ykecoa(map),xplayer(map),yplayer(map));
    healthPlayer=damageKecoa(xkecoa(map),ykecoa(map),xplayer(map),yplayer(map),healthPlayer);
    if (healthPlayer==0)
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