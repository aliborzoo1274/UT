#include <stdio.h>
int main() {

int numOf500f;      /*مقدار 500 تومانی اولیه*/
int numOf1000f;     /*مقدار 1000 تومانی اولیه*/
int numOf2000f;     /*مقدار 2000 تومانی اولیه*/
int numOf5000f;     /*مقدار 5000 تومانی اولیه*/
int numOf10000f;    /*مقدار 10000 تومانی اولیه*/
int numOf50000f;    /*مقدار 50000 تومانی اولیه*/
int numOfproducts;  /*تعداد کالاها*/
int p;              /*قیمت کالا*/
scanf("%d %d %d %d %d %d", &numOf500f, &numOf1000f, &numOf2000f, &numOf5000f, &numOf10000f, &numOf50000f);
scanf("%d", &numOfproducts);
for(int i=1;i<=numOfproducts;i++){      /*حلقه به تعداد کالا وارد شده تکرار میشود*/
int numOfRequired50000=0;    /*مقدار 50000 تومانی مورد نیاز*/
int numOfRequired10000=0;    /*مقدار 10000 تومانی مورد نیاز*/
int numOfRequired5000=0;     /*مقدار 5000 تومانی مورد نیاز*/
int numOfRequired2000=0;     /*مقدار 2000 تومانی مورد نیاز*/
int numOfRequired1000=0;     /*مقدار 1000 تومانی مورد نیاز*/
int numOfRequired500=0;      /*مقدار 500 تومانی مورد نیاز*/
        scanf("%d", &p);
    if (numOf500f*500 + numOf1000f*1000 + numOf2000f*2000 + numOf5000f*5000 + numOf10000f*10000 + numOf50000f*50000 >= p){       
        while (p>=50000 && numOf50000f>0){
                numOf50000f--;
                numOfRequired50000++;
                p-=50000;
            }
        while (p>=10000 && numOf10000f>0){
                numOf10000f--;
                numOfRequired10000++;
                p-=10000;
            }
        while (p>=5000 && numOf5000f>0){
                numOf5000f--;
                numOfRequired5000++;
                p-=5000;
            }
        while (p>=2000 && numOf2000f>0){
                numOf2000f--;
                numOfRequired2000++;
                p-=2000;
            }
        while (p>=1000 && numOf1000f>0){
                numOf1000f--;
                numOfRequired1000++;
                p-=1000;
            }
        while (p>=500 && numOf500f>0){
                numOf500f--;
                numOfRequired500++;
                p-=500;
            }
            if (p==0){
                printf("%d %d %d %d %d %d\n", numOfRequired500, numOfRequired1000, numOfRequired2000, numOfRequired5000, numOfRequired10000, numOfRequired50000);
            }
            else {
                printf("Not Enough Money\n");
            }}
        else {
            printf("Not Enough Money\n");
        }        
        }
    return 0;
}