#include<iostream>
using namespace std;

class myClass
{
public:

    string num;
    int a[100]={0},sizeA=0;

    void vertical(int line,int num)
    {
        //print line

        if (line==1 && num!=1 && num!=4)
        {
            cout<<" -- ";
        }
        else
        {
            if(line==1)
            {
                cout<<"    ";
            }
        }

        if (line==2 && num>=2 && num!=1 && num!=7 && num!=0)
        {
            cout<<" -- ";
        }
        else
        {
            if(line==2)
            {
                cout<<"    ";
            }
        }

        if (line==3 && num!=1 && num!=4 && num!=7)
        {
            cout<<" -- ";
        }
        else
        {
            if(line==3)
            {
                cout<<"    ";
            }
        }

    }

    void horizontal(int location,int num)
    {


        if (location==1 && num!=1 && num!=2 && num!=3 && num!=7 )
        {
            cout<<"|  ";

            if(num==4 || num==8 || num==0 || num==9)
            {
                cout<<"|";
            }
            else
            {
                cout<<" ";
            }

            return;
        }
        else
        {
            //this means the num is 1,2,3 or 7
            if (location==1)
            {
                cout<<"   |";
                return;
            }

        }

        if (location==2 && num!=1 && num!=4 && num!=3 && num!=5 && num!=7 && num!=9 )
        {

            cout<<"|  ";

            if (num==6 || num==8 || num==0)
                cout<<"|";

            else
            {
                cout<<" ";
            }
        }
        else
        {
            cout<<"   |";
        }


    }

    void input()
    {
        cout<<"ENTER NUMBER : ";
        cin>>num;
        convert();

    }

    void convert()
    {
        int temp,i=0;

        for (i=0;num[i]!='\0';i++)
        {
            a[i]=num[i]-48;
            sizeA++;
        }
    }


    void display()
    {
        int i,j;

         for (i=0;i<sizeA;i++)
        {
            vertical(1,a[i]);
            cout<<" ";
        }

        cout<<"\n";
        for (i=0;i<sizeA;i++)
        {
            horizontal(1,a[i]);
            cout<<" ";
        }

        cout<<"\n";
        for (i=0;i<sizeA;i++)
        {
            horizontal(1,a[i]);
            cout<<" ";
        }

        cout<<"\n";
        for (i=0;i<sizeA;i++)
        {
            vertical(2,a[i]);
            cout<<" ";
        }

        cout<<"\n";
        for (i=0;i<sizeA;i++)
        {
            horizontal(2,a[i]);
            cout<<" ";
        }

        cout<<"\n";
        for (i=0;i<sizeA;i++)
        {
            horizontal(2,a[i]);
            cout<<" ";
        }
        cout<<"\n";

        for (i=0;i<sizeA;i++)
        {
            vertical(3,a[i]);
            cout<<" ";
        }


    }

};


int main()
{
    myClass obj;
    obj.input();
    obj.display();
}
