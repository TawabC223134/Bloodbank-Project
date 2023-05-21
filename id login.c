#include<stdio.h>
#include<string.h>
int i,j,n;
struct user
{
    int id,pass;
    char name[100];

};
struct user u[1000];
void user_info()
{
    FILE *fp;
    fp=fopen("user.txt","r");
    for(i=1; i<6; i++){
        fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
    }

}
void donor_info()
{
    FILE *fp=fopen("donor.txt","r");
    for(i=1;i<5;i++)
    {
       fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
    }
}
void authority_info()
{
    FILE *fp=fopen("authority.txt","r");
    for(i=1;i<5;i++)
    {
       fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
    }
}
int check_id(int ID)
{
    int k=0;
   for(i=1; i<6; i++){
        //printf("i=%d\n",i);
        if(ID==u[i].id){

            k=i;
            break;
            }

        else{
                continue;
                printf("not found\n");
        }


    }
    return k;
}
void check_password(int pw,int k)
{
       if(u[k].pass==pw)
            {
        printf("login complete\n");

            }
        else
            {
        printf("wrong password\n");
            }

}
int main()
{
    printf("Press 1 to login as a user\n");
    printf("Press 2 to login as a donor\n");
    printf("Press 3 to login as a authority\n");

    int q,p,ID,x;
    scanf("%d",&q);
    if(q==1)
    {
        printf("Enter User ID :");
    scanf("%d",&ID);
    user_info();
    x=check_id(ID);
    if(x==0)
    {
        printf("ID not found\n");
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);
        check_password(p,x);

    }

    }
    else if(q==2)
    {
          printf("Enter Donor ID :");
    scanf("%d",&ID);
    donor_info();
    x=check_id(ID);
    if(x==0)
    {
        printf("ID not found\n");
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);
        check_password(p,x);

    }

    }
       else if(q==3)
    {
          printf("Enter Authority ID :");
    scanf("%d",&ID);
    authority_info();
    x=check_id(ID);
    if(x==0)
    {
        printf("ID not found\n");
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);
        check_password(p,x);

    }

    }


}
