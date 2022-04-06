#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[30];
int a,e,c;
void exor()
{
  for(c=1;c<N;c++)
  cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc()
{
    for(e=0;e<N;e++)
    cs[e]=t[e];
    do{
         if(cs[0]=='1') exor();
         for(c=0;c<N-1;c++)
      cs[c]=cs[c+1];
      cs[c]=t[e++];
    }while(e<=a+N-1);
}

int main()

{
    int count=0;
    printf("\nEnter data:");
    scanf("%s",t);
    printf("\n--------------------------");
    printf("\nEnter Generating polynomial in binary:");
    scanf("%s",g);
    a=strlen(t);
    for(e=a;e<a+N-1;e++) t[e]='0';
    printf("\n--------------------------");
    printf("\nAugmented dataword:%s",t);
    printf("\n--------------------------");
    crc();
    printf("\nChecksum is:%s",cs);
    for(e=a;e<a+N-1;e++) t[e]=cs[e-a];
    printf("\n--------------------------");
    printf("\nFinal Codeword is:%s",t);
    printf("\n--------------------------\n\n");


    //receiver code

printf("\n Code Received is:%s",t);
crc();
printf("\n*******************************");
printf("\nChecksum is: %s",cs);

for(int z=0;z<strlen(cs);z++)
{
    if (cs[z]='0')
        count=count+1;
}
if(count==strlen(cs))
    printf("\n Received data is correct");
else
    printf("\n Incorrect");

char l[40];
int p;
    printf("Enter the codeword");
    scanf("%s",&l);
    printf("Enter polynomial");
    scanf("%d",&p);
    int s=strlen(p);
    int m=strlen(l);
    int q=s-m;
    char dest[30];
  strncpy(dest,l,strlen(l)-s);


}
