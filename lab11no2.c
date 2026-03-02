#include <stdio.h>
#include <stdlib.h>

#define NO_SCORE 5
#define NO_STD 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;
void writeStudentToFile();
void readAndProcessData();
float findAverage(Student s);
void findLessThanTen(Student s);

int main() {

    writeStudentToFile();


    readAndProcessData();

    return 0;
}

void writeStudentToFile() {
    FILE *fptr;
    Student std;
    int i, j;


    fptr = fopen(".\\lab11\\no2\\std10.dat", "w"); 
    if (fptr == NULL) {
        printf("Error: Cannot create file.\n");
        exit(1);
    }

    for (i = 0; i < NO_STD; i++) {
        printf("Enter data for student %d\n", i + 1);
        printf("\tName : "); scanf("%s", std.name);
        printf("\tSurname : "); scanf("%s", std.surname);
        

        fprintf(fptr, "%s %s", std.name, std.surname);
        
        for (j = 0; j < NO_SCORE; j++) {
            printf("\tScore %d : ", j + 1);
            scanf("%d", &std.score[j]);

            fprintf(fptr, " %d", std.score[j]);
        }fprintf(fptr, "\n");

        printf("---------------------------\n");
    }
    fclose(fptr);
    printf("\nSaved\n");
}

void readAndProcessData() {
    FILE *fptr;
    Student std;
    int i;
    float avg;


    fptr = fopen(".\\lab11\\no2\\std10.dat", "r");
    if (fptr == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
while (fscanf(fptr, "%s %s", std.name, std.surname) != EOF) {
        

        std.total = 0;
        for (i = 0; i < NO_SCORE; i++) {
            fscanf(fptr, "%d", &std.score[i]);
            std.total += std.score[i];
        }

   
        avg = findAverage(std);

        printf("\nStudent: %s %s", std.name, std.surname);
        printf("\n  - Total Score: %.2f", std.total);
        printf("\n  - Average Score: %.2f", avg);

        
        findLessThanTen(std);
        printf("\n-------------------------------");
    }

    fclose(fptr);
}

float findAverage(Student s) {
    return (s.total / NO_SCORE);
}

void findLessThanTen(Student s) {
    int i, count = 0;
    printf("\n  - Scores less than 10:");
    for (i = 0; i < NO_SCORE; i++) {
        if (s.score[i] < 10) {
            printf("\n\tTest #%d: %d", i + 1, s.score[i]);
            count++;
        }
    }
    if (count == 0) printf(" None");
}
