//This is the efficient segment tree implementation without any memory waste
#include<bits/stdc++.h>
using namespace std;

void build(int a[],int segtree[],int n)
{
    for(int i=0;i<n;i++)
    {
        segtree[n+i]=a[i];
    }
    for(int i=n-1;i>0;i--)
    {
        segtree[i]=segtree[2*i]+segtree[2*i+1];
    }
}

int getsum(int segtree[],int l,int r,int n)
{
    int res=0;
    for(l+=n,r+=n;l<r;l/=2,r/=2)
    {
        if(l&1)
        {
            res+=segtree[l++];
        }
        if(r&1)
        {
            res+=segtree[--r];
        }
    }
    return res;
}

void update(int segtree[],int i,int value,int n)
{
    segtree[i+n]=value;
    i=i+n;
    for(int j=i;j>1;j/=2)
    {
        segtree[j/2]=segtree[j]+segtree[j-1];
    }
}
int main()
{
    int a[]={1,3,5,7,9,11};
    int n=sizeof(a)/sizeof(a[0]);
    int segtree[2*n];
    build(a,segtree,n);

    cout<<"Tell me the range whose sum you want to find\n";
    int l,r;
    cin>>l>>r;
    int sum=getsum(segtree,l,r,n);
    cout<<sum<<'\n';
    cout<<"Tell me the index whose value you want to update and to what\n";
    int i,value;
    cin>>i>>value;
    update(segtree,i,value,n);

    cout<<"Now tell the range whose sum you want to find\n";
    int lu,ru;
    cin>>lu>>ru;
    int sumu=getsum(segtree,lu,ru,n);
    cout<<sumu<<'\n';

}