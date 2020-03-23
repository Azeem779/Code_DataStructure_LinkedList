#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *link;
};
struct node *createlist(struct node *start);
struct node *addbeg(struct node *start,int data);
struct node *addend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *delbeg(struct node *start);
struct node *delend(struct node *start);
struct node *reverse(struct node *start);
struct node *search(struct node *start,int data);
void display(struct node *start);
void total(struct node *start);
int main()
{
    struct node *start=NULL;
    int choice,data,item;
    while(1)
        {
            printf("\n1.Create New list.\n");
            printf("2.Add at beginning.\n");
            printf("3.At the end..\n");
            printf("4.At after node.\n");
            printf("5.At before node.\n");
            printf("6.Delete at Beginning.\n");
            printf("7.Delete at end.\n");
            printf("8.Display List.\n");
            printf("9.Search item.\n");
            printf("10.Count item.\n");
            printf("11.Reverse list.\n");
            printf("12.Exit.\n");
            printf("\nEnter the value: ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                    start=createlist(start);
                    break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d",&data);
                start=addbeg(start,data);
                    break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d",&data);
                start=addend(start,data);
                    break;
            case 4:
                printf("Enter the value to be inserted: ");
                scanf("%d",&data);
                printf("Enter the value after which value is to be inserted: ");
                scanf("%d",&item);
                start=addafter(start,data,item);
                    break;
            case 5:
                printf("Enter the value to be inserted: ");
                scanf("%d",&data);
                printf("Enter the value after which value is to be inserted: ");
                scanf("%d",&item);
                start=addbefore(start,data,item);
                    break;
            case 6:
                start=delbeg(start);
                break;
            case 7:
                start=delend(start);
                break;
            case 8:
                display(start);
                    break;
            case 9:
                printf("Enter the data to be searched: ");
                start=search(start,data);
                break;
            case 10:
                total(start);
                break;
            case 11:
                start=reverse(start);
                break;
            case 12:
                exit(1);
            default:
                printf("\nWrong choice...\n");
            }
        }
}
struct node *createlist(struct node *start)
{
 int i,n,data;
 printf("Enter the number of node: ");
 scanf("%d",&n);
 printf("Enter the data to be inserted: ");
 scanf("%d",&data);
 start=NULL;
 if(n==0)
        return;
 start=addbeg(start,data);
 for(i=2;i<=n;i++)
 {
  printf("Enter the data to be inserted: ");
  scanf("%d",&data);
  start=addend(start,data);
 }
 return start;
}
struct node *addbeg(struct node *start,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}
struct node *addend(struct node *start,int data)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    p=start;
    while(p->link!=NULL)
    {
        p=p->link;
    }
    p->link=temp;
    return start;
}
void display(struct node *start)
{
 struct node *p;
 if(start==NULL)
 {
     printf("List is empty.");
     return;
 }
 printf("List is: ");
 p=start;
 while(p!=NULL)
 {
     printf("%d ",p->info);
     p=p->link;
 }
 printf("\n");
}
struct node *addafter(struct node *start,int data,int item)
{
    struct node *p,*temp;
    p=start;
        while(p!=NULL)
        {
            if(p->info==item)
            {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->info=data;
                temp->link=p->link;
                p->link=temp;
            }
            p=p->link;
        }
        printf("%d not present in the list.",item);
        return start;
}
struct node *addbefore(struct node *start,int data,int item)
{
    struct node *p,*temp;
    p=start;
        while(p!=NULL)
        {
            if(p->link->info==item)
            {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->info=data;
                temp->link=p->link;
                p->link=temp;
            }
            p=p->link;
        }
        printf("%d not present in the list.",item);
        return start;
}
struct node *delbeg(struct node *start)
{
    struct node *p;
    p=start;
    start=start->link;
    free(p);
    return start;
}
struct node *delend(struct node *start)
{
    struct node *p,*temp;
    p=start;
    while(p->link!=NULL)
    {
        temp=p;
        p=p->link;
    }
    temp->link=NULL;
    free(p);
    return start;
}
struct node *search(struct node *start,int data)
{
    struct node *p;
    int pos=1;
    p=start;
    while(p!=NULL)
    {
        if(p->info==data)
        {
            printf("Item %d is found at %d",data,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("%d is not found.",data);
}
void total(struct node *start)
{
 int count=0;
 struct node *p;
 p=start;
 while(p!=NULL)
 {
     p=p->link;
     count++;
 }
 printf("Total element in the list: %d",count);
 printf("\n");
}
struct node *reverse(struct node *start)
{
    struct node *prev,*next,*temp;
    prev=NULL;
    temp=start;
    while(temp!=NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    start=prev;
    printf("List reversed: ");
    return start;
}
