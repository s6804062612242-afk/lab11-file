#include <stdio.h>
#define NO_SCORE 5
typedef struct {
char name[16];
char surname[20];
int score[NO_SCORE];
float total;
} Student;
int i;
void readStudentData(Student *);
void findTotalScore(Student *);
float findAverage(Student);
void findLessThanTen(Student);
void addRecordscore(Student *pStd);

int main() {
	Student std;
	float avg;
	readStudentData(&std);
	findTotalScore(&std);
	avg = findAverage(std);
	addRecord(&std);
	printf("\n\nAverage score is %.2f", avg);
	findLessThanTen(std);
}
void readStudentData(Student *pStd) {

printf("Enter student data\n");
printf("\tName : ");
scanf("%s", &pStd->name);
printf("\tSurname : ");
scanf("%s", &pStd->surname);
for (i=0; i<NO_SCORE; i++) {
printf("\tScore %d : ", i+1);
scanf("%d", &pStd->score[i]);
	addRecordscore(&pStd);
}
}
void findTotalScore(Student *pStd) {
int i;
printf("\n\nPrint student data");
printf("\n\t%s %s got score ", pStd->name, pStd->surname);
pStd->total = 0.0;
for (i=0; i<NO_SCORE; i++) {
printf("%6d", pStd->score[i]);
pStd->total += pStd->score[i];
}
printf("\n\tTotal score is %.2f", pStd->total);
}
float findAverage(Student s) {
return(s.total/NO_SCORE);
}
void findLessThanTen(Student s) {
int i,count=0;
printf("\n\nScore less than 10");
for (i=0; i<NO_SCORE; i++) {
if (s.score[i] < 10) {
printf("\n\tTest no.%d - %d", i+1, s.score[i]);
count++;
}
}
if (count==0) 
printf(" -> None");
}
//
void addRecord(Student *pStd) {
	FILE *fptr;
	fptr=fopen(".\\lab11\\no2\\std10.dat", "w");
	fprintf(fptr, "%s\t%s\t",pStd->name,pStd->surname);
	fclose(fptr);
}

void addRecordscore(Student *pStd) {
	FILE *fptr;
	fptr=fopen(".\\lab11\\no2\\std10.dat", "a");
	fprintf(fptr, "score:%d %d\n",i,pStd->score);
	fclose(fptr);
}
