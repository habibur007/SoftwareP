#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char name[50];
    char phn[50];
    struct node *next;
}*head,*temp,*current,*previous,*record,*target;

void insert_end()
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    getchar();
    printf("Name: ");
    gets(newnode->name);
    printf("Phone Number: ");
    gets(newnode->phn);
    printf("\n");
    newnode->next=NULL;

    if(head==NULL) head=newnode;
    else{
        temp=head;
        while(temp->next!=NULL) temp=temp->next;

            temp->next=newnode;
    }
}

void searchname(char sname[50])
{
    current=head;
    int c=0;
    while(current!=NULL){
        if(strcmp(sname,current->name)==0){
            c=1;
            break;
        }
        else current=current->next;
    }
    if(c==0) printf("%s was not found.\n",sname);
    else if(c==1) printf("\n%s Exists in the list.\tComplete information of %s is:\n\n Name: %s\nPhone number: %s\n\n",sname,sname,current->name,current->phn);

    printf("press any key to continue");
    getch();
    system("cls");
}

void deletename(char sname[50])
{
    if(head==NULL) printf("\n\t\t\t\t\tSorry, Your Phone book list is Empty right now.\n\t\t\t\t\tCan't Perform operation\n\t\t\t\t\tAdd contact first.\n");

    else{
        current=head;
        previous=NULL;
        int c=0;
        if((strcmp(head->name,sname)==0)){
            if(head->next==NULL) head=NULL;

            else head=head->next;

            printf("\n\t\t\t\t\tContact deleted successfully\n");
        }
        else{
            while(current!=NULL){
                if(strcmp(sname,current->name)==0){
                    c=1;
                    break;
                }
                else{
                    previous=current;
                    current=current->next;
                }
            }
            if(c==0) printf("\n\t\t\t\t%s was not found.\n\n",sname);
            else if(c==1){
                previous->next=current->next;
                free(current);

                printf("\n\t\t\t\t\tContact deleted successfully\n");
            }
        }
    }
    printf("press any key to continue");
    getch();
    system("cls");
}

void modify(char sname[50])
{
    if(head==NULL) printf("\n\t\t\t\t\tSorry, Your Phone book list is Empty right now.\n\t\t\t\t\tCan't Perform operation\n\t\t\t\t\tAdd contact first.\n");


    else{
        int c=0;
        current=head;record=NULL;target=NULL;
        if(strcmp(sname,head->name)==0){
            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            printf("Name: ");
            gets(newnode->name);
            printf("Phone Number: ");
            gets(newnode->phn);
            printf("\n");
            newnode->next=head->next;
            head=newnode;

            printf("\n\t\t\tModified Successfully.\n\n\n");
        }
        else{
            while(current!=NULL){
                if(strcmp(sname,current->name)==0){
                    c=1;
                    target=current->next;
                    free(current);
                    struct node *newnode=(struct node*)malloc(sizeof(struct node));
                    printf("Name: ");
                    gets(newnode->name);
                    printf("Phone Number: ");
                    gets(newnode->phn);
                    printf("\n");
                    newnode->next=NULL;

                    record->next=newnode;
                    newnode->next=target;
                    break;
                }
                else{
                    record=current;
                    current=current->next;
                }
            }
            if(c==0) printf("\n\t\t\tYour Desired contact was not found\n\n\n");
            else printf("\n\t\t\tModified Successfully.\n\n\n");
        }
    }
    printf("press any key to continue");
    getch();
    system("cls");
}

void display()
{
    int c;
    temp=head;
    if(head==NULL) printf("\n\t\t\t\t\tSorry, Your Phone book list is Empty right now.\n\t\t\t\t\tAdd contact first.\n");

    else{
        printf("\t\t\t\t\tYour Current Phone book list is:\n");
        while(temp!=NULL){
            printf("Name: %s\nPhone Number: %s\n\n",temp->name,temp->phn);
            temp=temp->next;
        }
    }
    printf("press any key to continue");
    getch();
    system("cls");
}
float menu()
{
    printf("1.Add new contact\n2.Display List\n3.Delete Record\n4.Modify Record\n5.Search Record\n6.Exit\n\n");
    float dis;
    scanf("%f",&dis);
    return dis;
}



int main()
{
    int d1;
    float input;
    char sname[50];
    printf("\t\t\t\t\t****Welcome to Phone Book****\n");
    while(1){
        input=menu();
        if(input==6) break;
        else{
            if(input==1){
                insert_end();
                system("cls");
                printf("\n\t\t\t\t\tData saved successfully\n");
            }
            else if(input==2){
                sort();
                display();
            }
            else if(input==3){
                printf("Enter name you want to delete: ");
                getchar();
                gets(sname);
                deletename(sname);
            }
            else if(input==4){
                printf("Enter name you want to Modify: ");
                getchar();
                gets(sname);
                modify(sname);
            }
            else if(input==5){
                printf("Enter name you want to search: ");
                getchar();
                gets(sname);
                searchname(sname);
            }
            else{
                system("cls");
                printf("\n\n\t\t\t\t\t//Please Choose Integers between 1 to 6//\n\n");
            }
        }
    }
    return 0;
}


