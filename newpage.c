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
void go_back(){

    int q;
    printf("=-=-=-=--=--\npress [0] to return\n\n>>");
    scanf("%d", &q);

    if(q==0) homepage();
}

void go_back2(){

    int q;
    printf("\nPress 0 to return===");
    scanf("%d", &q);

    if(q==0) btype_page();
}

void user_info()

{
    FILE *fp;
    fp=fopen("user.txt","r");
    for(i=1;; i++){
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
        //printf("k= %d\n",k);
        //printf("WP = %d\n",u[k].pass);
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
    for(i=1;;i++){
        if(feof(fr)){break;}

    fscanf(fr,"%s",dnr[i].btype);
    fscanf(fr,"%d",&dnr[i].n);

    for(j=1; j<=dnr[i].n; j++){
        fscanf(fr,"%s",dnr[i].dname[j]);
        for(k=j;k==j;k++)
        {
             fscanf(fr," %[^\n]",dnr[i].dadd[k]);

        }
      }

   int loop_numer=i;
   //printf("loop nmbr:%d\n",loop_numer);
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
    printf("Enter Your Required Location: \n");
        scanf(" %[^\n]",add);
        location_check(add,a);

}
void location_check(char Dadd[100],int a)
{
    int k,f=0;
    for(i=a;;i++)
    {
        for(j=1;j<=dnr[a].n;j++)
        {
             for(k=j;k==j;k++)
        {
             if(strcmp(Dadd,dnr[a].dadd[j])==0)
             {
                 f=1;
                 printf("Found : %s %s\n",dnr[a].dname[j],dnr[a].dadd[j]);
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
    int a,b;
    system("cls");
    printf("Enter Blood Type:\n");
    printf("===>");

        char bt[100],add[100];
        scanf("%s",bt);
        blood_type_info();
        a=blood_search(bt);
        printf("Press 1 to go to next page: ");
        scanf("%d",&b);
        if(b==1)
        {
            location_page(a);
        }
        go_back2();

}
void own_page(int k)
{
    int n;
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

    }
    else if(n==2)
    {
        edit_info(k);
    }

}
void edit_info(int k)
{


}
void homepage(){
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
        own_page(x);
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
        own_page(x);


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
        own_page(x);

    }

    }

    //go_back();
}
void home_page2()
{



}

int main(){
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
    for(j=4;j<=6;j++){
    gotoxy(33,j);
    printf("%c-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-==%C",b,c);fflush(stdout);
    }
    for(k=17;k<=19;k++){
    gotoxy(33,k);
    printf("%C-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-==%c",b,c);fflush(stdout);}
    for(i=6;i<=16;i++){
    gotoxy(33,i);
    printf("%c-=",b);fflush(stdout);
    }
    for(i=6;i<=17;i++){
    gotoxy(79,i);
    printf("=-%c",c);fflush(stdout);
    }
    gotoxy(0,22);
    printf("===>PRESS 1 TO START\n");

    scanf("%d", &q);

    if(q==1){



    homepage();}
    getch();

    return 0;
}
