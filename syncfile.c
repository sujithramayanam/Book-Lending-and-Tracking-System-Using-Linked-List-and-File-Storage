#include"myheaders.h"
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
            //newnode=calloc(1,sizeof(struct Book));
            newnode=create_book();
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