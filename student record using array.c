#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[30];
    int *marks; 
    int totalMarks;
};

struct student students[5]; 
int i, j, numSubjects;

void ask() {
    for (i = 0; i < 5; i++) {
        printf("\nEnter %dth student record\n", i + 1);
        printf("Student name: ");
        scanf("%s", students[i].name);
        
        printf("Enter number of subjects: ");
        scanf("%d", &numSubjects);
        
        
        students[i].marks = (int *)malloc(numSubjects * sizeof(int));
        
        
        for (j = 0; j < numSubjects; j++) {
            printf("Enter marks for subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
        
       
        students[i].totalMarks = 0;
        for (j = 0; j < numSubjects; j++) {
            students[i].totalMarks += students[i].marks[j];
        }
    }

    
    printf("\nDisplaying Student records\n");
    for (i = 0; i < 5; i++) {
        printf("\nStudent name: %s", students[i].name);
        printf("\nMarks: ");
        for (j = 0; j < numSubjects; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nTotal Marks: %d", students[i].totalMarks);
    }

   
    int maxMarksIndex = 0;
    for (i = 1; i < 5; i++) {
        if (students[i].totalMarks > students[maxMarksIndex].totalMarks) {
            maxMarksIndex = i;
        }
    }

    
    printf("\nStudent with the highest total marks:\n");
    printf("Student name: %s\n", students[maxMarksIndex].name);
    printf("Total Marks: %d\n", students[maxMarksIndex].totalMarks);

    
    for (i = 0; i < 5; i++) {
        free(students[i].marks);
    }
}

void main() {
    ask();
}