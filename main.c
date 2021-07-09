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

int main()
{

    create_linkedlist();
    insert();
    //display ();

    return 0;
}
