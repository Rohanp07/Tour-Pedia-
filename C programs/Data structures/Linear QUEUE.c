#include<stdio.h>

    int queue_array[3]={0};
    int rear=-1,myfront=0;

    void Enqueue ()
    {   int num=0;

            printf("\nEnter a number to insert: ");
            scanf("%d",&num);
            rear++;
            queue_array[rear]=num;
    }

    void Dequeue()
    {   int i=0,flag=0;
        while(i!=3)
        {
            if(queue_array[i]!=0)
            {
                printf("%d <-is REMOVED.",queue_array[i]);
                queue_array[i]=0;
                myfront++;
                flag=1;
                break;
            }

            i++;

        }
        if(flag==0)
        {
            printf("No elements in the array to Dequeue !!!");
        }

    }


    void ShowFront()
    {
        printf("\nYour front is: %d",queue_array[myfront]);
    }


    void Size()
    {
        int ele;
        int i;
        for (i=0;i<3;i++)
        {
            if(queue_array[i]!=0)
            ele++;
        }
        printf("The queue size is: %d",ele);
    }
    void Display()
    {
        int i,flag=0;
        printf("\n");
        for (i=0;i<3;i++)
        {
            if(queue_array[i]!=0)
            {
                printf("%d  ",queue_array[i]);
                flag=1;
            }

        }

        if (flag==0)
        printf("EMPTY QUEUE!!!\nPlease insert some elements.\n");
    }
    int operations()
    {   printf("\nFRONT: %d.\tREAR:%d ",myfront,rear);
        int choice;
        printf("\nWhat do you want to do ?\n");
        printf("1. Enqueue.\n");
        printf("2. Dequeue.\n");
        printf("3. ShowFront.\n");
        printf("4. Display Size.\n");
        printf("5. Display Queue.\n");
        printf("6. EXIT. \n\n");
        printf("Your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: if (rear==2)
                    {
                        printf("Queue overloaded !");
                        return 0;
                        break;
                    }
                    Enqueue();
                    Display();
                    return 0;
                    break;

            case 2: Dequeue();
                    return 0;
                    break;

            case 3: ShowFront();
                    return 0;
                    break;

            case 4: Size();
                    return 0;
                    break;

            case 5: printf("Queue is: ");
                    Display();
                    return 0;
                    break;

            case 6: break;

            default: printf("INVALID OPTION");return 0;
                     break;


        }
        return 1;

    }




int main()
{
    printf("***QUEUE***");

    int a ;
    while(a!=1)
    {
      a= operations();
    }

}

