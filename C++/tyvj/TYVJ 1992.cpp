#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0;i<n;++i)
using namespace std;
const int q[2][2] = {{101,100}, {100,101}};
 
int tn, home, qa, qb;
char str[100];
 
int main()
{
    scanf("%d", &tn);
    int a,b,c;
    rep(vi, tn)
    {
        do scanf("%s", str); while ( str[0]!='h' && str[1]!='w' );
        if (str[0]=='h') home = 1; else home = 0;
        rep(i,2) scanf("%s",str); scanf("%d", &a);
        rep(i,3) scanf("%s",str); scanf("%d", &b);
        qa = a*q[home][0], qb = b*q[home][1];
        
        for (a=0;a<=30;++a) if ( qa+ a*q[!home][0] >= qb ) {printf("%d ", a); goto next;}
        printf("30 ");
next :
        for (a=30;a>=0;--a) if ( qa+ a*q[!home][0] <= qb+ 30*q[!home][1] ) {printf("%d\n", a); goto n2xt;}
        printf("0\n");
n2xt :  ;
    }
    system("pause");
    return 0;
}
