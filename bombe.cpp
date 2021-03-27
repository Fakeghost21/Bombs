#include <iostream>
#include <fstream>
using namespace std;
int distanta(int x,int y,int a,int b)
{   int d,e;
    d=(x-a)*(x-a);
    e=(y-b)*(y-b);
    return d+e;
}
void elim(int &n,int a[][3],int b,int c)
{   int i=1,j,g=0;
    while(i<=n && g==0)
        {if(a[i][1]==b && a[i][2]==c)
            g=1;
        i++;}
    i--;
    for(j=i;j<n;j++)
    {
        a[j][1]=a[j+1][1];
        a[j][2]=a[j+1][2];
        a[j][3]=a[j+1][3];
    }
    n--;
}
void re(int a[][3],int &n,int b,int c,int r)
{
    elim(n,a,b,c);
    for(int i=1;i<=n;i++)
        if(distanta(b,c,a[i][1],a[i][2])<=r*r && (b!=a[i][1] || c!=a[i][2]))
            re(a,n,a[i][1],a[i][2],a[i][3]);
}
int main()
{
    int n,a[101][3],i,k,nr=0;
    ifstream f("date.in");
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>a[i][1]>>a[i][2]>>a[i][3];
    re(a,n,a[k][1],a[k][2],a[k][3]);
    for(i=1;i<=n;i++)
        cout<<a[i][1]<<" "<<a[i][2]<<" "<<a[i][3]<<endl;
    cout<<n;
    f.close();
    return 0;
}
