#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void op(int y,int z,int i,int j,char a[][25],char b[][25]){
    if(y<0||y>=i||z<0||z>=j)
        return;
    if(b[y][z]!='X')
        return;
    if(a[y][z]=='@')
        return;
    b[y][z]=a[y][z];
    if(a[y][z]!='0')
        return;
    for(int k=-1;k<=1;k++)
        for(int l=-1;l<=1;l++)
            if(k!=0||l!=0)
                op(y+k,z+l,i,j,a,b);
}

int main(){
    srand(time(0));
    int i,j,k,s,t,x,f;
    scanf("%d",&k);
    if(k==1){
        i=9;
        j=9;
        f=10;
    }
    else if(k==2){
        i=16;
        j=16;
        f=70;
    }
    else if(k==3){
        i=25;
        j=25;
        f=110;
    }
    char a[25][25],b[25][25];
    for(s=0;s<i;s++){
        for(t=0;t<j;t++)
            b[s][t]='X';
    }

    if(k==1){
        for(s=0;s<i;s++)
            for(t=0;t<j;t++)
                a[s][t]='X';
        for(x=0;x<10;x++){
            s=rand()%i;
            t=rand()%j;
            while(a[s][t]=='@'){
                s=rand()%i;
                t=rand()%j;
            }
            a[s][t]='@';
        }
    }
    else if(k==2){
        for(s=0;s<i;s++)
            for(t=0;t<j;t++)
                a[s][t]='X';
        for(x=0;x<70;x++){
            s=rand()%i;
            t=rand()%j;
            while(a[s][t]=='@'){
                s=rand()%i;
                t=rand()%j;
            }
            a[s][t]='@';
        }
    }
    else if(k==3){
        for(s=0;s<i;s++)
            for(t=0;t<j;t++)
                a[s][t]='X';
        for(x=0;x<110;x++){
            s=rand()%i;
            t=rand()%j;
            while(a[s][t]=='@'){
                s=rand()%i;
                t=rand()%j;
            }
            a[s][t]='@';
        }
    }
int count=0;
for(s=0;s<i;s++){
    for(t=0;t<j;t++){
        if(a[s][t]=='@')
            continue;
        count=0;
        for(int n=-1;n<=1;n++){
            for(int m=-1;m<=1;m++){
                if(n==0&&m==0)
                    continue;
                int y=s+n;
                int z=t+m;
                if(y>=0&&y<i&&z>=0&&z<j){
                    if(a[y][z]=='@')
                        count++;
                }
            }
        }
        a[s][t]=count+'0';
    }
}

    printf("   ");
    for(t=1;t<j+1;t++)
        printf("%3d",t);
    printf("\n");
    for(s=0;s<i;s++){
        printf("%3d",s+1);
        for(t=0;t<j;t++)
            printf("%3c",b[s][t]);
        printf("\n");
    }

    int y,z;
    scanf("%d %d",&z,&y);
    while(y>i||y<=0||z>j||z<=0){
        printf("沒有這格\n");
        scanf("%d %d",&z,&y);
    }

    int un=0;
    while(a[y-1][z-1]!='@'){
        if(b[y-1][z-1]!='X'){
            printf("翻過了\n");
        }
        else{
            op(y-1,z-1,i,j,a,b);
            if(un==i*j-f){
                printf("你贏了!");
                return 0;
            }
        }
        printf("   ");
        for(t=1;t<j+1;t++)
            printf("%3d",t);
        printf("\n");
        for(s=0;s<i;s++){
            printf("%3d",s+1);
            for(t=0;t<j;t++)
                printf("%3c",b[s][t]);
            printf("\n");
        }
        scanf("%d %d",&z,&y);
    }
    if(a[y-1][z-1]=='@')
        printf("踩到地雷了!");
    return 0;
}
