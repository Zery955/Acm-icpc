#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

const int MAXN=40000;//�����10000�Ľ׳ˣ���Ϊ40000�͹���
int f[MAXN];
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        cout<<n<<"!="<<endl;
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=2;i<=n;i++)
        {
            int c=0;
            for(j=0;j<MAXN;j++)
            {
                int s=f[j]*i+c;
                f[j]=s%10;
                c=s/10;
            }
        }
        int cnt = 0;
        for(j=MAXN-1;j>=0;j--)
           if(f[j]) break;//����ǰ��0
        for(i=j;i>=0;i--)
        {
            printf("%d",f[i]);
            cnt++;
            if(cnt%80==0)
                cout<<endl;
        }

        printf("\n");
    }
    return 0;
}
