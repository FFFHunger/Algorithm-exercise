#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,top,b[500010];
long long ans;
int main()
{
    int i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        while(top>1 && b[top-1]>=b[top] && b[top]<=x) 
        {
            ans+=min(b[top-1],x);
            top--;
        }
        b[++top]=x;
    }
    sort(b+1,b+1+top);
    for(i=1;i<=top-2;i++) ans+=b[i];
    cout<<ans<<endl;
    return 0;
}