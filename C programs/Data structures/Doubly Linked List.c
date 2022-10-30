#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct node
{
    int val;
    struct node* next;
    struct node* prev;
};

struct node* start;
struct node* current;

//global temp and new list pointers for switching lists
struct node* List1;
struct node* List2;


//global int counter for counting nodes
int cntN = 0;
int NodeNum,uniFlag;
//function for storing the value of start pointers
//and selecting lists
int switchlist()
{
    int ch;

    printf("\nSELECT LIST -> List 1 or List 2 (enter 1 or 2)... ");
    scanf(" %d",&ch);
    if (ch==1)
    {
        start=List1;
        return 1;
    }
    if(ch==2)
    {
        start=List2;
        return 2;
    }

    printf("INVALID LIST NUMBER. ENTER 1 or 2.\n\n");
    return 0;
}


///function for creating a new node
struct node *createNode()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(temp));
    temp->next = NULL;
    temp->prev = NULL;
    //returning new node's address
    return temp;
}


void countN()
{
    struct node *temp;
    temp=start;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    cntN=i;
}


struct node* traverseByVal()
{
    NodeNum=0;
    uniFlag=1;
    current=start;
    if (start==NULL)
    {
        printf("EMPTY LIST.");
        return NULL;
    }
    int a,i;
    printf("\nENTER THE VALUE TO BE SEARCHED : ");
    scanf("%d",&a);
    NodeNum++;
    while(current->next!=NULL && current->val!=a)
    {
        NodeNum++;
        current=current->next;
    }

    //last node to be checked
    if (current->val==a)
    {
        return current;
    }
    else
    {
        uniFlag=0;
        printf("NUMBER NOT FOUND !");
        return NULL;
    }
}


struct node* traverseByPos(int a)
{
    int i;
    current =start;
    if (start==NULL)
    {
        printf("EMPTY LIST !");
    }
    else
    {
        for (i=0;i<a-2;++i)
        {
            current=current->next;
        }
        return current;
    }


};

void InbyVal()
{
    struct node* temp;
    struct node* newNode;
    newNode=createNode();

    do
    {
        temp=traverseByVal();
    }while(temp==NULL);

    int a=0,z;
    do
    {
        printf("\n1. Insert before.");
        printf("\n2. Insert after.");
        printf("\nCHOICE : ");
        scanf("%d",&a);
    }while(a!=1 && a!=2);

    printf("ENTER A NUMBER : ");
    scanf("%d",&newNode->val);

    if(a==1)
    {
        if(temp==start)
        {
            newNode->next=start;
            start->prev=newNode;
            start=newNode;
            return;
        }
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev=newNode;
        return;
    }
    else
    {
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        return;
    }



}


void InbyPos()
{
    struct node * temp;
    int a;
    countN();
    printf("ENTER NODE NUMBER (valid from 1 to %d) : ",cntN+1);
    scanf("%d",&a);

    struct node* newNode;
    newNode=createNode();
    printf("ENTER A NUM : ");
    scanf("%d",&newNode->val);

    //if node is to be inserted at first position
    if (a==1)
    {
       newNode->next=start;
       start->prev=newNode;
       start=newNode;
    }
    else
    temp=traverseByPos(a);

    //returning previous node
    if (temp->next!=NULL)
        temp->next->prev=newNode;

    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;

    return;
}



//INSERT FUNCTION
void insert()
{
    if (start==NULL)
    {
        start=createNode();
        printf("\nENTER A NUMBER : ");
        scanf("%d",&start->val);
        return;
    }
    int ch;
    printf("\n1. INSERT BY VALUE.\n");
    printf("2. INSERT BY POSITION.\n");
    printf("CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: InbyVal();
                break;
        case 2: InbyPos();
                break;
        default :printf("INVALID INPUT !");
                return;
    }

}

//function for deleting node by val
void DelbyVal()
{
    struct node* temp;
    do
    {
        temp=traverseByVal();
    }while(temp==NULL);

    printf("\n%d DELETED from the list.",temp->val);
    if (temp==start)
    {
        if(start->next==NULL)
            start=NULL;

        else
        {
            start=start->next;
        }
        return;
    }
    temp->prev->next=temp->next;
    if (temp->next==NULL)
    {
        free(temp);
        return;
    }
    temp->next->prev=temp->prev;
    free(temp);
    return;
}

//for deleting node by position
void DelbyPos()
{
    struct node* temp;
    int a;
    countN();
    printf("ENTER NODE NUMBER (valid from 1 to %d) : ",cntN);
    scanf("%d",&a);


    //if node is to be deleted at first position
    if (a==1)
    {
        printf("%d DELETED from the list.\n",start->val);
        start=start->next;
        if(start!=NULL)
        start->prev=NULL;
        return;
    }

    temp=traverseByPos(a);
    printf("%d is DELETED from the list.\n",temp->next->val);
    if (temp->next->next==NULL)
    {
        temp->next=NULL;
        return;
    }

    temp->next=temp->next->next;
    temp->next->prev=temp;



}

//delete function
void del()
{
        if (start==NULL)
    {
        start=createNode();
        printf("\nENTER A NUMBER : ");
        scanf("%d",&start->val);
        return;
    }
    int ch;
    printf("\n1. DELETE BY VALUE.\n");
    printf("2. DELETE BY POSITION.\n");
    printf("CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: DelbyVal();
                break;
        case 2: DelbyPos();
                break;
        default :printf("INVALID INPUT !");
                return;
    }
}

void UpbyVal()
{
    struct node* temp;
    temp=traverseByVal();
    printf("\nEnter new value : ");
    scanf("%d",&temp->val);
    return;

}
void UpbyPos()
{
    struct node* temp;
    int a;
    countN();
    printf("ENTER NODE NUMBER (valid from 1 to %d) : ",cntN);
    scanf("%d",&a);
    printf("\nEnter new value : ");

    //if node is to be deleted at first position
    if (a==1)
    {
        scanf("%d",&start->val);
        return;
    }

    temp=traverseByPos(a);
    temp=temp->next;
    scanf("%d",&temp->val);

}

void update()
{

    int ch;
    printf("\n1. UPDATE BY VALUE.\n");
    printf("2. UPDATE BY POSITION.\n");
    printf("CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: UpbyVal();
                break;
        case 2: UpbyPos();
                break;
        default :printf("INVALID INPUT !");
            return;
    }
}


//function for displaying the list
struct node *display(struct node* l)
{

    if (l == NULL)
    {
        printf("EMPTY !\n");
        return 0;
    }
    struct node *current;
    current = l;
    while (current!= NULL)
    {
        printf("%d ", current->val);
        if (current->next != NULL)
        {
            printf("-> ");
            //setting the last node pointer value

        }
        current = current->next;
    }
    printf("\n");

}

void search()
{
    traverseByVal();
    if (uniFlag==1)
    {
        printf("The node is found at position : %d\n",NodeNum);
        return;
    }
}

void reverse()
{
    current=start;
    struct node* temp;
    printf("LIST BEFORE REVERSE : ");
    display(start);

    while(1)
    {
        //for the last node of the list (to make it head)
        if (current->next==NULL)
        {
            start=current;
            current->next=current->prev;
            current->prev=NULL;
            break;
        }

        //swapping prev and next pointers of each node.
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;

        current=temp;
    }
    printf("\nLIST AFTER REVERSE  : ");
    display(start);

}

void setPrev()
{
    current=start;
    start->prev=NULL;
    while(current!=NULL)
    {
        if(current->next!=NULL)
            current->next->prev=current;
        current=current->next;
    }

}

void sort ()
{
    current=start;
    struct node* temp;
    struct node* newS;
    struct node* last;
    struct node* lowest;
    newS=NULL;

    while(start->next!=NULL)
    {
        temp=start;
        lowest=start;
        while(temp!=NULL)
        {
            if(lowest->val>temp->val)
                lowest=temp;

            temp=temp->next;
        }
        if(temp==start)
            start=start->next;

        //remove lowest from the list
        if(lowest->next!=NULL)
            lowest->next->prev=lowest->prev;

        if(lowest->prev!=NULL)
            lowest->prev->next=lowest->next;


        //add to newlist
        if(newS==NULL)
        {
            newS=lowest;
            last=newS;
        }
        else
        {
            last->next=lowest;
            last=last->next;
        }
    }

    last->next=start;
    start=newS;
    setPrev();
    printf("SORTED LIST : ");
    display(start);
}




//function for merging two sorted linked lists
void merge()
{
    //start pointer for new merged LL
    struct node* mStart;

    struct node* newNode;

    //Pointers for traversing 3 lists
    struct node* L1;
    struct node* L2;
    struct node* mCurrent;

    mStart=NULL;
    L1=List1;
    L2=List2;

    while (L1!=NULL && L2!=NULL)
    {
        mCurrent=mStart;

        if (L1->val<L2->val)
        {
            newNode=createNode();
            newNode->val=L1->val;
            if (mStart==NULL)
            {
                mStart=newNode;
                L1=L1->next;

            }
            else
            {
                while(mCurrent->next!=NULL)
                    mCurrent=mCurrent->next;

                mCurrent->next=newNode;
                L1=L1->next;
            }

        }
        else
        {
            newNode=createNode();
            newNode->val=L2->val;
            if (mStart==NULL)
            {
                mStart=newNode;
                L2=L2->next;
            }
            else
            {
                while(mCurrent->next!=NULL)
                    mCurrent=mCurrent->next;

                mCurrent->next=newNode;
                L2=L2->next;

            }

        }
    }
    if(L1== NULL && L2==NULL)
    {
        printf("Merged list : ");
        display(mStart);
        return;
    }
    mCurrent=mStart;
    if (L1==NULL)
    {
        while(L2!=NULL)
        {
            newNode=createNode();
            newNode->val=L2->val;
            while (mCurrent->next!=NULL)
                mCurrent=mCurrent->next;

            mCurrent->next=newNode;
            L2=L2->next;
        }

    }
    else
    {
        while(L1!=NULL)
        {
            newNode=createNode();
            newNode->val=L1->val;
            while (mCurrent->next!=NULL)
                mCurrent=mCurrent->next;

            mCurrent->next=newNode;
            L1=L1->next;
        }
    }
    printf("Merged LIST : ");
    setPrev();
    display(mStart);
    return;

}


//function for option for repeating the same operation
int yesNo()
{
    char a;
    printf("\nDo you want to do the same operation again?(y/n) ... ");
    a=getche();
    if (a == 'y' || a == 'Y')
    {
        return 1;
    }
    else
        return 0;
}



//DISPLAY FUNCTION
void display_both()
{
    printf("-------------------------------------------------------------");
    printf("\nList 1: ");
    display(List1);
    printf("-------------------------------------------------------------");
    printf("\nList 2: ");
    display(List2);
    printf("-------------------------------------------------------------\n\n");
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


        case 4: search();
                return 1;


        case 5: reverse();
                return 1;


        case 6: countN();
                printf("\nNumber of Nodes : %d",cntN);
                return 1;

        case 7: display_both();
                return 1;


        case 8: sort();
                return 1;


        case 9: merge();
                return 1;

        case 10: return 0;


        default:printf("INVALID CHOICE !!!\n");
                return 1;

    }
}



//function for displaying options
void options()
{
    printf("\n+--------------------------+");
    printf("\n|****DOUBLY LINKED LIST****|\n");
    printf("+--------------------------+\n");
    printf("| 1. Insert.               |\n");
    printf("| 2. Delete.               |\n");
    printf("| 3. Update.               |\n");
    printf("| 4. Search.               |\n");
    printf("| 5. Reverse.              |\n");
    printf("| 6. Count Nodes.          |\n");
    printf("| 7. Display.              |\n");
    printf("| 8. Sort.                 |\n");
    printf("| 9. Merge.                |\n");
    printf("| 10. Exit.                |\n");
    printf("+--------------------------+\n\n");
    display_both();
    printf("CHOICE: ");
}




int main()
{
    int a, flag,c, ch;
    a = 1; c=0;
    start = NULL;
    List1 = NULL;
    List2 = NULL;
    //loop for taking continuous user input
    while (a)
    {
        while(!c)
            c=switchlist();

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
            printf("\nLIST : ");
            display(start);
        }
        if (c==1)
            List1=start;

        else List2=start;

        c=0;
    }
    return 0;
}
