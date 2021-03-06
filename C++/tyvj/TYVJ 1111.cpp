#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int map1[201][201];
int map2[201][201];
int n,num[201];
int sag;
bool mark[201];
int ans;
void dfs1(int x)
{
     mark[x]=1;
     int i;
     for(i=1;i<=map1[x][0];i++)
     {
     if(!mark[map1[x][i]])
     dfs1(map1[x][i]);
     }
     sag++;
     num[sag]=x;
}
void dfs2(int x)
{
     mark[x]=1;
     int i;
     for(i=1;i<=map2[x][0];i++)
     {
     if(!mark[map2[x][i]])
     dfs2(map2[x][i]);
     }
}
int main()
{
    int a,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
      while(scanf("%d",&a))
      {
         if(a==0) break;
         map1[i][0]++;map1[i][map1[i][0]]=a;
         map2[a][0]++;map2[a][map2[a][0]]=i;
      }
    }    
    sag=0;
    for(i=1;i<=n;i++)
    {
    if(!mark[i])
    dfs1(i);
    }
    for(i=1;i<=n;i++)
    mark[i]=0;
    for(i=n;i>=1;i--)
    {
      if(!mark[num[i]])
      {ans++;dfs2(num[i]);}
    }
    cout<<ans;
    system("pause");
    return 0;
} 
