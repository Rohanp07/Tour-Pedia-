
#include<iostream>
using namespace std;
struct node {

int val;
struct node *next;
struct node *prev;
};

class myList
{   struct node * start;

   public :

    Mylist ()
    {   start = new node ;
        start->val=0;
        start->next=NULL;
        start->prev=NULL;
    }

    int Add ()
    {   int new_num;
        printf("Enter a num : ");
        scanf("%d",&new_num);


           printf("here");

            printf("%0x  ",start->next);
         //   start-> next =NULL;
         //   start-> prev =NULL;
            start-> val= new_num;
            printf("%d  ",start->val);
            printf("%0x  ",start->next);
            return 0;

        if (start->val!=0)

        {   struct node* current =start;
            struct node* temp;
            temp=new node;
            temp->next=NULL;
            temp->prev=NULL;
            temp->val=new_num;
            while (new_num<((current->next)->val))
            {
             current =current->next;
            }
            temp->next=current->next;
            temp->prev=current;
            current->next=temp;
            ((temp->next)->prev)=temp;



        }


    }


int add()
{ int new_num; struct node *currentl=start;
  struct node *start;


    printf("Enter a num: ");
    scanf("%d",&new_num);



     if((*start).val==NULL)
     {(*start).val=new_num;

     }else{
            struct node *tmp= new node;
            (*tmp).val = new_num;
            (*tmp).next= NULL;
            (*tmp).prev=NULL;


        /**SPEcial CASE!!!!!! (to add new no. at first position)*/
          int temp;
        if((*currentl).val>new_num)
        {   currentl->prev=tmp;
            temp=(*currentl).val;
            (*tmp).next=(*currentl).next ;
            (*currentl).val=new_num;
            (*currentl).next=tmp;
            (*tmp).val= temp ;


        return 1;
        }


        /**OVER**/


         while((((*currentl).next)!=NULL) && new_num> (*(*currentl).next).val)
         {

            currentl=(*currentl).next;


        };
        ///if number is last
        if((*currentl).next==NULL){
         printf("%0x  %0x\n",currentl,tmp);
        (*currentl).next=tmp;
          tmp->prev =currentl;
          printf("%0x  %0x\n",currentl,tmp);
        }
        ///IF NUM IS MIDDLE ONE
        else
        {
            (*tmp).next=(*currentl).next;
            tmp->prev=currentl;
             (*currentl).next= tmp;
        }

}    return 1;
}


   void my_show()
{ int flag=0;
 struct node* current= start;

    if((current->val)!=NULL)
    {
        do{
        printf("%d  %0x",(*(current)).val,current);
        current=(*(current)).next;
        printf(" %0x\n",current);
        }while((current)!=NULL);
printf("\n");

    }else
    {
        printf("\nEMPTY LIST ! ! !\n");
    }
}





};


int main()
{   int c;

    myList one;

    while(c!=3)
    {
        printf("\n1 TO ADD.\n2 To Show.\n3 To Exit.\n");
        scanf("%d",&c);

        switch(c)
        {
            case 1 : c= one.add();
                     one.my_show();
                     break;

            case 2 : one.my_show ();break;

            case 3 : break;


        }

    }



}
