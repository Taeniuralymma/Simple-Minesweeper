#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void skip(){
    system("cls");
}

void co(int a){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

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

int main1(){
    srand(time(0));
    int i,j,k,s,t,x,f;
    printf("簡單模式輸入1\n普通模式輸入2\n困難模式輸入3\n");
    scanf("%d",&k);
    while(k!=1&&k!=2&&k!=3){
        printf("輸入錯誤 請重新輸入");
        scanf("%d",&k);
    }
    if(k==1){
        i=9;
        j=9;
        f=10;
    }
    else if(k==2){
        i=16;
        j=16;
        f=40;
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
        for(x=0;x<0;x++){
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

    skip();
    printf("   ");
    for(t=1;t<j+1;t++)
        printf("%3d",t);
    printf("\n");
    for(s=0;s<i;s++){
        printf("%3d",s+1);
        for(t=0;t<j;t++){
            co(7);
            printf("%3c",b[s][t]);
        }
        printf("\n");
    }

    int y,z;
    printf("輸入要翻開的座標\n");
    scanf("%d %d",&z,&y);
    while(y>i||y<=0||z>j||z<=0){
        printf("沒有這格\n請重新輸入");
        scanf("%d %d",&z,&y);
    }

    int un;
    while(a[y-1][z-1]!='@'){
        if(b[y-1][z-1]!='X'){
            printf("翻過了\n");
        }
        else{
            op(y-1,z-1,i,j,a,b);
            for(s=0;s<i;s++){
                for(t=0;t<j;t++){
                    if(b[s][t]=='X')
                        un++;
                }
            }
            if(un==f){
                printf("你贏了!");
                return 0;
            }
            un=0;
        }
        skip();
        printf("   ");
        for(t=1;t<j+1;t++)
            printf("%3d",t);
        printf("\n");
        for(s=0;s<i;s++){
            printf("%3d",s+1);
            for(t=0;t<j;t++){
                if(b[s][t]=='X'){
                    co(7);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='0'){
                    co(8);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='1'){
                    co(1);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='2'){
                    co(2);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='3'){
                    co(4);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='4'){
                    co(3);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='5'){
                    co(6);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='6'){
                    co(5);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='7'){
                    co(9);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='8'){
                    co(11);
                    printf("%3c",b[s][t]);
                }
                else if(b[s][t]=='9'){
                    co(14);
                    printf("%3c",b[s][t]);
                }
                co(7);
            }
            printf("\n");
        }
        printf("輸入要翻開的座標\n");
        scanf("%d %d",&z,&y);
        while(y>i||y<=0||z>j||z<=0){
            printf("沒有這格\n請重新輸入");
            scanf("%d %d",&z,&y);
        }
    }
    if(a[y-1][z-1]=='@')
        printf("踩到地雷了!");
    return 0;
}

int main(){
    main1();
    printf("要再玩一次嗎\n要請輸入1\n不要請輸入其他數字\n");
    int a;
    scanf("%d",&a);
    if(a!=1){
        printf("感謝遊玩!");
        exit(0);
    }
    while(a==1){
        main();
    }
}
