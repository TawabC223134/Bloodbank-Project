#include <stdio.h>
#include<string.h>
#include<windows.h>

int i,j,n;
struct user
{
    int id,pass;
    char name[100];

};
struct user u[1000];
struct donor
{
    char btype[100];
    int n;
    char dname[100][100],dadd[100][100];

};
struct donor dnr[1000];
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
sleep(sometime_in_millisecs);
void go_back()
{

    int q;
    printf("=-=-=-=--=--\nPress 0 to return\n\n>>");
    scanf("%d", &q);

    if(q==0) homepage();
}

void go_back2()
{

    int q;
    printf("\nPress 0 to return===");
    scanf("%d", &q);

    if(q==0) btype_page();
}

void user_info()

{
    FILE *fp;
    fp=fopen("user.txt","r");
    for(i=1;; i++)
        {
            if(feof(fp))
            {
                break;
            }
        fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
        }

}
void donor_info()
{
    FILE *fp=fopen("donor.txt","r");
    for(i=1;;i++)
    {
        if(feof(fp))
            {
                break;
            }
        fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
    }
}
void authority_info()
{
    FILE *fp=fopen("authority.txt","r");
    for(i=1;;i++)
    {
        if(feof(fp))
            {
                break;
            }
        fscanf(fp,"%d",&u[i].id);
        fscanf(fp," %[^\n]",u[i].name);
        fscanf(fp,"%d",&u[i].pass);
    }
}
void user_write_info()

{
    FILE *fp=fopen("user.txt","w");
    for(i=1;i<6;i++)
    {

    fprintf(fp,"%d\n",u[i].id);
    fprintf(fp,"%s\n",u[i].name);
    fprintf(fp,"%d\n",u[i].pass);


    }
    fclose(fp);


}
void donor_write_info()

{
    FILE *fp=fopen("donor.txt","w");
    for(i=1;i<6;i++)
    {

    fprintf(fp,"%d\n",u[i].id);
    fprintf(fp,"%s\n",u[i].name);
    fprintf(fp,"%d\n",u[i].pass);


    }
    fclose(fp);


}
void authority_write_info()

{
    FILE *fp=fopen("authority.txt","w");
    for(i=1;i<6;i++)
    {

    fprintf(fp,"%d\n",u[i].id);
    fprintf(fp,"%s\n",u[i].name);
    fprintf(fp,"%d\n",u[i].pass);


    }
    fclose(fp);


}
void authority_user_edit_write()
{
    FILE *fp=fopen("user.txt","w");
    for(i=1;i<6;i++)
    {

    fprintf(fp,"%d\n",u[i].id);
    fprintf(fp,"%s\n",u[i].name);
    fprintf(fp,"%d\n",u[i].pass);



    }
    fclose(fp);

}

int check_id(int ID)
{
    int k=0;
   for(i=1; i<6; i++){
        //printf("i=%d\n",i);
        if(ID==u[i].id)
            {

                k=i;
                break;
            }

        else
            {
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

                go_back();
            }



}


void blood_type_info()
{
    int k;
    FILE *fr;
    fr=fopen("bloodgroup.txt","r");
    for(i=1;;i++)
        {
        if(feof(fr)){break;
        }

    fscanf(fr,"%s",dnr[i].btype);
    fscanf(fr,"%d",&dnr[i].n);

    for(j=1; j<=dnr[i].n; j++)
      {
        fscanf(fr,"%s",dnr[i].dname[j]);
        for(k=j;k==j;k++)
        {
             fscanf(fr," %[^\n]",dnr[i].dadd[k]);

        }
      }

   int loop_numer=i;

  }

}


int blood_search(char btp[100])
{
  int pos=0,k,b;

    for(i=1;;i++)
    {
        if(strcmp(btp,dnr[i].btype)==0)
            {
          pos=i;
           if(dnr[pos].n==0){
                    printf("Blood Type Not Availaible\n");}
            for(j=1;j<=dnr[pos].n;j++)
                {
                printf("%s\n",dnr[pos].dname[j]);
                for(k=j;k==j;k++)
        {
             printf("%s\n",dnr[pos].dadd[j]);
        }

                }

        break;
            }

    }

return pos;


}
void location_page(int a)
{
    char add[100];
    system("cls");
    printf("Enter Your Desired Location: \n");
        scanf(" %[^\n]",add);
        location_check(add,a);

}
void location_check(char Dadd[100],int a)
{
    int k,f=0,m;
    for(i=a;;i++)
    {
        for(j=1;j<=dnr[a].n;j++)
        {
             for(k=j;k==j;k++)
            {
             if(strcmp(Dadd,dnr[a].dadd[j])==0)
             {
                 f++;
                 printf("Found : %d.%s %s\n",f,dnr[a].dname[j],dnr[a].dadd[j]);

             }
             else
             {
                 continue;
             }
            }

        }
        if(f==0)
        {
            printf("No one available at this place\n");
        }
        break;

    }


}

void btype_page()
{
    int a,b,q;
    system("cls");
    printf("Enter Blood Type:\n");
    printf("===>");

        char bt[100],add[100];
        scanf("%s",bt);
        blood_type_info();
        a=blood_search(bt);
        printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to next page\n");

        printf("===>");
        scanf("%d",&b);
        if(b==1)
        {
            location_page(a);
            //go_back2();
            printf("\nPress 0 to return to homepage\n");
            printf("Press 1 to return to previous page\n");
            printf("===>");
            scanf("%d", &q);
            if(q==0)
            {
                homepage();
            }

            else if(q==1)
            {
              btype_page();
            }

        }
        else if(b==0)
        {
            homepage();
        }


}
void own_page(int k,int q)
{
    int n,m;
    system("cls");
    printf("Press 1 to Show your information\n");
    printf("Press 2 to Edit your information\n");
    printf("===>");
    scanf("%d",&n);
    if(n==1)
    {
      printf("ID : %d\n",u[k].id);
      printf("Name : %s\n",u[k].name);
      printf("Password : %d\n",u[k].pass);
      printf("Press 0 to go to homepage\n");
       printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
          own_page(k,q);
        }

    }
    else if(n==2)
    {
        edit_info(k,q);
    }

}
void authority_own_page(int k ,int q)
{
    int n,m;
    system("cls");
    printf("Press 1 to Show your information\n");
    printf("Press 2 to Edit  information\n");
    printf("===>");
    scanf("%d",&n);
    if(n==1)
    {
      printf("ID : %d\n",u[k].id);
      printf("Name : %s\n",u[k].name);
      printf("Password : %d\n",u[k].pass);
      printf("Press 0 to go to homepage\n");
      printf("Press 1 to go to previous page\n");
      printf("===>");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
          authority_own_page(k,q);
        }
    }
    else if(n==2)
    {
       authority_edit(k,q);

    }

}
void authority_edit(int k,int q)
{
    system("cls");
    int nid,n,m,oid;
    char nname[100];
    printf("Press 1 to edit user information\n");
    printf("Press 2 to edit donor information\n");
    printf("Press 3 to edit your information\n");
    printf("==>");
    scanf("%d",&n);
    if(n==1)
    {
        user_info();

        printf("Enter old ID :");
        scanf("%d",&oid);
        printf("Enter new ID :");
        scanf("%d",&nid);
        u[oid].id=nid;
        printf("Enter new name :");
        scanf(" %[^\n]",nname);
        strcpy(u[k].name,nname);

        authority_user_edit_write();
         printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
            authority_edit(k,q);

        }

    }
    else if(n==2)
    {
        donor_info();

        printf("Enter old ID :");
        scanf("%d",&oid);
        printf("Enter new ID :");
        scanf("%d",&nid);
        u[oid].id=nid;
        printf("Enter new name :");
        scanf(" %[^\n]",nname);
        strcpy(u[k].name,nname);

        authority_user_edit_write();
        printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
            authority_edit(k,q);

        }

    }
    else if (q==3)
    {
        edit_info(k,q);


    }


}

void edit_info(int k,int q)
{
    system("cls");
    char str[100];
    int npass,m;
    if(q==1)
    {

        user_info();
        printf("Enter new name :");
        scanf(" %[^\n]",str);
        strcpy(u[k].name,str);
        //printf(" new = %s\n",u[k].name);
        printf("Enter new pass :");
        scanf("%d",&npass);
        u[k].pass=npass;


        user_write_info();
        printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
          own_page(k,q);
        }


    }
     else if(q==2)
    {
        donor_info();

        printf("Enter new name :");
        scanf(" %[^\n]",str);
        strcpy(u[k].name,str);
        //printf(" new = %s\n",u[k].name);
        printf("Enter new pass :");
        scanf("%d",&npass);
        u[k].pass=npass;


        donor_write_info();
        printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
          own_page(k,q);
        }

    }
     else if(q==3)
    {
        authority_info();

        printf("Enter new name :");
        scanf(" %[^\n]",str);
        strcpy(u[k].name,str);
        //printf(" new = %s\n",u[k].name);
        printf("Enter new pass :");
        scanf("%d",&npass);
        u[k].pass=npass;

        authority_write_info();
        printf("Press 0 to go to homepage\n");
        printf("Press 1 to go to previous page\n");
        scanf("%d",&m);
        if(m==0)
        {
            homepage();
        }
        else if(m==1)
        {
          authority_own_page(k,q);
        }

    }

}

void homepage()
{
    system("cls");

    printf("PRESS 1 TO LOGIN AS A USER\n");


    printf("=-=--=-=-=-=-=-=-=-=-=-=--=-=\n");fflush(stdout);

    printf("PRESS 2 TO LOGIN AS A DONOR\n");fflush(stdout);


    printf("=-=--=-=-=-=-=-=-=-=-=-=--=-=\n");fflush(stdout);

    printf("PRESS 3 TO LOGIN AS A AUTHORITY\n");

    printf("=-=--=-=-=-=-=-=-=-=-=-=--=-=");fflush(stdout);
    gotoxy(0,8);
    printf(">>>>");
    int q,p,ID,x,m;
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
        go_back();
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);

        check_password(p,x);

        printf("press 1 to go to insert blood type\n");
        printf("Press 2 to go to your profile\n");

    scanf("%d",&m);
        if(m==1)
        {
     btype_page();
        }
        else if(m==2)
        {
          printf("Press 1 to go to next page\n");
        own_page(x,q);
        }


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
        go_back();
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);
        check_password(p,x);

        printf("Press 1 to go to next page\n");
        own_page(x,q);


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
       go_back();
    }
    else
    {
         printf("enter password :");
        scanf("%d",&p);
        check_password(p,x);
        printf("Press 1 to go to next page\n");
        authority_own_page(x,q);

    }

    }


}


int main()
{
    system("cls");
    int q;
     int x,y,i,j,k;
    char a=3,b=62,c=60,d=247,e=254;
    gotoxy(53,11);
    printf("BLOOD BANK");fflush(stdout);
    sleep(1);
    gotoxy(39,13);
    printf("THE GIFT OF BLOOD IS A GIFT TO SOMEONE%C",a);fflush(stdout);
    sleep(1);
    for(j=4;j<=6;j++)
    {
    gotoxy(33,j);
    printf("%c-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-==%C",b,c);fflush(stdout);
    }
    for(k=17;k<=19;k++)
    {
    gotoxy(33,k);
    printf("%C-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-==%c",b,c);fflush(stdout);
    }
    for(i=6;i<=16;i++)
    {
    gotoxy(33,i);
    printf("%c-=",b);fflush(stdout);
    }
    for(i=6;i<=17;i++)
    {
    gotoxy(79,i);
    printf("=-%c",c);fflush(stdout);
    }
    gotoxy(0,22);
    printf("===>PRESS 1 TO START\n");

    scanf("%d", &q);

    if(q==1)
        {
            homepage();
        }
            getch();

    return 0;
}
