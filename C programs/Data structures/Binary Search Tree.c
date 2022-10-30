#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//in this BTS the smaller number will be at left and greater at right w.r.t it's parent
struct node
{
    struct node* left;
    int val;
    struct node* right;
};


struct node* root;
struct node* current;
int cntN,leaf;

void countN(struct node* ptr)
{
    if(ptr==NULL)
        return;
    cntN++;
    countN(ptr->left);
    countN(ptr->right);
}


void countLeaf(struct node* ptr)
{
    if(ptr==NULL)
        return;

    if(ptr->left==NULL && ptr->right==NULL)
        leaf++;

    countLeaf(ptr->left);
    countLeaf(ptr->right);
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



struct node* createNode()
{
    struct node* ptr;
    ptr= (struct node*) malloc(sizeof(struct node));
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

void menu()
{
    printf("\n+==========================+\n");
    printf("| ***BINARY SEARCH TREE*** |");
    printf("\n+==========================+\n");
    printf("| 1. Insertion.            |\n");
    printf("| 2. Deletion.             |\n");
    printf("| 3. Search.               |\n");
    printf("| 4. Finding Depth / Height|\n");
    printf("| 5. Traversal display.    |\n");
    printf("| 6. Counting of nodes.    |\n");
    printf("| 7. Counting of leaf.     |\n");
    printf("| 8. Find Min / Max.       |\n");
    printf("| 9. Display.              |\n");
    printf("| 10.Mirror Image of Tree. |\n");
    printf("| 11.Delete Entire Tree.   |\n");
    printf("+==========================+\n\n");
    printf("CHOICE: ");
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

struct node* parent(struct node* i)
{
    struct node* ptr;
    ptr=root;
    while(1)
    {
        if(ptr->left->val==i->val || ptr->right->val==i->val)
        {
            return ptr;
        }

        if(ptr->val<i->val)
            ptr=ptr->right;

        else ptr=ptr->left;
    }
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

}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(struct node* ptr, int val)
{
    // base case
    if (ptr == NULL) return ptr;

    if (val < ptr->val)
        ptr->left = deleteNode(ptr->left, val);

    else if (val > root->val)
        ptr->right = deleteNode(ptr->right, val);

    else
    {
        if (ptr->left == NULL)
        {
            struct node *temp = ptr->right;
            free(ptr);
            return temp;
        }
        else if (ptr->right == NULL)
        {
            struct node *temp = ptr->left;
            free(ptr);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(ptr ->right);

        // Copy the inorder successor's content to this node
        ptr->val = temp->val;

        // Delete the inorder successor
        ptr->right = deleteNode(ptr->right, temp->val);
    }
    return ptr;
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



void del()
{
    display();
    int n;
    printf("ENTER A NUMBER TO DELETE: ");
    scanf("%d",&n);
    deleteNode(root,n);
    display();
}

void minMax()
{
    current=root;

    while(current->left!=NULL)
        current=current->left;
    printf("%d is the lowest node in the tree.\n",current->val);
    current=root;


    while(current->right!=NULL)
        current=current->right;

    printf("%d is the highest node in the tree.",current->val);
}


void inorder(struct node* ptr)
{
    if(ptr==NULL)
        return;

    inorder(ptr->left);
    printf("%d ",ptr->val);
    inorder(ptr->right);
}

void preorder(struct node* ptr)
{
    if(ptr==NULL)
        return;
    printf("%d ",ptr->val);
    preorder(ptr->left);
    preorder(ptr->right);
}

void postorder(struct node* ptr)
{
    if(ptr==NULL)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ",ptr->val);
}

void travDisplay()
{
    printf("\nINORDER   : ");
    inorder(root);
    printf("\n\nPREORDER  : ");
    preorder(root);
    printf("\n\nPOSTORDER : ");
    postorder(root);
    printf("\n");
}
struct node* mirror(struct node* ptr)
{
    if(ptr==NULL)
        return 0;

    struct node* temp;
    mirror(ptr->left);

    //swap pointers
    temp=ptr->right;
    ptr->right=ptr->left;
    ptr->left=temp;

    mirror(ptr->left);

}


struct node* deleteTree(struct node* ptr)
{
    if(ptr==NULL)
        return 0;

    ptr->left=deleteTree(ptr->left);
    ptr->right=deleteTree(ptr->right);
    free(ptr);
    return NULL;
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

//function for choice
int choice(int ch)
{
    int d;
    switch (ch)
    {
        case 1: insert();
                return 1;


        case 2: del();
                return 1;


        case 3: search(0);
                return 1;


        case 4: d=maxDepth(root);
                printf("%d is the max depth of the tree.",d-1);
                return 1;


        case 5: travDisplay();
                display();
                return 1;


        case 6: cntN =0;
                countN(root);
                printf("\nThere are total %d nodes in the tree.",cntN);
                return 1;


        case 7: leaf=0;
                countLeaf(root);
                printf("There are total %d leaf nodes.",leaf);
                return 1;


        case 8: minMax();
                return 1;


        case 9: display();
                return 1;

        case 10:printf("BEFORE MIRROR :\n\n");
                display();
                printf("\nAFTER MIRROR :\n\n");
                mirror(root);
                display();
                return 1;
        case 11: deleteTree(root);
                printf("TREE HAS BEEN DELETED !!! ");
                return 1;

        default:printf("INVALID CHOICE !!!\n");
                return 1;

    }
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
