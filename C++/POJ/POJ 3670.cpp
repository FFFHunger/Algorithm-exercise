#include<stdio.h>
                  //arr������洢ԭʼ���� maxarr������洢������  maxarr[len]Ϊ����Ϊlen���������� 
                 //���һ����������ֵ��Ҳ������Сֵ��lis�У��� �� ��һ����������ֵ��Ҳ�������ֵ��lds�У���
int n;
int search_lis(int maxarr[],int len,int x){
	int l=0,r=len-1,mid;
	while(l<=r){//��ʼѰ��x�ܴ����λ�� ��lis�У���λ��Ϊ x��ǰһ�����󣬱Ⱥ�һ����С�����صľ��������һ��������λ��
		mid=(l+r)/2;
		if(maxarr[mid]<=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int lis(int arr[]){
	int maxarr[30010],len=1,pos;
	maxarr[0]=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>=maxarr[len-1]){//�����������maxarr���������������һ���������ҾͰѴ����ŵ�maxarr��β
			maxarr[len++]=arr[i];
		}
		else{//���� �ҵ����ʵ�λ�÷���
			pos=search_lis(maxarr,len,arr[i]);
			maxarr[pos]=arr[i];
		}
	}
	return len;
}
int search_lds(int maxarr[],int len,int x){
	int l=0,r=len-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(maxarr[mid]>=x){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return r+1;
}
int lds(int arr[]){
	int maxarr[30010],len=1;
	maxarr[0]=arr[0];
	for(int i=1;i<n;i++){
		if(maxarr[len-1]>=arr[i]){
			maxarr[len++]=arr[i];
		}
		else{
			int pos=search_lds(maxarr,len,arr[i]);
			maxarr[pos]=arr[i];
		}
	}
	return len;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int len=0,maxarr[30010],arr[30010];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		int LIS=lis(arr);
		int LDS=lds(arr);
		int max=LIS>LDS?LIS:LDS;
		printf("%d\n",n-max);
	}
	while(1);
	return 0;
}
