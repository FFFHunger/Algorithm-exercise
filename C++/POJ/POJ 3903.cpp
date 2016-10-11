#include <iostream>
 using namespace std;
 
 const int MAXN = 100005;
 int num, sub[MAXN];
 
 int main()
 {
     int n, top;
     while(cin >> n)
     {
         sub[0] = -1; //���ǵ���һ��Ԫ�ؿ�����0
         top = 0;
         for(int i = 0; i < n; i++)
         {
             cin >> num;
             if(num > sub[top])
             {
                 sub[++top] = num;
             }
             else
             {
                 //�˴��Ƕ����Ż�
                 int high = top, low = 1, mid;
                 while(low <= high)
                 {
                     mid = (high + low) / 2;
                     if(num > sub[mid])
                     {
                         low = mid + 1;
                     }
                     else
                     {
                         high = mid - 1;
                     }
                 }
                 sub[low] = num;
             }
         }
         cout << top << endl;
     }
     while(1);
     return 0;
 }
