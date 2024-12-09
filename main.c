#include "myheaders.h"
struct Book *delete_book(struct Book *p);
void sort(struct Book *p){
    struct Book *z;z=p;
    if((z->next)==NULL){
        return;
    }
    else{
        struct Book *temp,*nxt,*d;
        
        d=z;
        
        while(d){
            nxt=temp->next;
            temp=z;
        while(nxt!=NULL){
            if(((strcmp(temp->name,nxt->name))==0)&&((strcmp(temp->author,nxt->author)==0))&&(temp->pages==nxt->pages))
            {
                temp->count++;
                temp->next=nxt->next;
                free(nxt);
                //return;
            }
            else
            {
                temp=temp->next;
                nxt=nxt->next;
            }
        }d=d->next;
        }
        free(nxt);
        return;
    }
}
struct Book *create_book(){
        struct Book *new_book;
        new_book=malloc(sizeof(struct Book));
        fflush(stdin);
        printf("enter book name\n");
       scanf("%[^\n]s",new_book->name);
       fflush(stdin);
        printf("enter author name\n");
        scanf("%s",new_book->author);
        fflush(stdin);
        printf("enter pages of book\n");
        scanf("%d",&new_book->pages);
        fflush(stdin);
        new_book->count=1;
        new_book->next=NULL;
        return new_book;
    }
struct Book *add_new_book(struct Book *p){
    struct Book *temp,*q,*z,*d;
    d=p;
    z=create_book();
    if(p==NULL){
        p=z;
        return p;
    }
    q=p;
    temp=z;
    while((q->next)!=NULL){
        q=q->next;
    }
    q->next=temp;
    //temp=NULL;
    q=p;
    //sort(d);
    return p;
}
struct Book * list_books(struct Book *p){
    struct Book *temp,*s;
    s=p;
    temp=p;
    if(temp==NULL){
        printf("no books");
    }
    else{
        printf("BOOK\tAUTHOR\tPAGES\tcount\n");
        printf("*************************\n");
        while(temp){
        printf("%s\t%s\t%d\t%d\n",temp->name,temp->author,temp->pages,temp->count);
        temp=temp->next;
        }
    }
    return s;
}
void count_book(struct Book *p){
    struct Book *temp;
    temp=p;
    char nm[100];
    
    if(temp==NULL){
        printf("no books");
    }
    else{
        printf("enter bane of book to display count\n");
        fflush(stdin);
        scanf("%s",nm);
        fflush(stdin);
        printf("BOOK\tcount\n");
        printf("*************************\n");
        while(temp->next){
            if(strcmp(temp->name,nm)==0)
            {
                printf("%s\t%d\n",temp->name,temp->count);
                return;
            }
             temp=temp->next;
        }
        if(strcmp(temp->name,nm)==0)
        {
            printf("%s\t%d\n",temp->name,temp->count);
            return;
        }
        printf("no books found\n");
    }
}
void find_book(struct Book *p){
    struct Book *temp;
    temp=p;
    char nm[100];
    char ch;
    if(temp==NULL){
        printf("no books\n");
        return;
    }
    printf("select operation\nn)search by name \ta)search by author\n");
    fflush(stdin);
    scanf("%c",&ch);
    switch (ch)
    {
    case 'n':case 'a':
        printf("enter  name\n");
        fflush(stdin);
        scanf("%s",nm);
        if(temp==NULL){
        printf("no books\n");
        return;
        }
         while(temp->next){
            if((strcmp(temp->name,nm)==0)||(strcmp(temp->author,nm)==0))
            {
                printf("%s\t%d\n",temp->name,temp->count);
                return;
            }
             temp=temp->next;
        }
        if((strcmp(temp->name,nm)==0)||(strcmp(temp->author,nm)==0))
        {
            printf("%s\t%d\n",temp->name,temp->count);
            return;
        }
        printf("no books found\n");
        break;
    
    default:
        printf("invalid operation\n");
        break;
    } 
}
struct Book * take_book(struct Book *p)
{
    struct Book *q,*s;
    s=p;
    q=p;
    if(q==NULL){
        printf("null no books");
        return s;}
    char name[100],auth[100];
    fflush(stdin);
    printf("Enter name of book\n");
    scanf("%s",name);
    printf("Enter author of book\n");
    fflush(stdin);
    scanf("%s",auth);
    while(q){
        
        if((strcmp(q->name,name)==0)&&(strcmp(q->author,auth)==0))
        {
            q->count--;
            return s;
        }
        q=q->next;
    }
     N1:
     
     N2:
     //s=delete_book(s);
     printf("no books found\n");
     return s;
}
void save(struct Book *p)
{
    FILE *fp;
    if(p==NULL)
    {
        puts("No books to save\n");
        fp=fopen("records.txt","w");
        return;
    }
    fp=fopen("records.txt","w");
    if(fp==NULL)
    {
        puts("unable to oprn file");
        return;
    }
    while(p)
    {
        fprintf(fp,"%s %s %d %d\n",p->name,p->author,p->pages,p->count);
        p=p->next;
    }
    fclose(fp);
    return;
}
struct Book *delete_book(struct Book *p)
{
    printf("came");
    struct Book *temp,*prev,*pr;
    if(p==NULL)
    {
        return p;
    }
    else if((p->next==NULL)&&(p->count<=0)){
        free(p);
        return NULL;
        //free(p);
    }
    else if(p->count<=0)
    {
        temp=p;
        p=p->next;
        return p;
    }
    else
    {
        temp=p->next;
        prev=p;
        while(temp)
        {
            if(temp->count<=0){
                prev->next=temp->next;
                free(temp);
                temp=NULL;
            }
            else
            {
                pr=prev;
                prev=temp;
                temp=temp->next;
            }   
        }    
    }
    //printf("came");
    return p;
}
void edit_book(struct Book *p){
    p=list_books(p);
    if(p==NULL){
        printf("no books to edit \n");
        return;
    }
    printf("enter book name and author name to edit");
    fflush(stdin);
    p=take_book(p);
    printf("enter new name of book and author\n");
    p=add_new_book(p);
    p=delete_book(p);
}
int main(){
    struct Book *head=syncfile();
    printf("**********WELCOME TO LIBRARY**********\n");
    while(1)
    {
        char ch;
        fflush(stdin);
        printf("\t*****ENTER AN OPERATION*****\n*s:save\t\t\t*a: add book\t*l:list of books\n*c:count of books\t*q:exit\n*f:find book\t\t*t:take book\t e:edit book\n");
        ch=getchar();
        fflush(stdin);
        switch (ch){
        case 'a':
        //case 'A':
            head=add_new_book(head);
            sort(head);
            break;
        case 'l': 
            head=list_books(head);
            break;
        case 'q':
            return 0;
            break;
        case 'c':
            count_book(head);
            break;
        case 'f':
            find_book(head);
            break;
        case 't':
            head=list_books(head);
            head=take_book(head);
            printf("sucesfull\n");
            head=delete_book(head);
            break;
        case 's':
            save(head);
            break;
        case 'e':
            head=list_books(head);
            printf("enter book name and author name to edit\n");
            fflush(stdin);
            head=take_book(head);
            printf("enter new name of book and author\n");
            head=add_new_book(head);
            sort(head);
            head=delete_book(head);
            break;
        default:
            break;
        }

    }
}
struct Book * syncfile()
{
    struct Book *ptr=NULL,*newnode=NULL,*temp=NULL;
    struct Book var;
    //var.name=callov(1,100);
    FILE *fp;
    fp=fopen("records.txt","r");
    if(fp==NULL)
    {
        return ptr;
    }
    else
    {
        while(fscanf(fp,"%s%s%d%d",var.name,var.author,&var.pages,&var.count)==4)
        {
            newnode=calloc(1,sizeof(struct Book));
            //newnode=create_book();
            if(newnode==NULL)
            {
                printf("no books");
            }
            else
            {
                //newnode->name=calloc(1,strlen(var.name)+1);
                //newnode->name=var.name;
                strcpy(newnode->name,var.name);
               // newnode->author=var.author;
                strcpy(newnode->author,var.author);
                newnode->pages=var.pages;
                newnode->count=var.count;
                if(ptr==NULL)
                {
                    ptr=newnode;
                }
                else
                {
                    temp=ptr;
                    while(temp->next!=NULL)
                    temp=temp->next;
                    temp->next=newnode;
                }

            }
            
        }
        fclose(fp);
        return ptr;
    }

}