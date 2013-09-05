#include <iostream>
#include <conio.h>
int main()
{
    int it,n;
    complex a[10],b[10],c[10],x;
    clrscr();
    cout<<"Enter the degree of the polynomial:";
    cin>>n;
    cout<<"Enter the coefficients of the polynomial"<<endl;
    for(int i=0;i<=n;i++)
        cin>>a[i];
    cout<<"Enter the initial guess in complex form: (x,y):";
    cin>>x;
    do{
        it=0;
        c[0]=a[0];
        b[0]=a[0];
        do{
            for(i=1;i<=n;i++)
                b[i]=a[i]+x*b[i-1];
            for(i=1;i<n;i++)
                c[i]=b[i]+x*c[i-1];
            x=x-b[n]/c[n-1];
            it++;
        }while(abs(b[n])>1e-5 && it<100);
        
        cout<<"The root is:"<<x<<endl;
        n--;
        for(i=0;i<=n;i++)
            a[i]=b[i];
            
    } while(n>=1);
    getch();
    return 0;
}
