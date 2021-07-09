#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[50];
    int student_id;
    int day;
    int month;
    int year;
    int score;
    struct student*next;
};
