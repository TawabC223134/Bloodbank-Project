#include<stdio.h>
#include<string.h>
int i,j,k;

struct user_search
{
    int n;
   char dname[100];
   char btype[100];
   //struct doner_name utd[1000];
};
struct user_search std[1000];

void blood_read()
{

    int x=0;
    FILE *fr=fopen("bloodgroup.txt","r");
      ///Blood type read
    for(i=1;i<=31;i++)
    {

        fscanf(fr,"%s",std[i].btype);
        printf("i=%d\n",i);

        fscanf(fr,"%d",&std[i+1].n);
        for(j=i+2;j<=31;j++)
            {
                if(feof(fr)){break;}

            fscanf(fr,"%s",std[j].dname);
            //printf("%s j=%d\n",std[j].dname,j);
        }
        //printf(" std[i] = %d\n",std[i+1].n);
        x+=std[i+1].n;//5+0
        i=x+2;//7 9



        //printf("I = %d\n",i);

    }
}
void blood_search(char btp[100])
{

    for(i=1;i<=31; i++){


    if(strcmp(btp,std[i].btype) == 0)
    {
       int a=i;
        printf("A+ Donor:\n");
        for(j=i+2;j<=(std[i+1].n)+2;j++)
        {
           printf("%s\n",std[j].dname);
        }
    }
   else if(strcmp(btp,std[i].btype) == 0)
    {
       int a=i;
       printf("%d",a);
        printf("A- Donor:\n");
        for(j=i+2;j<=(std[i+1].n)+2;j++)
        {
           printf("%s\n",std[j].dname);
        }
    }
    else if(strcmp(btp,std[3].btype)==0)
    {
      printf("B+ Donor:\n");
      for(j=1; ;)
      {

      }
    }
    else if(strcmp(btp,std[4].btype)==0)
    {
      printf("B- Donor:\n");
      for(j=1; ;)
      {

      }
    }
    else if(strcmp(btp,std[5].btype)==0)
    {
      printf("O+ Donor:\n");
      for(j=1; ;)
      {

      }
    }
    else if(strcmp(btp,std[6].btype)==0)
    {
      printf("O- Donor:\n");
      for(j=1; ;)
      {

      }
    }
    else if(strcmp(btp,std[2].btype)==0)
    {
      printf("AB+ Donor:\n");
      for(j=1; ;)
      {

      }
    }
    else if(strcmp(btp,std[2].btype)==0)
    {
      printf("AB- Donor:\n");
      for(j=1; ;)
      {

      }
    }
  }
}

int main()
{
    char bt[100];
    scanf("%s",bt);
    //user_search
    blood_read();
    blood_search(bt);


    return 0;
}
