#include <stdio.h>

int main() {
    int data[100];
    int datacheck[100],c,c1,c2,c3,i;

    printf("Enter the bits of data one by one\n");
    scanf("%d",&data[0]);
    scanf("%d",&data[1]);
    scanf("%d",&data[2]);
    scanf("%d",&data[4]);
    scanf("%d",&data[5]);
    scanf("%d",&data[6]);
    scanf("%d",&data[8]);

    //Calculation of parity
    data[10]=data[8]^data[6]^data[4]^data[2]^data[0];
    data[9]=data[8]^data[5]^data[4]^data[1]^data[0];
     data[7]=data[4]^data[5]^data[6];
    data[3]=data[0]^data[1]^data[2];

    printf("\nEncoded data is\n");
    for(i=0;i<11;i++)
        printf("%d",data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for(i=0;i<11;i++)
        scanf("%d",&datacheck[i]);

    c1=datacheck[6]^datacheck[4]^datacheck[2]^datacheck[0];
    c2=datacheck[5]^datacheck[4]^datacheck[1]^datacheck[0];
    c3=datacheck[3]^datacheck[2]^datacheck[1]^datacheck[0];
    c=c3*4+c2*2+c1 ;

    if(c==0) {
        printf("\nNo error while transmission of data\n");
    }
    else {
        printf("\nFound error on position %d",c);

        printf("\nData in : ");
        for(i=0;i<11;i++)
            printf("%d",data[i]);

        printf("\nData out : ");
        for(i=0;i<11;i++)
            printf("%d",datacheck[i]);

        printf("\nCorrect message is\n");

        //if errorneous bit is 0 we complement it else vice versa
        if(datacheck[11-c]==0)
            datacheck[11-c]=1;
        else
            datacheck[11-c]=0;

        for (i=0;i<11;i++) {
            printf("%d",datacheck[i]);
        }
    }
}
