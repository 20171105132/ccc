#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    char name[10];
    char sex[10];
    char class1[15];
    char phoneNo[15];
    int numbers;
    int dateofbirt;
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;
};
int main()
{
    FILE *a;
    FILE *b;
    int  n,i=0;
    char header[100];
    struct student p[100];
    a=fopen("/Users/s20171105132/Desktop/studentdata.csv","r");
    if (a==NULL)
    {
        printf("文件不存在\n");
        exit(-1);
    }
    else
    {
        fscanf(a,"%s",header);
        while(!feof(a))
        {
            fscanf(a,"%d,%[^,],%[^,],%d,%[^,],%[^,],%d ,%d ,%d ,%d ,%d ",&p[i].numbers,p[i].name,p[i].sex,
                   &p[i].dateofbirt,p[i].class1,p[i].phoneNo,&p[i].judge1,&p[i].judge2,&p[i].judge3,&p[i].judge4,&p[i].judge5);
            i++;
        }
        fclose(a);
    }
    n=i;
    int max[50],min[50];
    for(i=0;i<n;i++)
    {
        max[i]=min[i]=p[i].judge1;
    }
    for(i=0;i<n;i++)
    {
        if(p[i].judge2>max[i])
            max[i]=p[i].judge2;
        if(p[i].judge3>max[i])
            max[i]=p[i].judge3;
        if(p[i].judge4>max[i])
            max[i]=p[i].judge4;
        if(p[i].judge5>max[i])
            max[i]=p[i].judge5;
    }
    for(i=0;i<n;i++)
    {
        if(p[i].judge2<min[i])
            min[i]=p[i].judge2;
        if(p[i].judge3<min[i])
            min[i]=p[i].judge3;
        if(p[i].judge4<min[i])
            min[i]=p[i].judge4;
        if(p[i].judge5<min[i])
            min[i]=p[i].judge5;
    }
    for(i=0;i<n;i++)
    {
        p[i].score=(p[i].judge1+p[i].judge2+p[i].judge3+p[i].judge4+p[i].judge5-max[i]-min[i])/3;
    }
    b=fopen("/Users/s20171105132/Desktop/studentdata2.csv","w");
    if(b==0)
    {
        printf("文件不存在");
        exit(-1);
    }
    else
    {
        fprintf(b,"%s,score\n",header);
        printf("%s,score\n",header);
        i=0;
        while(i<n)
        {
            fprintf(b,"%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",p[i].numbers,p[i].name,p[i].sex,p[i].dateofbirt,p[i].class1,p[i].phoneNo,p[i].judge1,p[i].judge2,p[i].judge3,p[i].judge4,p[i].judge5,p[i].score);
            printf("%d,%s,%s,%d,%s,%s,%d,%d,%d,%d,%d,%d\n",p[i].numbers,p[i].name,p[i].sex,p[i].dateofbirt,p[i].class1,p[i].phoneNo,p[i].judge1,p[i].judge2,p[i].judge3,p[i].judge4,p[i].judge5,p[i].score);
            i++;
        }
    }
    fclose(b);
    return 0;
}
