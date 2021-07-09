#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[50];
    int student_id;
    int day, month, year;
    int score;
    struct student*next;
};

struct student*head;
int L=0;
int number;
void insert ()
{
    char choice ;
label_1 :
    printf("#######################################################################\n");
    printf("press 1 if you need to insert in the begin \npress 2 if you need to insert in the end \npress 3 if you need to insert with index\npress 4 if you need to display the data\npress 5 if you need to finish insertion\n");
    printf("#######################################################################\n");
    scanf("%s",&choice);
    if ((choice != '1')&&(choice != '2')&&(choice != '3')&&(choice != '4')&&(choice != '5'))
    {
        printf("your choice is not valid please enter correct number\n");
        goto label_1 ;
    }

    switch (choice )
    {

    case '1' :
    {
        struct student* Node1 =NULL ;
        Node1 =  (struct student*) malloc(sizeof(struct student));
        printf("#######################################################################\n");
        printf("please insert the data of student \n");
        printf("enter the name of the student\n");
        scanf("%s",Node1->name);
        printf("enter the ID of the student\n");
        scanf("%d",&(Node1->student_id));
        printf("enter the birth date of the student\n ");
        printf("enter the day\n");
        scanf("%d",&(Node1->day));
        printf("enter the month\n");
        scanf("%d",&(Node1->month));
        printf("enter the year\n");
        scanf("%d",&(Node1->year));
        printf("enter the score of the previous year\n");
        scanf("%d",&(Node1->score));
        Node1->next = head ;
        head =Node1;
        printf("#######################################################################\n");
        printf("Inserted successfully\n");
        L++;
        goto label_1 ;
    }
    case '2':
    {
        struct student* Node2 =NULL ;
        Node2 =  (struct student*) malloc(sizeof(struct student));
        struct student*temp ;
        printf("#######################################################################\n");
        printf("please insert the data of student\n");
        printf("enter the name of the student\n");
        scanf("%s",Node2->name);
        printf("enter the ID of the student\n");
        scanf("%d",&(Node2->student_id));
        printf("enter the birth date of the student\n ");
        printf("enter the day\n");
        scanf("%d",&(Node2->day));
        printf("enter the month\n");
        scanf("%d",&(Node2->month));
        printf("enter the year\n");
        scanf("%d",&(Node2->year));
        printf("enter the score of the previous year\n");
        scanf("%d",&(Node2->score));
        temp=head;
        while (temp->next != NULL)
        {
            temp=temp->next ;
        }
        temp->next=Node2 ;
        Node2->next=NULL;
         printf("#######################################################################\n");
        printf("Inserted successfully\n");
        L++;
        goto label_1 ;
    }
    case '3':
    {
        struct student* Node3 =NULL ;
        Node3 =  (struct student*) malloc(sizeof(struct student));
        struct student* temp ;
        printf("#######################################################################\n");
        printf("Enter the index of the new student\n");
        int index;
        scanf("%d",&index);
        printf("#######################################################################\n");
        if(index==0)
        {
            printf("THAT INDEX IS AT BEGIN SO PLEASE GO TO INSERT IN THE BEGIN \n");
            goto label_1;
        }
        else if (index==L)
        {
            printf("THAT INDEX IS AT END SO PLEASE GO TO INSERT IN THE END \n");
            goto label_1;
        }
        else if(index<L && index>0)
        {
            printf("please insert the data of student \n");
            printf("enter the name of the student\n");
            scanf("%s",Node3->name);
            printf("enter the ID of the student\n");
            scanf("%d",&(Node3->student_id));
            printf("enter the birth date of the student\n ");
            printf("enter the day\n");
            scanf("%d",&(Node3->day));
            printf("enter the month\n");
            scanf("%d",&(Node3->month));
            printf("enter the year\n");
            scanf("%d",&(Node3->year));
            printf("enter the score of the previous year\n");
            scanf("%d",&(Node3->score));
            printf("#######################################################################\n");
            temp=head ;
            for (int i =0; i<index-1; i++)
            {
                temp=temp->next ;
            }
            Node3->next= temp->next ;
            temp->next = Node3;
        }
        else
        {
            printf("THAT INDEX IS out of range of linked list \n");
            goto label_1 ;
        }

        goto label_1 ;
    }
    case '5' :
    {
         printf("#######################################################################\n");
        return;
    }
    case '4' :
        {
            printf("#######################################################################\n");
            display();
            goto label_1 ;
        }
    }
}
void display ()
{
    int i =0;
    struct student* temp ;
    temp = head ;
    while (temp != NULL )
    {
        printf("The Name of student %d : %s  \n",i, temp->name) ;
        printf("The ID of student %d : %d  \n",i, temp->student_id) ;
        printf("The Birth Date of student %d : %d / %d  / %d  \n",i, temp->day,temp->month,temp->year) ;
        printf("The Previous Year Score of student %d : %d  \n",i, temp->score) ;
        printf("#######################################################################\n");
        temp=temp->next;
        i++;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_at_begin_oflinkedlist()
{
    struct student*node = NULL;
    node=(struct student*)malloc(sizeof(struct student));
    printf("#######################################################################\n");
    printf("Insert data for the student \n");
    printf("enter the name of the student\n");
    scanf("%s",(node->  name));
    printf("enter the student_ID\n");
    scanf("%d",(&node->  student_id));
    printf("enter the birth date\n");
    printf("enter day \n");
    scanf("%d",(&node->day));
    printf("enter month \n");
    scanf("%d",(&node->month));
    printf("enter year \n");
    scanf("%d",(&node->  year));
    printf("enter the previous year score \n");
    scanf("%d",(&node-> score));
    printf("#######################################################################\n");
    node->next=head;
    head=node;
    L++;
}
void add_at_end_oflinkedlist()
{
    struct student*node2 = NULL;
    struct student*tmp = NULL;
    node2=(struct student*)malloc(sizeof(struct student));
    printf("enter the name of the student\n");
    scanf("%s",(node2->  name));
    printf("enter the student_ID\n");
    scanf("%d",(&node2->  student_id));
    printf("enter the birth date\n");
    printf("enter day \n");
    scanf("%d",(&node2->day));
    printf("enter month \n");
    scanf("%d",(&node2->month));
    printf("enter year \n");
    scanf("%d",(&node2->  year));
    printf("enter the previous year score \n");
    scanf("%d",(&node2-> score));
    printf("#######################################################################\n");
    tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=node2;
    node2->next=NULL;
    L++;
}
void create_linkedlist ()
{
    printf("Enter number of students\n");
    scanf("%d",&number);
    add_at_begin_oflinkedlist();
    for(int k=1; k<number; k++)
    {
        printf("Insert data for the student #%d\n",k+1);

        add_at_end_oflinkedlist();
    }
    printf("Linked List Is Created Successfully\n");
    printf("#######################################################################\n");
}












/////////////////////////////////array code///////////////////////////////////////////////////
void insertinbegin();
void insertinend();
void insertinmiddle();


void insertinbegin (int noofstudents, struct student *stdp){



    printf("This function makes you insert new student in the beginning :) ... \n \n");


    /* insert a new student */

        for (int i = noofstudents-1; i >= 0; i--){
             strcpy(stdp[i+1].name, stdp[i].name);
             stdp[i+1].student_id  = stdp[i].student_id;
             stdp[i+1].day  = stdp[i].day;
             stdp[i+1].month  = stdp[i].month;
             stdp[i+1].year  = stdp[i].year;
             stdp[i+1].score  = stdp[i].score;

        }
         /*details of a new student */

        printf("\nEnter details of the new student \n\n");

        printf("Enter name: ");
        scanf("%s", stdp->name);

        printf("Enter student id: ");
        scanf("%d", &stdp->student_id);

        printf("Enter day: ");
        scanf("%d", &stdp->day);

        printf("Enter month: ");
        scanf("%d", &stdp->month);

        printf("Enter year: ");
        scanf("%d", &stdp->year);

        printf("Enter score: ");
        scanf("%d", &stdp->score);

        /* printing the new dynamic array */

    for (int i = 0; i < noofstudents ; i++) {
        printf("\nDetail of student %d",i+1);
        printf("\t student name: %s", stdp[i].name);
        printf("\t Student id: %d", stdp[i].student_id);
        printf("\t Day: %d", stdp[i].day);
        printf("\tMonth: %d", stdp[i].month);
        printf("\tYear: %d", stdp[i].year);
        printf("\tScore: %d", stdp[i].score);
  }

    }
/*function to Insert a new student in the end*/
void insertinend (int noofstudents, struct student *stdp){
    printf("This function makes you insert new student in the end :) ... \n \n");

        printf("\nEnter details of the new student \n\n");

        printf("Enter name: ");
        scanf("%s", (stdp+noofstudents-1)->name);

        printf("Enter student id: ");
        scanf("%d", &(stdp+noofstudents-1)->student_id);

        printf("Enter day: ");
        scanf("%d", &(stdp+noofstudents-1)->day);

        printf("Enter month: ");
        scanf("%d", &(stdp+noofstudents-1)->month);

        printf("Enter year: ");
        scanf("%d", &(stdp+noofstudents-1)->year);

        printf("Enter score: ");
        scanf("%d", &(stdp+noofstudents-1)->score);


          for (int i = 0; i < noofstudents ; i++) {
        printf("\nDetail of student %d",i+1);
        printf("\t student name: %s", stdp[i].name);
        printf("\t Student id: %d", stdp[i].student_id);
        printf("\t Day: %d", stdp[i].day);
        printf("\tMonth: %d", stdp[i].month);
        printf("\tYear: %d", stdp[i].year);
        printf("\tScore: %d", stdp[i].score);
  }

    }
/*function to Insert a new student in the middle*/
void insertinmiddle (int noofstudents, struct student *stdp){
    printf("This function makes you insert new student in the middle :) ... \n \n");

    printf("Enter the index which you need to insert to : ");
    int index;
    scanf("%d", &index);

    while (index+1 >= noofstudents || index == 0){
    printf("Enter the correct index which you need to insert to : ");
    scanf("%d", &index);
    }
    /*insert a new student and copying the students in static array to dynamic array*/
    /*details of a new student */
        for (int i = noofstudents-index-1; i >= 0 ; i--){
            strcpy(stdp[index+i+1].name, stdp[index+i].name);
             stdp[index+i+1].student_id  = stdp[index+i].student_id;
             stdp[index+i+1].day  = stdp[index+i].day;
             stdp[index+i+1].month  = stdp[index+i].month;
             stdp[index+i+1].year  = stdp[index+i].year;
             stdp[index+i+1].score  = stdp[index+i].score;

        }
        printf("\nEnter details of the new student \n\n");

        printf("Enter name: ");
        scanf("%s", (stdp+index-1)->name);

        printf("Enter student id: ");
        scanf("%d", &(stdp+index-1)->student_id);

        printf("Enter day: ");
        scanf("%d", &(stdp+index-1)->day);

        printf("Enter month: ");
        scanf("%d", &(stdp+index-1)->month);

        printf("Enter year: ");
        scanf("%d", &(stdp+index-1)->year);

        printf("Enter score: ");
        scanf("%d", &(stdp+index-1)->score);



        for (int i = 0; i < noofstudents ; i++) {
        printf("\nDetail of student %d",i+1);
        printf("\t student name: %s", stdp[i].name);
        printf("\t Student id: %d", stdp[i].student_id);
        printf("\t Day: %d", stdp[i].day);
        printf("\tMonth: %d", stdp[i].month);
        printf("\tYear: %d", stdp[i].year);
        printf("\tScore: %d", stdp[i].score);
  }

    }








