#include<fstream>
#include<iostream>
#include <cstring>
using namespace std;


void daoxu(int *a,int l);
void add(int *a,int *b,int lenA,int lenB,int scale);//lenA,lenB�ֱ�Ϊ����a��b�ĳ��ȣ�scaleΪ��������
int main()                                          //����ֻ�Ǽ����˰˽��Ƶļӷ�������scale=8�������Ҫ�����������Ƶ�������ֻ��Ҫ�ı�scale��ֵ
{

 char c;
 bool t=true;
 while(t)
 {

  int i=0,j=0;
  int a[105],b[105],lenA,lenB;
  memset(a,0,105);
  memset(b,0,105);
  while(c=cin.get())
  {
   if(c==' ')break;
   a[i++]=c-48;
   cout<<a[i-1];
  }
  lenA=i;
  cout<<"+";
  while(c=cin.get())
  {
   if(c=='\n'||c==EOF)break;
   b[j++]=c-48;
   cout<<b[j-1];
  }
  lenB=j;
  cout<<"=";
  daoxu(a,i);//�����鵹������,�Է������ļ�����
  daoxu(b,j);
  add(a,b,lenA,lenB,8);
  cout<<'\n';
  if(c==EOF)t=false;
 }
 return 0;

}
void daoxu(int *a,int l)
{
 int temp;
 for(int i=0,j=l-1;i<=j;i++,j--)
 {
  temp=a[i];
  a[i]=a[j];
  a[j]=temp;
 }
}
void add(int *a,int *b,int lenA,int lenB,int scale)
{

 int i,j;

 if(lenA>=lenB)//����*a�ĳ��ȱ�*b�ĳ��ȳ�
 {
  for(i=0;i<lenB;i++)
  {
   a[i]=a[i]+b[i];
   a[i+1]=a[i+1]+a[i]/scale;//������Ӧ���Ƶ�ת��
   a[i]=a[i]%scale;
  }
  while(a[i]>=scale)
  {
   a[i+1]=a[i+1]+a[i]/scale;
   a[i]=a[i]%scale;
   i++;
  }
  int max=lenA>i?lenA:i;//�Ƚ�lenA��i�Ĵ�С��ʹ�����ʽ��ȷ
  if(max>i)
  for(int j=max-1;j>=0;j--)cout<<a[j];
  else for(int j=i;j>=0;j--)cout<<a[j];
 }
 else
 {
  for(i=0;i<lenA;i++)
  {
   b[i]=b[i]+a[i];
   b[i+1]=b[i+1]+b[i]/scale;
   b[i]=b[i]%scale;
  }
  while(b[i]>=scale)
  {
   b[i+1]=b[i+1]+b[i]/scale;
   b[i]=b[i]%scale;
   //j--;
  }
  int max=lenB>i?lenB:i;
  if(max>i)
  for(int j=max-1;j>=0;j--)cout<<b[j];
  else for(int j=i;j>=0;j--)cout<<b[j];
 }
}
