#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <fstream.h>
ifstream fin("data.in");
ofstream fout("data.out");
#define cin fin 
#define cout fout 
const MAX=30;
typedef struct List
{
	char name[MAX];
	int  No;        //��ǰ�ڵ���
	int  price;     //Ͷ��۸�
} List;
//List array[4000];  //�ڵ�����

int bubble(List *a,int n)
{
    int i,j,k=0,flag=0,cnt=1,min,sum;	
	int *num;
	List tmp;
    num=new int[n];
	num[0]=1;
	for (i=0; i<n-1;i++){  //ð�ݷ����򣬽�С�����³�
		for (j=n-1; j>i;j--){
			if (a[j].price<a[j-1].price) {
				tmp=a[j];  //temp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
		if (i>0){         //ͳ����ͬ���ĸ���
			if(a[i].price==a[i-1].price){   //ÿ�αȽ�����Ԫ�صĹ�ϵ����ͳ��
				flag=1;
				cnt++;
			}
			else{
				num[k]=cnt;
				k++;
				cnt=1;
			}
		}
	}
	if ((n>1)&&(a[n-1].price==a[n-2].price))  //������
		num[k]=cnt+1;
	else{
		num[k]=cnt;
		k++;
		num[k]=1;
	}

	min=num[0];j=0;sum=0;             //������С����λ��
	if (flag){
		for (i=1; i<=k;i++){
			
			if(min>num[i]) {
				min=num[i];
				j=i;
			}
		}
		
		for (i=0; i<j;i++) sum+=num[i];  //ͳ������ͬͶ���ʱ��СͶ������λ��
		tmp=a[sum];    //�ҵ�λ�ú��ʼ��
		for (i=1; i<min;i++){           //ȷ����С��ŵ���
			if (tmp.No>a[sum+i].No) {
				tmp=a[sum+i];
			}
		}
	}
	if (!flag)	tmp=a[0];          //�Բ�ͬͶ��۵���СͶ����
	cout<<"The winner is "<<tmp.name<<"."<<endl;   
	cout<<"The price is "<<tmp.price<<"."<<endl<<endl;

	return 0;

}

int main(){
   int T,i;
   long U,M,j,count;
   List *array;
   cin>>T;
   for(i=0;i<T;i++){
	   cout<<"Case "<<i+1<<":"<<endl;
	   cin>>U>>M;
	   array=new List[M];
	   count=0;
	   for(j=0;j<M;j++){
		   cin>>array[count].name>>array[count].price;
		   array[count].No=count;
		   if((array[count].price<=U)&&(array[count].price>0)) 
			   count++;
	   }
	   bubble(array,count);
   }
   return 0;
}