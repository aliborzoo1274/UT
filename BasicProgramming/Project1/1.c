#include <stdio.h>
int main()
{
    int width;             /*عرض شیشه*/
    int flyPos;            /*موقعیت اولیه مگس روی محور ایکس*/
    float posChange;       /*میزان تغییر موقعیت مگس بعد از هر برخورد*/
    int numberOfsmash = 0; /*تعداد برخورد*/
    scanf("%d %d %f", &width, &flyPos, &posChange);
    float distance = width - flyPos; /*فاصله مگس تا لبه شیشه*/
    while (distance > 0)
    {
        distance -= posChange;
        numberOfsmash++;
    }
    printf("%d", numberOfsmash);
    return 0;
}