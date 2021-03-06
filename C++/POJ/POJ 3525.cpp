#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define N 310
#define eps 1e-10
using namespace std;
struct point{
    double x,y;
}Inter[N], P[N];
struct bpm{
    point a,b; // to right
    double alp; 
}L[N],Q[N];
int n, psz;

point operator -(const point &a,const point &b){
    point c;c.x=a.x-b.x;c.y=a.y-b.y;
    return c;
}

point operator +(const point &a,const point &b){
    point c;c.x=a.x+b.x;c.y=a.y+b.y;
    return c;
}

double operator *(const point &a,const point &b){
    return a.x*b.y-a.y*b.x;
}
double Turnto(point a,point b,point c){//>0 to right 
    return (c-a)*(b-a);
}
void addbpm(int now,point a,point b){
    L[now].a=a;L[now].b=b;
    L[now].alp=atan2(a.y-b.y,a.x-b.x);
}
bool comp(const bpm &a,const bpm &b){
    if(fabs(a.alp-b.alp)<eps){
        if(Turnto(a.a,a.b,b.a)>-eps) return 0;
        else return 1;
    }
    else return a.alp<b.alp;
}
point Get_Interpoint(bpm A,bpm B){
    point Ans;double k1,k2,k3;
    k1=(B.a-A.a)*(A.b-A.a);
    k2=(A.b-A.a)*(B.b-A.a);
    k3=k1/(k1+k2);
    Ans.x=B.a.x+k3*(B.b.x-B.a.x);
    Ans.y=B.a.y+k3*(B.b.y-B.a.y);
    return Ans;
}
void init(){
    point A,B,C,D;
    A.x=0;A.y=0;B.x=0;B.y=10000;C.x=10000;C.y=10000;D.x=10000;D.y=0;
    addbpm(++n,A,B);addbpm(++n,B,C);addbpm(++n,C,D);addbpm(++n,D,A);
}
int HalfPlaneInter(){
    int i,t=1,w=1;        
    sort(L+1,L+1+n,comp);
    Q[1]=L[1];
    for(i=2;i<=n;i++){
        if(fabs(L[i].alp-L[i-1].alp)<eps) continue;
        bpm now=L[i];
        while(t<w && Turnto(now.a,now.b,Inter[w-1])<eps) w--;
        while(t<w && Turnto(now.a,now.b,Inter[t])<eps) t++;
        Q[++w]=now;Inter[w-1]=Get_Interpoint(Q[w-1],Q[w]);
    }
    int l=-1,r=t+1;
    while(l<t || r>w){
        l=t;r=w;
        while(t<w && Turnto(Q[t].a,Q[t].b,Inter[w-1])<eps) w--;
        while(t<w && Turnto(Q[w].a,Q[w].b,Inter[t])<eps) t++;
    }
    if(w-t<2){
        return -1;
    }
    double ans=0;
    Q[++w]=Q[t];Inter[w-1]=Get_Interpoint(Q[w-1],Q[w]);
    Inter[w]=Inter[t];
    for(i=t;i<w;i++) ans+=Inter[i]*Inter[i+1];
    if(ans<0) ans=-ans;
    ans*=0.5;
    return 1;
}

inline double dist(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool build(double mid){
    n = 0;
    for(int i = psz; i > 1; i--){
        point pp;
        pp.x = P[i - 1].x - P[i].x;
        pp.y = P[i - 1].y - P[i].y;
        double xx = pp.x;
        pp.x = pp.y; pp.y = -xx;
        pp.x *= mid / dist(P[i-1], P[i]);
        pp.y *= mid / dist(P[i-1], P[i]);
        addbpm(++n, P[i] + pp, P[i-1] + pp);
    }
    init();
}

bool check(double mid){
    build(mid);
    if(HalfPlaneInter() == -1) return 0;
    else return 1;
}

int main(){
    while(scanf("%d", &psz)){
        if(!psz) break;
        for(int i = 1; i <= psz; i++){
            scanf("%lf%lf", &P[i].x, &P[i].y);
        }
        P[++psz] = P[1];
        double l = 0.0, r = 1e6, mid;
        for(int i = 1; i <= 1000; i++){
            mid = (l + r) * 0.5;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%6f\n", l);
    }

    return 0;
}
