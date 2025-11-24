#include <stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct polys
{
    int size;
    node *poly;
    struct polys *next;
} polys;
typedef struct func
{
    float IP;
    float OP;
    struct func *next;
}func;
polys *lister();
node *LL(int*);
void cleanforce(polys*);
void clean(node*);
void cleanA(func*);
void displayforce(polys *);
void display(node *);
void editforce(polys*);
void edit(node*,int);
void selector(int, polys *);
//int NewtRap(polys*);
float reguFal(polys*);
float polyvalue(float,node*);
float reg(node*);
int countLL = 0, countlister = 0;
int main()
{
    int exitcase = 0, choice = 0;
    polys *ptr = 0;
    printf("enter the exitcase 1 to continue 0 to exit");
    scanf("%d", &exitcase);
    while (exitcase != 0)
    {
        ptr = lister();
        printf("\nEnter what operation to perform from the below options");
        printf("\n1.display\t2.solvforXNEWTRAP\t3.Edit\t4.SolveforXREGUFAL\t0.Exit");
        scanf("%d", &choice);
      while(choice!=0)
      {
        selector(choice, ptr);
        printf("\n1.display\t2.solvforXNEWTRAP\t3.Edit\t4.SolveforXREGUFAL\t0.Exit");
        scanf("%d",&choice);
      }
        cleanforce(ptr);
        printf("\nEnter the exitcase 1 to continue 0 to exit listing");
        scanf("%d", &exitcase);
    }
    printf("\n##### #   #     #    # #   #\t   #    # ##### #   #");
    printf("\n  #   #   #    ##   #  #  # \t    #  #  #   # #   #");
    printf("\n  #   #####   # # #    ##   \t     #    #   # #   #");
    printf("\n  #   #   #  #  ##     #  # \t     #    #   # #   #");
    printf("\n  #   #   # #   #      #   #\t     #    ##### #####");
}
node *LL(int *a)
{
    node *head = 0, *temp = 0, *newnode = 0;
    int exitcase = 1, countnode = 0;
    countLL++;
    printf("\nEnter elements for polynomial no %d of list %d", countLL, countlister);
    while (exitcase != 0)
    {
        newnode = (node *)malloc(sizeof(node));newnode->next = 0;
        printf("\nEnter the poly of degree %d", countnode);
        scanf("%d",&newnode->data);
        countnode++;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("\nEnter the exitcase 1 to continue 0 to exit");
        scanf("%d", &exitcase);
    }
    printf("\nListed poly %d in record",countLL);
    *a=countnode;
    return head;
}
polys *lister()
{
    int exitcase = 1;
    polys *listhead = 0, *list_traverser = 0, *list = 0;
    countlister++;
    while (exitcase != 0)
    {
        list = (polys *)malloc(sizeof(polys));
        list->next = 0;list->poly=0;list->size=0;
        if (listhead == 0)
        {
            listhead = list_traverser = list;
        }
        else
        {
            list_traverser->next = list;
            list_traverser = list;
        }
        list_traverser->poly = LL(&list->size);
        printf("\nEnter the exitcase 1 to continue 0 to exit");
        scanf("%d", &exitcase);
    }
    return listhead;
}
void selector(int a, polys *b)
{
    switch (a)
    {
    case 1: // display
        displayforce(b);
        break;
    /*case 2://solv for x
    NewtRap(b);
    break;*/
    case 3:
    editforce(b);
    break;
    case 4:
    reguFal(b);
    break;
    default:
        printf("\nInvalid choice");
        break;
    }
}
void display(node *ntraverser)
{
    int i=0;
    while (ntraverser != 0)
    {
        printf("%dx^%d+", ntraverser->data,i);
        ntraverser = ntraverser->next;
        i++;
    }
    printf("0=0\n");
}
void displayforce(polys *ptraverser)
{
    int polyno = 0,count=0;
    printf("\nEnter which poly you want to display out of %d polys listed(0 to display all)", countLL);
    scanf("%d", &polyno);
    if (polyno == 0)
    {
        while (ptraverser!=0)
        {
            count++;
            printf("\nPOLY %d is as follows",count);
            display(ptraverser->poly);
            ptraverser=ptraverser->next;
        }
    }
    else
    {
        int i=0;
        for(i=1;i<polyno;i++)
        {
            count++;
            ptraverser=ptraverser->next;
        }
        count++;
        printf("\nPOLY %d is as follows",count);
        display(ptraverser->poly);

    }
}
void clean(node *ntraverser)
{
    node *prev;
    while(ntraverser!=0)
    {
        prev=ntraverser;
        ntraverser=ntraverser->next;
        free(prev);
    }
    prev=0;
}
void cleanforce(polys* ptraverser)
{
    int i=0;
    polys* prev;
while(ptraverser!=0)
{
    i++;
    prev=ptraverser;
    clean(prev->poly);
    printf("\nCleaned polynomial %d",i);
    ptraverser=ptraverser->next;
    free(prev);
}
prev=0;
printf("Cleaned list %d",countlister);
}
void edit(node *ntraverser,int size)
{
    int edit_place=0;
printf("note that highest degree is %d and lowest is %d",size-1,0);
printf("\nEnter which at whitch degree to edit");
scanf("%d",&edit_place);//edit_place+=1;
if(edit_place>=size||edit_place<0)
{
printf("\nInvalid Choice\t\t--Redirected--");
}
else{
    //edit_place-=1;
/*while(edit_place!=1)
{
    ntraverser=ntraverser->next;
    edit_place--;
}*/
int i;
//i=size-1-edit_place;//i=size-(size-(size-(size-1-edit_place)));
//for(i=size-1-edit_place;i!=0;i--)
for(i=1;i<=edit_place;i++)
{
    ntraverser=ntraverser->next;
}
printf("\nEnter what to replace %d with",ntraverser->data);
scanf("%d",&ntraverser->data);
printf("\nEdit succesful");
}
}
void editforce(polys* ptraverser)
{
    polys *phead=ptraverser;
    int exitcase=1,edit_poly=0,choice=0;
    printf("\nEnter 1.EDit poly \t2.Edit Poly List(change poly completely)");
    scanf("%d",&choice);
    if(choice==1)
    {
    while(exitcase!=0)
    {
        printf("\nEnter which poly to operate on We have %d polys",countLL);
        scanf("%d",&edit_poly);
        while(edit_poly!=1)
        {
            ptraverser=ptraverser->next;
            edit_poly--;
        }
        edit(ptraverser->poly,ptraverser->size);
        printf("Exit Case 1 to continue 0 to exit");
        scanf("%d",&exitcase);
    }
    }
    else if(choice==2)
    {
        polys *prev=0;
        printf("ENter which poly to edit");
        scanf("%d",&edit_poly);
        if(edit_poly<=0||edit_poly>countLL)
        {
            printf("\nYOU FOOL poly %d does not exist",edit_poly);
        }
        else
        {
        while(edit_poly!=1)
        {
            prev=ptraverser;
            ptraverser=ptraverser->next;
            edit_poly--;
        }
        printf("ENter what to DO");
        printf("\n1.Remove it 2.Edit it completely(change size) 3.swap its position");
        scanf("%d",&choice);
        if(choice==1)
        {
           clean(ptraverser->poly);ptraverser->poly=0;
           if(ptraverser->next==0)
           {
            prev->next=0;
            free(ptraverser);
           }
           else
           {
           prev->next=ptraverser->next;
           free(ptraverser);
           }
        }
        else if(choice==2)
        {
            printf("\nUNDER CONSTRUCTION");
        }
        else if(choice==3)
        {
            node *ptr;
            printf("\nEnter which node to swap ITS position with");
            scanf("%d",&choice);
            if(choice>countLL||choice==0){printf("\nInvalid choice \tRedirected");}
            else
            {
                prev=ptraverser;
                //first take it to list head then use traversing again
                ptraverser=phead;
                while(choice!=1)
                {
                    ptraverser=ptraverser->next;
                    choice--;
                }
                ptr=ptraverser->poly;
                ptraverser->poly=prev->poly;
                prev->poly=ptr;
            }
        }
        else
        {
            printf("\nInvalid Choice---Redirected-");
        }
    }
    }
    else
    {
        printf("\nInvalid selection\t--REDIRECTED--");
    }
}
/*int NewtRap(polys* ptraverser)//on Hold
{
    int choice=0;
    printf("\nWe have %d polys listed",countLL);
    printf("\nEnter which poly to find its randome value using Newton Rapson Method");
    printf("\n0 to find all");
    scanf("%d",choice);
    if(choice<0||choice>countLL)
    {
        printf("\nInvalid Choice\t--Redirected--");
    }
    else if(choice==0)
    {}
    else
    {
        node *ntraverser=0;
        while(choice!=1)
        {
            ptraverser=ptraverser->next;
            choice--;
        }   
        ntraverser=ptraverser->poly;
        derivative(ntraverser);
    }
}*/
float reguFal(polys* ptraverser)
{
int choice=0;
float X=0;
int count=0;
    printf("\nWe have %d polys listed",countLL);
    printf("\nEnter which poly to find its randome value using Regular Falc Method");
    printf("\n0 to find all");
    scanf("%d",&choice);
    if(choice<0||choice>countLL)
    {
        printf("\nInvalid Choice\t--Redirected--");
    }
    else if(choice==0)
    {
        while(ptraverser!=0)
        {
            count++;
            ptraverser=ptraverser->next;
            X=reg(ptraverser->poly);
            printf("The approx val of x of polynimial%d is x=%f",count,X);

        }
    }
    else
    {
        //node *ntraverser=0;
        while(choice!=1)
        {
            ptraverser=ptraverser->next;
            choice--;
        }
        count=ptraverser->size-1;
        if(count==0)
        {printf("\nThe poly only has single element no root can be found.(I.E DEGREE is 0)");}
        else{
            int i=1;
        while(count!=0)
        {
            printf("\nEnter the interval %d",i);
        X=reg(ptraverser->poly);
            printf("\nThe approx val of x of polynimial%d is x=%f",choice,X);
            count--;i++;
        }
    }
    }
}
float reg(node *ntraverser)
{
    int success=1;
    float Xi=0,Xii=0,Xiii=0,exitcase=1,counter=0;
    float polval1=1,polval2=1,i=0;
    while(exitcase!=0)
    {   
    printf("\nEnter 1st random value");
    scanf("%f",&Xi);
    polval1=polyvalue(Xi,ntraverser);
    printf("\nEnter 2nd random value");
    scanf("%f",&Xii);
    polval2=polyvalue(Xii,ntraverser);
        if(Xi==0)
        {
            /*while(ntraverser->next!=0)
            {
                ntraverser=ntraverser->next;
            }
            polval1=ntraverser->data;
            printf("%d",ntraverser->data);
            ntraverser=nhead;
            polval2=polyvalue(Xii,ntraverser);*/
            polval1=ntraverser->data;
           // polval2=polyvalue(Xii,ntraverser);
        }
        if(Xii==0)
        {
           // polval1=polyvalue(Xi,ntraverser);
            polval2=ntraverser->data;
        }
        if(Xi==Xii)
        {
            printf("\nInvalid Interval");
        }
    //if(polval1<0&&polval2>0)
    if(polval1*polval2<=0&&Xi!=Xii) 
        {
            printf("\nf(a)=%f,and f(b)=%f",polval1,polval2);
            exitcase=0;
            if(polval1==0)
            {
                //printf("THE ROOT IS %f",Xi);
                return Xi;
            }
            if(polval2==0)
            {
                //printf("THE ROOT IS %f",Xii);
                return Xii;
            }
        }
    }
    printf("\nPoly values noted");
    //THE MESS STARTS FROM BELOW
    //MESS BEGINING
    func *varhead=0,*vartraverser=0,*var=0,*prev1=0,*prev2=0;
    //for(i=0;i<11;i++)//USE WHILE(i!=11) .if(success)->set i to 11 else ->increment i inside loop 
    while(success!=0)
    {
    var=(func*)malloc(sizeof(func));var->next=0;
    if(varhead==0)
    {
        varhead=vartraverser=var;
        vartraverser->IP=Xi;vartraverser->OP=polval1;
        var=(func*)malloc(sizeof(func));var->next=0;
        vartraverser->next=var;
        vartraverser=var;
        vartraverser->IP=Xii;vartraverser->OP=polval2;
        counter+=2;
    }
    else
    {
        //if conter=>4 strat cheking previous IP and OPs is they repeat to obtain success condition.NAH ITS DIFFERENT OR Such
        int j=0;
        vartraverser->next=var;
        vartraverser=var;
        /*vartraverser=varhead;
        for(j=1;j<counter;j++)
        {
            prev1=vartraverser;
            prev2=vartraverser=vartraverser->next;vartraverser=vartraverser->next;
        }
            */
           prev1=prev2=vartraverser=varhead;
           while(vartraverser->next!=0)
           {
            
            if(vartraverser!=varhead)//does not jump for firsr case so jumps 1 times less end up in 1 place befour.
            {
                prev2=prev2->next;
            }
            if(vartraverser!=varhead&&vartraverser!=varhead->next)//does not jump for firsr and second case so jumps 2 times less end up in 2 place befour.
            {
                prev1=prev1->next;
            }
            vartraverser=vartraverser->next;
           }
        //vartraverser=vartraverser->next;
        vartraverser->IP=((prev1->IP*prev2->OP)-(prev2->IP*prev1->OP))/(prev2->OP-prev1->OP);
        vartraverser->OP=polyvalue(vartraverser->IP,ntraverser);//var
        counter++;
        if(fabs(prev2->IP-vartraverser->IP)<=0.01||vartraverser->OP==0)
        {
            success=0;
           // return vartraverser->IP;
        }
    }
    }
    cleanA(varhead);
    return vartraverser->IP;
    //MESS END
}
float polyvalue(float IP,node* ntraverser)
{
    float OP=0;
    //int i=size-1;//FIX;-i is not related with count LL it is related with ptraverser->size FIXED done
    int i=0;
    while(ntraverser!=0)
{
    OP=OP+(float)ntraverser->data*pow(IP,i);
ntraverser=ntraverser->next;
i++;
}
return OP;
}
/*void RGFORM()//formula application{}*/
void cleanA(func* vartraverser)
{
    func *prev;
    while(vartraverser!=0)
    {
        prev=vartraverser;
        vartraverser=vartraverser->next;
        free(prev);
    }
    prev=0;
    printf("\nCleaned the root LL");
}
//70 or such lines of code is just traversing make a funcction to traverse.