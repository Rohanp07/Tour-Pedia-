#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

//declared global start and last node pointers
struct node *start;

//global int counter for counting nodes
int cntN = 0;

void countN()
{
    struct node *current;
    current = start;
    int i = 0;
    if (start == NULL)
    {
        cntN = 0;
        return;
    }
    while (current->next != start)
    {
        i++;
        current = current->next;
    }
    i++;
    cntN = i;
}
//function for displaying the list

void display()
{
    struct node *current;
    current = start;
    printf("\n------------------------------------------------------------------\n");
    printf("LIST : ");
    if (start == NULL)
    {
        printf("EMPTY.");
        return;
    }

    while (current->next != start)
    {
        printf(" %d ", current->val);
        if (current->next != start)
        {
            printf("-> ");
        }
        current = current->next;

    }
    printf(" %d ", current->val);
    printf("\n------------------------------------------------------------------\n");

}

//function for option for repeating the same operation
int yesNo()
{
    char a;
    printf("\nDo you want to do the same operation again?(y/n) ... ");
    scanf(" %c", &a);
    if (a == 'y' || a == 'Y')
    {
        return 1;
    }
    else
        return 0;
}

///function for creating a new node
struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(temp));
    temp->next = start;
    //returning new node's address
    return temp;
}

///Search function which is used for 5 other functions
struct node *search(int Ch)
{
    struct node *current;
    current = start;
    int a=0;
    //only to get last node
    if (Ch == 0)
    {

        while (current->next != start)
        {
            current = current->next;
        }
        return current;
    }
        //before
        current=start;
        if (Ch)
        {
            int n;
            while(1)
            {
                a=0;
                a++;
                current=start;
                printf("ENTER NUMBER TO BE SEARCHED : ");
                scanf("%d", &n);
                if (start->val == n)
                {
                    if (Ch==3)
                    {
                        printf("%d is found at node number %d\n",current->val,a);
                    }
                    return start;
                }
                while (1)
                {

                    if (current->next == start)
                       {
                           printf("ENTER A VALID NUMBER !\n\n");
                           break;
                       }
                    a++;
                    if (current->next->val == n)
                    {
                        if (Ch==2)
                        {
                            current =current->next;
                        }
                        if (Ch==3)
                        {
                            printf("%d is found at node number %d.\n\n",current->next->val,a);
                        }
                        return current;
                    }

                    current=current->next;
                }

            }

        }
}



//function for inserting by position
void insertBy_pos()
{
    int n,i;
    countN();
    do
    {
        printf("ENTER NUMBER OF NODE ON WHICH YOU WANT TO INSERT.\n");
        printf("(VALID FROM 1 to %d)\n->",cntN+1);
        scanf("%d",&n);

        if (n>=1 || n<=cntN+1)
        {
            break;
        }
        printf("INVALID POSITION CHOSEN !");

    }while(1);

    struct node* temp;
    temp=createNode();
    printf("\nENTER A NUMBER -> ");
    scanf("%d",&temp->val);
    struct node* ptrAtVal;
    ptrAtVal=start;
    if (n==1)
    {
        temp->next=start;
        while(ptrAtVal->next!=start)
            ptrAtVal=ptrAtVal->next;
        ptrAtVal->next=temp;
        start=temp;
        return;
    }
    else
    {
        if (n==cntN+1)
        {
            while(ptrAtVal->next!=start)
                ptrAtVal=ptrAtVal->next;
            ptrAtVal->next=temp;
            return;
        }
        else
        {
            for (i=0;i>n-2;i++)
            {
                ptrAtVal=ptrAtVal->next;
            }
            temp->next=ptrAtVal->next;
            ptrAtVal->next=temp;
            return;

        }
    }
}

void insert()
{
    struct node *newNode;

    /*if the list is not been created*/
    if (start == NULL)
    {
        start = createNode();
        start->next=start;
        printf("Enter a number : ");
        scanf("%d", &start->val);
        return;
    }
    //if list is existing
    else
    {
        struct node *temp;
        struct node* current;
        current=start;
        int ch;
        printf("\n\nYou have these options to insert:\n");
        printf("1. Insert at last.\n");
        printf("2. Insert before a node.\n");
        printf("3. Insert after a node.\n");
        printf("4. Insert by position.\n\n");
        printf("\nChoice: ");
        scanf(" %d", &ch);
        switch (ch)
        {
            case 1: temp = search(0);
                    newNode=createNode();
                    printf("ENTER A NUM : ");
                    scanf("%d", &newNode->val);
                    temp->next=newNode;
                    return;

            //before a val insertion
            case 2: temp = search(1);
                    newNode=createNode();
                    printf("ENTER A NUM : ");
                    scanf("%d", &newNode->val);
                    if(temp==start)
                    {
                        newNode->next=start;
                        //update start for the last node
                        while(current->next!=start)
                            current=current->next;
                        start=newNode;
                        current->next=start;
                    }
                    else
                    {
                        newNode->next=temp->next;
                        temp->next=newNode;
                    }
                    return;

            case 3: temp = search(2);
                    newNode=createNode();
                    printf("ENTER A NUM : ");
                    scanf("%d", &newNode->val);
                    temp->next=newNode;
                    return;

            case 4: insertBy_pos();
                    return;



        }
    }
}

//update by value
void uptPOS()
{
    struct node* temp;
    temp=start;
    int n,i;
    countN();
    do
    {
        printf("ENTER NUMBER OF NODE ON WHICH YOU WANT TO UPDATE.\n");
        printf("(VALID FROM 1 to %d)\n->",cntN);
        scanf("%d",&n);
        if (n>=1 || n<=cntN)
        {
            break;
        }
        printf("INVALID POSITION CHOSEN !\n\n");

    }while(1);

    for (i=0;i<n-1;i++)
    {
        temp=temp->next;
    }
    printf("ENTER THE NUMBER : ");
    scanf("%d",&temp->val);
    return;


}

//function to edit any node
void update()
{
    int ch;
    printf("\n\nYou have these options to update:\n");
    printf("1. UPADTE BY VALUE.\n");
    printf("2. UPDATE BY POSITION.\n");
    printf("\nChoice: ");
    scanf("%d", &ch);
    struct node* temp;
    switch (ch)
    {
        case 1: temp=search(2);
                printf("UPDATE THE NUMBER : ");
                scanf("%d",&temp->val);
                return;

        case 2: uptPOS();
                return;
    }


}

//delete by position function
void delPOS()
{
    struct node* temp;
    temp=start;
    int n,i;
    struct node* last;
    last=search(0);
    countN();
    do
    {
        printf("ENTER NUMBER OF NODE ON WHICH YOU WANT TO DELETE.\n");
        printf("(VALID FROM 1 to %d)\n->",cntN);
        scanf("%d",&n);
        if (n>=1 || n<=cntN)
        {
            break;
        }
        printf("INVALID POSITION CHOSEN !\n\n");

    }while(1);

    for (i=0;i<n-2;i++)
    {
        temp=temp->next;
    }

    if (temp==start)
    {
        printf("\n%d is been deleted successfully !\n",start->val);
        if (start->next==start)
        {
            start==NULL;
            return;
        }
        start=start->next;
        //last node-> next updated
        last->next=start;
        return;
    }

    else
    {
        printf("\n%d is been deleted successfully !\n",temp->next->val);
        temp->next=(temp->next)->next;
        return;
    }

}

void delVAL()
{
    struct node* temp;
    struct node* last;
    temp=search(1);
    last=search(0);

    if (temp==start)
    {
        printf("\n%d is been deleted successfully !\n",start->val);
        if (start->next==start)
        {
            start==NULL;
            return;
        }
        start=start->next;
        //last node-> next updated
        last->next=start;
        return;
    }
    else
    {
        printf("\n%d is been deleted successfully !\n",temp->val);
        temp->next=(temp->next)->next;
        return;
    }

}
//Delete function
void del()
{
    //if list is empty return
    if (start == NULL)
    {
        printf("NOTHING TO DELETE, EMPTY LIST !!!\n");
        return;
    }
    int ch;
    printf("\n1. Delete by value.");
    printf("\n2. Delete by position.\n\n");
    printf("CHOICE: ");
    scanf("%d",&ch);


    switch (ch)
    {
        case 1: delVAL();
                return;

        case 2: delPOS();
                return;
    }
}

//function for displaying options
void options()
{
    printf("\n****CIRCULAR LINKED LIST****\n\n");
    printf("1. Insert.                 |\n");
    printf("2. Delete.                 |\n");
    printf("3. Update.                 |\n");
    printf("4. Search.                 |\n");
    printf("5. Count Nodes.            |\n");
    printf("6. Display.                |\n");
    printf("7. Exit.                   |\n");
    printf("----------------------------\n\n");
    printf("CHOICE: ");
}

//function for choice
int choice(int ch)
{
    switch (ch)
    {
    case 1: insert();
            return 1;


    case 2: del();
            return 1;


    case 3: update();
            return 1;


    case 4: search(3);
            return 1;


    case 5: countN();
            printf("\nNumber of Nodes : %d", cntN);
            return 1;


    case 6: display();
            return 1;


    case 7: return 0;


    default: printf("INVALID CHOICE !!!\n");
                return 1;

    }
}

int main()
{
    int a, flag, ch;
    a = 1;
    start = NULL;
    //loop for taking continuous user input
    while (a)
    {
        flag = 1;
        options();
        scanf(" %d", &ch);
        if (start == NULL && ch > 1)
        {
            printf("EMPTY list !!!\nFirst add some elements.\n");
            continue;
        }
        a = choice(ch);
        while (flag)
        {
            flag = yesNo();
            if (flag == 1)
            {
                a = choice(ch);
            }
        }
        display();
    }
    return 0;
}
