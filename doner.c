#include<stdio.h>
#include<string.h>
int i,j,n;

struct doner
{
    char dname[100];
};
struct doner std[1000];
void blood_search(char btp[100])
{

    if(strcmp(btp,"A+")==0)
    {
        printf("A+ DONOR:\n");
       FILE *fr;
       fr=fopen("A+.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }

         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }


    }
       else if(strcmp(btp,"A-")==0)
    {
        printf("A- DONOR:\n");
       FILE *fr;
       fr=fopen("A-.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }
    else if(strcmp(btp,"B+")==0)
    {
        printf("B+ DONOR:\n");
       FILE *fr;
       fr=fopen("B+.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }
    else if(strcmp(btp,"B-")==0)
    {
        printf("B- DONOR:\n");
       FILE *fr;
       fr=fopen("B-.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }

    else if(strcmp(btp,"O+")==0)
    {
        printf("O+ DONOR:\n");
       FILE *fr;
       fr=fopen("O+.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }
    else if(strcmp(btp,"O-")==0)
    {
        printf("O- DONOR:\n");
       FILE *fr;
       fr=fopen("O-.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }

    else if(strcmp(btp,"AB+")==0)
    {
        printf("AB+ DONOR:\n");
       FILE *fr;
       fr=fopen("AB+.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }
    else if(strcmp(btp,"AB-")==0)
    {
        printf("AB- DONOR:\n");
       FILE *fr;
       fr=fopen("AB-.txt","r");
       for(i=1;;i++){

         if(feof(fr)){
            break;
         }
         fscanf(fr," %[^\n]",std[i].dname);
         printf("%s\n",std[i].dname);
         }
    }

}
int main()
{
     printf("Enter Blood Type:\n");
    char bt[100];
    scanf("%s",bt);

    blood_search(bt);

}
