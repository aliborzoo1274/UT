#include <stdio.h>

struct student {
	int grade;
	char name[20];
};

typedef struct student std;
typedef int color;


int main()
{
	char names[][20] = { "Golzari", "Hadian","Blookazari" };
	std blookazari;
	std students[100];
	color g;
	int size = sizeof(std);

	for (int i = 0; i < 3; i++) {
	//	scanf("%d", &(students[i].grade));
	//	scanf("%s", students[i].name);
		students[i].grade = 10 + i;
		for (int j = 0; j < 20 && names[i][j] !='\0'; j++) {
			students[i].name[j] = names[i][j];
			if (names[i][j] == '\0')
				break;
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("%d ", students[i].grade);
		printf("%s\n", students[i].name);

	}

	scanf("%d", &(blookazari.grade));
	scanf("%s", blookazari.name);
	printf("student name %s and grade %d", blookazari.name, blookazari.grade);
}

/*
int main() 
{
	int x;
	char c;
	float f;
	long float lf;

	int grade[100];
	char name[100][20];

	for (int i = 0; i < 3; i++) {
		scanf("%d ", &grade[i]);
		scanf("%s", &name[i][0]);
	}
		
	




}*/