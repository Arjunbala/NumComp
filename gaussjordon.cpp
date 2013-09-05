#include<iostream.h>
#include<conio.h>
int main()
{
    int i,j,k,n;
    float a[10][10],d;

    cout<<"No of equations ? ";cin>>n;
    cout<<"Read all coefficients of matrix with b matrix too "<<endl;
    for(i=1;i<=n;i++) // read nxn matrix - cofficients
        for(j=1;j<=n+1;j++)
            cin>>a[i][j];

    /************** partial pivoting **************/
    for(i=n;i>1;i--)
    {
        if(a[i-1][1]<a[i][1])
        for(j=1;j<=n+1;j++)
        {
            d=a[i][j];
            a[i][j]=a[i-1][j];
            a[i-1][j]=d;
        }
    }
    cout<<"pivoted output: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
            cout<<a[i][j]<<"    ";
        cout<<endl;
    }
    /********** reducing to diagonal  matrix ***********/

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        if(j!=i)
        {
            d=a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++)
                a[j][k]-=a[i][k]*d;
        }
    }
    /************** reducing to unit matrix *************/
    for(i=1;i<=n;i++)
    {
    d=a[i][i];
        for(j=1;j<=n+1;j++)
            a[i][j]=a[i][j]/d;
    }


    cout<<"your solutions: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+1;j++)
            cout<<a[i][j]<<"    ";
        cout<<endl;
    }

    

    getch();
    return 0;
}
