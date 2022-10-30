#include<stdio.h>
#include<GL/gl.h>
int disklocation[]={1,2,3,4,5};
int i;
int o,p; o=186;p=178;
void display_array()

{ int i;
    for (i=0;i<5;i++)
        printf("%d \t",disklocation[i]);
    printf("\n");
}



//IMP FUNCTION
void display()
{ int i=0;
int k;int c_d_l=0;
for(i=0;i<5;i++) //no of disks
  { printf("\n")

;   for (k=0;k<3;k++) //pegs
{ int j;
c_d_l=k*5+i+1;
int size; size_of_disk();
size = size_of_disk(c_d_l);
//printf("_%d _",size);
//printf("%d \n",c_d_l);
for(j=0;j< (9-size);j++ ) //blank spaces
    printf(" ");
for(j=0;j<= (size-1);j++ ) //half part of disk
    printf("%c",p);
printf("%c",o);
for(j=0;j<= (size-1);j++ )
    printf("%c",p);
    for(j=0;j< (9-size);j++ )
    printf(" ");
    //printf("%d",c_d_l);
printf("\t ");
}

printf("\n ");


 } }

int size_of_disk(int loc)
{ int i;
    for (i=0;i<5;i++)
 {
   if (disklocation[i]== loc )
     return i+1;

 }

 return 0;



}

/// is over
int is_over ()
{
    for(i=0;i<5;i++)

    {
        if(disklocation[i]=11+i)
        {
            return 0;

        }
    }
     return 1;



}

void main()
{ int i ,start,fl,tl, end,size,k,to_size,l;
int end_to,start_to;
int flag=1;int f2=1,f3=1;
do {
      //  f3= is_over();

//gameplay();

///Current disk location
display();
do{
do{
    printf("From which peg do you want to make a move :");
    scanf("%d",&fl);
    if(fl>=1 && fl<4)
       {flag=0;}
        else {flag=1;
            printf("Invalid Move ! \n");
            }

    }while(flag==1);

 do{
 printf("To which peg do you want to shift : ");
 scanf("%d",&tl);

 if(tl>=1 && tl<4)
       {flag=0;}
        else {flag=1;
            printf("Invalid Move ! \n");

 }} while(flag==1);


 if (tl==fl)
    {display();
 continue;}


start=(fl-1)*5+1;
end = start +5;
start_to=(tl-1)*5+1;
end_to=start_to +5;


for(i=0;i<5;i++)

{
    if ((disklocation[i]>=start) && (disklocation[i]<end))
{printf("%d \n",i);
    size=i;
    break;}


}
to_size=-1;
for (k=0;k<5;k++)
{
    if(disklocation[k]>=start_to && (disklocation[k]<end_to))

    {
        //printf("%d ")
        to_size =k;
        break;
    }


}
if (to_size==-1)
{

    to_size=end_to-1;
      disklocation[size]= to_size; }

else
{
    l=to_size;
    to_size=disklocation[to_size]-1;
}

//printf("%d \n",to_size);

//for (k=0;k<5;k++)
//    if(disklocation[k]!<=start_to && disklocation[k])

///SWAP NUMBER
if(size<l)
{f2=1;
  disklocation[size]= to_size; }
  else if (size==0)
    {f2=1;
  disklocation[size]= to_size; }
  else {f2=0;
  display();
  }
}while(f2==0);


//printf("%d \n",to_size);
//display_array();
}while (1);
printf("well played !!!");}
