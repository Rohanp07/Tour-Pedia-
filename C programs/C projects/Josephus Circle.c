#include<stdio.h>
#include<stdlib.h>
void killNode();
struct node
{
    int val;
    struct node* next;
};

struct node* start;
struct node* last;
struct node* current;



//function for creating a node
void insert(int N)
{

    struct node* temp;
    temp=(struct node*) malloc(sizeof(struct node*));
    temp->val= N;

    if (start==NULL)
    {
        start=temp;
        start->next=start;
        last=start;
        return;
    }

    else
    {
        if (start->next==start) //if only 1 node is existing
        {
            start->next=temp;
            temp->next=start;
            last=temp;
            return;
        }

        else
        {
            last->next=temp;
            temp->next=start;
            last=temp;
        }
    }



}

void display()
{

    current=start;
    printf("\nLIST : ");
    if(start==NULL)
    {
        printf("EMPTY.");
        return;
    }

    do
    {
        printf("%d ",current->val);
        if (current->next==start)
            {
                printf("\n\n");
                return;
            }
        current=current->next;

    }while(current->next!=start);

    printf("%d \n\n",current->val);



}

void killNode()
{
    current=start;
    struct node* now;

    if (start==NULL)
    {
        printf("EMPTY LIST!");
        return;

    }

    while(1)
    {
        if (current->next==start)    //for a new start (if now/current is the end node)
        {
            start=current;
            continue;
        }

        now=current;
        now->next=(now->next)->next; //node skip or kill
        current=current->next;

        if ((current->next)->next==current)  //if there are only 2 nums
        {
            current->next=start;
            printf("%d is the survivor.\n",current->val);
            return;
        }

    }
}

void getNum()
{
    int N,i=0;
    start=NULL;
    printf("Number of people present in the circle : ");
    scanf("%d",&N);

    while(i<N)
    {
        insert(i+1);
        i++;
    }


    printf("\nLIST CREATED !\n");
    display();
    killNode();
}

void main()
{
    start=NULL;
    last=NULL;

    do
    {
        getNum();
        printf("\n\n");

    }while(current->val!=999);
}
