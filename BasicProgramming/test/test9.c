#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int a=0;
    int i=0;
    int j=0;
    int arr [5][4];
    while (a<5){
        for(i=0;i<5;i++){
            for(j=0;j<4;j++){
                arr[i][j]=' ';
            }
        }
        arr[a][0]=arr[a][2]='[';
        arr[a][1]=arr[a][3]=']';
        for (i=0; i<5; i++){
            for(j=0; j<4; j++){
                if(arr [i][j]!= ']' && arr [i][j]!='['){
                    arr [i][j]= ' ';
                }
                printf("%c", arr[i][j]);
            }
                printf("\n");}
        a++;
        sleep(1);
        system("cls");
    }
    }