#include<stdio.h>
#include<string.h>
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
    char dname[100][100];

};
struct donor dnr[1000];


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
                printf("ID not found\n");
        }


    }
    return k;
}
int check_password(int pw,int k)
{
    int f=0;

        if(u[k].pass==pw)
            {
             f=1;

            }
        else
            {
            f=0;
            }
            return f;
}
void donor_info()
{
    FILE *fr;
    fr=fopen("bloodgroup.txt","r");
    for(i=1;;i++){
        if(feof(fr)){break;}

    fscanf(fr," %[^\n]",dnr[i].btype);
    fscanf(fr,"%d",&dnr[i].n);
    for(j=1; j<=dnr[i].n; j++){
        fscanf(fr,"%s",dnr[i].dname[j]);
      }

   int loop_numer=i;
   //printf("loop nmbr:%d\n",loop_numer);
  }

}


void blood_search(char btp[100])
{
  int pos=0;

    for(i=1;;i++)
    {
        if(strcmp(btp,dnr[i].btype)==0)
            {
          pos=i;
            for(j=1;j<=dnr[pos].n;j++)
                {
                printf("%s\n",dnr[pos].dname[j]);
                }
        break;
            }

    }

}

int main()
{
    printf("\t\t\t\t\t\tBLOOD BANK\n");
    printf("\t\t\t\tThe gift of blood is a gift to someone\n");
    printf("\n\n\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    int ID,p,x,q;
    printf("Enter ID :");
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
        q=check_password(p,x);
        if(q==1){
                printf("Login Complete\n");
        printf("\n\n\n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("Enter Blood Type:\n");

        char bt[100];
        scanf("%s",bt);
        donor_info();
        blood_search(bt);

        }
        else
        {
        printf("wrong password\n");
        }

    }

 return 0;
}



