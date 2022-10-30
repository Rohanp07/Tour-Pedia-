#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


///IN THIS GRAPH YOU CAN ADD MAX 3 EDGES
struct node
{
    struct node* ptr[3];
    struct node* next;
    int val,f;

};

struct node* createNode()
{
    struct node* temp;
    temp =((struct node*) malloc(sizeof(struct node)));
    temp->next=NULL;
    temp->f=1;
    temp->ptr[0]=NULL;
    temp->ptr[1]=NULL;
    temp->ptr[2]=NULL;
    return temp;
}


struct node* start;
struct node* Q[20]={0};
struct node* Stack[20]={0};

void insertV()
{
    struct node* temp;
    temp = createNode();
    printf("\nEnter value: ");
    scanf(" %d",&temp->val);

    if(start==NULL)
    {
        start=temp;
        return;
    }
    else
    {
        struct node* current=start;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=temp;
    }
}

void insertE()
{
    int a,b;
    struct node* current;
    struct node* A;
    struct node* B;
    printf("\nInsert edge relation (x to y): \n");
    scanf("%d",&a);
    scanf("%d",&b);

    current=start;
    while(current->val!=a)
    {
        if(current==NULL)
            return;
        current=current->next;
    }

    A=current;
    current=start;
    while(current->val!=b)
    {
        if(current==NULL)
            return;
        current=current->next;
    }

    int i;
    for(i=0;i<3;i++)
    {
        if(A->ptr[i]==NULL)
            {
                A->ptr[i]=current;
                return;
            }
    }

}

//******TRAVERSAL********

void bfs()
{
    int n,i,j,k;
    printf("Enter start point: ");
    scanf("%d",&n);
    struct node* c;
    c=start;

    while(c->val!=n)
    {
        c=c->next;
    }
    i=0;j=0;k=1;
    Q[0]=c;
    Q[0]->f=0;
    printf("BFS : %d ",Q[0]->val);
    while(Q[i]!=0)
    {
        //insert into queue(i loop)
        for(j=0;j<3;j++)
        {
            if(Q[i]->ptr[j]!=NULL)
            {
                if(Q[i]->ptr[j]->f!=0)
                {
                    Q[k]=Q[i]->ptr[j];
                    Q[k]->f=0;
                    printf("%d ",Q[k]->val);
                    k++;
                }
            }
        }
        i++;

    }

    for(i=0;i<20;i++)
    {
        Q[i]->f=1;
        Q[i]=0;
    }
}
struct node* DFSTraverse(struct node* V)
{
    if(V==NULL)
        return 0;
    if(V->f!=0)
    {
        printf("%d ",V->val);
        V->f=0;
    }
    else
        return 0;

    DFSTraverse(V->ptr[0]);
    DFSTraverse(V->ptr[1]);
    DFSTraverse(V->ptr[2]);
}


void dfs()
{
    int n;
    printf("Enter start point: ");
    scanf("%d",&n);
    struct node* c;
    c=start;
    while(c->val!=n)
        c=c->next;
    printf("DFS Traversal: ");
    DFSTraverse(c);
}



void menu()
{
    printf("\n+==========================+\n");
    printf("| *** GRAPH TRAVERSAL ***  |");
    printf("\n+==========================+\n");
    printf("| 1. Add Vertices.         |\n");
    printf("| 2. Add Edges.            |\n");
    printf("| 3. BFS Traversal.        |\n");
    printf("| 4. DFS Traversal         |\n");
    printf("+==========================+\n\n");
    printf("CHOICE: ");
}


int choice(int ch)
{
    switch(ch)
    {
        case 1: insertV();
                return 1;
        case 2: insertE();
                return 1;
        case 3: bfs();
                return 1;
        case 4: dfs();
                return 1;

        default: return 1;

    }
}

//function for option for repeating the same operation
int yesNo()
{
    char a;
    printf("\nDo you want to do the same operation again?[Y/N] ... ");
    a=getche();
    if (a == 'y' || a == 'Y')
    {
        return 1;
    }
    else
        return 0;
}

void main()
{
    start=NULL;

    int a, flag,c, ch;
    a = 1; c=0;

    //loop for taking continuous user input
    while (a)
    {
        flag = 1;
        menu();
        scanf(" %d", &ch);
        if (start == NULL && ch > 1)
        {
            printf("EMPTY TREE !!!\nFirst add some elements.\n");
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
        c=0;
    }
}
