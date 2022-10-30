#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


/*AVL tree*/

struct node
{
    struct node* left;
    int val;
    struct node* right;
};


struct node* root;
struct node* current;
int cntN;

struct node* createNode()
{
    struct node* ptr;
    ptr= (struct node*) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}


void countN(struct node* ptr)
{
    if(ptr==NULL)
        return;
    cntN++;
    countN(ptr->left);
    countN(ptr->right);
}



int maxDepth(struct node* ptr)
{
    if (ptr == NULL)
        return 0;
    else
    {

        int lDepth = maxDepth(ptr->left);
        int rDepth = maxDepth(ptr->right);


        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}





struct node* Q[100]={0};

void fill()
{

    int i=0,tmp;

    Q[0]=root;

    //loop for filling the queue
    while(i<100)
    {
        if(Q[i]!=0)
            Q[2*i+1]=Q[i]->left;

        if(Q[i]!=0)
            Q[2*i+2]=Q[i]->right;

        i++;

    }
    i=0;


}

int twopwr(int n)
{
    int i,tmp=1;
    for (i=0;i<n;i++)
        tmp=tmp*2;
    return tmp;
}

void display()
{
    fill();

    int i,j,k,D,t,n,ctr;
    D= maxDepth(root);
    printf("\nTREE(DEPTH %d) :\n",D-1);
    t=twopwr(D);
    n=0;ctr=0;

    //switching lines
    for(k=0;k<D;k++)
    {
        //loop on the specific line
         for (i=0;i<twopwr(ctr);i++)
        {
            //pre number spaces
            for(j=0;j<t-1;j++)
                printf(" ");

            if(Q[n]!=NULL)
            {
                printf("%d",Q[n]->val);
            }
            else printf("*");
            n++;

            //post number spaces
            for(j=0;j<t;j++)
                printf(" ");


        }
        t=t/2;
        ctr++;
        for(j=0;j<D-k;j++)
            printf("\n");
    }



    for(i=0;i<100;i++)
        Q[i]=NULL;

}



struct node* findParent(int n)
{
    current=root;

    if(n==root->val)
        return root;

    while(1)
    {
        if(current->right!=NULL)
        {
            if(current->right->val==n)
            {
                return current;
            }
        }

        if(current->left!=NULL)
        {
            if(current->left->val==n)
            {
                return current;
            }
        }

        if(current->val>n)
            current=current->left;
        else current=current->right;


    }
}



void insert()
{
    struct node* newNode;
    newNode=createNode();
    printf("\nENTER A NUMBER : ");
    scanf("%d",&newNode->val);

    if (root==NULL)
    {
        root=newNode;
        return;
    }

    current=root;

    while(1)
    {
        if(newNode->val>=current->val)
        {
            if(current->right==NULL)
            {
                current->right=newNode;
                //printf("%d is right child of %d.",newNode->val,current->val);
                break;
            }
            current=current->right;
        }
        else
        {
            if(newNode->val<=current->val)
            {

                if(current->left==NULL)
                {
                    current->left=newNode;
                    //printf("%d is left child of %d.",newNode->val,current->val);
                    break;
                }
                current=current->left;
            }
        }

    }
}



struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(int n)
{
    struct node* parent;
    struct node* ssor;
    struct node* t;
    struct node* ptrAtVal;
    struct node* temp;
    parent=findParent(n);
    int flag=0;

    if(parent->left!=NULL)
    {
        if(parent->left->val==n)
        {
            ptrAtVal=parent->left;
        }

    }
    if(parent->right!=NULL)
    {
        if(parent->right->val==n)
        {
            flag=1;
            ptrAtVal=parent->right;
        }
    }
    ssor =ptrAtVal;

    if(flag)
    {
        if(ptrAtVal->left==NULL)
        {
            parent->right=ptrAtVal->right;
            return 0;
        }

        ssor=ssor->left;
        while(ssor->right!=NULL)
            ssor=ssor->right;
        if(n==root->val)
        {
            root=ssor;
        }

        t=findParent(ssor->val);

        temp=ssor;
        ssor->right=ptrAtVal->right;

        parent->right=ssor;

        //***************
        if(temp->left==NULL)
        {
            ssor->left=ptrAtVal->left;
            t->right=NULL;
            return 0;
        }
        else
        {
            deleteNode(temp->val);
        }

    }
    else
    {
        if(ptrAtVal->right==NULL)
        {
            parent->left=ptrAtVal->left;
            return 0;
        }
        //finding predecessor of ptratval
        ssor=ssor->right;
        while(ssor->left!=NULL)
            ssor=ssor->left;
        if(n==root->val)
        {
            root=ssor;
        }

        t=findParent(ssor->val);

        parent->left=ssor;
        ssor->left=ptrAtVal->left;

        if(ssor->right==NULL)
        {
            ssor->right=ptrAtVal->right;
            t->left=NULL;
            return 0;
        }
        else deleteNode(ssor->val);

    }


}

void del()
{
    display();
    int n;
    struct node* p;
    p=root;
    printf("ENTER A NUMBER TO DELETE: ");
    scanf("%d",&n);
    deleteNode(n);
    display();
}








struct node* search(int a)
{
    int n,d,parent;
    current=root;
    printf("ENTER A NUMBER TO SEARCH : ");
    scanf("%d",&n);

    if (root->val==n)
    {
        if(a==1)
            return root;
        printf("%d is the root node.",n);
        return 0;
    }
    d=0;
    while(current->left!=NULL || current->right!=NULL)
    {
        parent=current->val;
        d++;
        if(current->val==n)
            break;

        if(current->val<n)
        {
            current=current->right;
            continue;
        }
        else
        {
            current=current->left;
        }
    }
    if(current->val==n)
    {
        if(a==1)
            return current;

        if(parent>n)
            printf("%d is LEFT CHILD of %d having DEPTH %d.\n",n,parent,d);

        else
            printf("%d is RIGHT CHILD of %d having DEPTH %d.\n",n,parent,d);
        return 0;
    }
   printf("NO NUMBER FOUND !!!\n");
   return 0;

}


int checkBF(struct node* ptr)
{
    current =ptr;
    int l=0,r=0,BF;
    while(current->left!=NULL)
    {
        l++;
        current=current->left;
    }
    current=ptr;
    while(current->right!=NULL)
    {
        r++;
        current=current->right;
    }

    BF=l-r;
    return BF;

}



void Leftrotate(struct node* ptr)
{
    struct node* t;
    struct node* l;
    if(ptr->right==NULL)
    {
        printf("RIGHT ROTATION CANNOT HAPPEN!!\n");
        return;
    }

    l=ptr->right;

    ptr->right= l->left;

    l->left=ptr;

    if(ptr==root)
        root=l;

    //setting parent
    else
    {
        printf("here");
        t=findParent(ptr->val);
        if(t->right==ptr)
        {
            t->right=l;
            return;
        }
        else
        {
            t->left=l;
        }

    }
}


void rightRotate(struct node* ptr)
{
    struct node* t;
    struct node* l;

    if(ptr->left==NULL)
    {
        printf("RIGHT ROTATION CANNOT HAPPEN!!\n");
        return;
    }

    /**********rotation code***********/
    l=ptr->left;

    ptr->left=l->right;

    l->right=ptr;

    if(ptr==root)
        root=l;
    //setting parent
    else
    {
        t=findParent(ptr->val);
        if(t->right==ptr)
        {
            t->right=l;
            return;
        }
        else
        {
            t->left=l;
        }
    }

    /***********************************/
}

struct node* Validitycheck(struct node* ptr)
{
    if(ptr==NULL)
        return 0;
    struct node* tmp;
    int BF;
    Validitycheck(ptr->left);
    Validitycheck(ptr->right);
    BF=checkBF(ptr);


    if(BF<-1)
    {
        Leftrotate(ptr);
    }
    if(BF>1)
    {
        rightRotate(ptr);
    }


}


//function for choice
int choice(int ch)
{
    int d;
    int a;
    switch (ch)
    {
        case 1: insert();
                Validitycheck(root);
                return 1;


        case 2: del();
                Validitycheck(root);
                return 1;


        case 3: search(0);
                return 1;


        case 4: d=maxDepth(root);
                printf("%d is the max depth of the tree.",d-1);
                return 1;



        case 5: cntN =0;
                countN(root);
                printf("\nThere are total %d nodes in the tree.",cntN);
                return 1;



        case 6: display();
                return 1;

        case 7: scanf("%d",&a);
                rightRotate(root);
                return 1;


        default:printf("INVALID CHOICE !!!\n");
                return 1;

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



void menu()
{
    printf("\n+==========================+\n");
    printf("|     *** AVL TREE ***     |");
    printf("\n+==========================+\n");
    printf("| 1. Insertion.            |\n");
    printf("| 2. Deletion.             |\n");
    printf("| 3. Search.               |\n");
    printf("| 4. Finding Depth / Height|\n");
    printf("| 5. Counting of nodes.    |\n");
    printf("| 6. Display.              |\n");
    printf("+==========================+\n\n");
    printf("CHOICE: ");
}






void main()
{
    int a, flag,c, ch;
    a = 1; c=0;

    //loop for taking continuous user input
    while (a)
    {
        flag = 1;
        menu();
        scanf(" %d", &ch);
        if (root == NULL && ch > 1)
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
        display();
        c=0;
    }

}
