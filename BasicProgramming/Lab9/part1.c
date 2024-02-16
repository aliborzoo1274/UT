#include <stdio.h>
#include <stdlib.h>
struct information
{
    float weight;
    float height;
};
typedef struct information inf;

int main()
{
    inf *person_ptr;
    person_ptr = (inf*)malloc(sizeof(inf));
    printf("Please enter weight : \n");
    scanf("%f", &person_ptr -> weight);
    printf("Please enter height : \n");
    scanf("%f", &person_ptr -> height);
    free (person_ptr);
    return 0;
}