/************* Gauss elimination for solving linear equations *************/

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n,i,j,k,temp;
    float a[10][10],c,d[10]={0};
    cout<<"No of equation ? ";
    cin>>n;
    cout<<"Coefficient of all : \n";
    for(i=0;i<n;i++)
    {
        cout<<"equation: "<<i+1<< "   ";
        for(j=0;j<=n;j++)
            cin>>a[i][j];
    }
    for(i=n-1;i>0;i--)        // partial pivoting
    {
        if(a[i-1][0]<a[i][0])
            for(j=0;j<=n;j++)
            {
                c=a[i][j];
                a[i][j]=a[i-1][j];
                a[i-1][j]=c;
            }
    }
    //*************** DISPLAY MATRIX*************//
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%6.1f",a[i][j]);
        printf("\n");
    }
    //********* changing to upper triangular matrix*************//
    //********* Forward elimination process**************//
    for(i=0;i<=n-1;i++)
        for(j=i;j<=n-1;j++)
        {if(j!=i){
            c= (a[j][i]/a[i][i]) ;
            
            for(k=0;k<=n;k++)
                a[j][k]-=c*a[i][k];}
        }

     // ************DISPLAYING UPPER TRIANGULAE MATRIX***************//

    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%6.1f",a[i][j]);
            
        printf("\n");
    }
    //***************** Backward Substitution method****************//

    for(i=n-1;i>=0;i--)
    {
        c=0;
        for(j=i;j<=n-1;j++)
            c=c+a[i][j]*d[j];
            
        d[i]=(a[i][n]-c)/a[i][i];
    }
    //******** RESULT DISPLAY *********//
    for(i=0;i<n;i++)
    cout<<d[i]<<endl;


    getch();
    return 0;
}
