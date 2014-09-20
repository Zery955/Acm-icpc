/*
    yao���������һ�ֲ��Լ��Ż����Ĳ���һ����һ��������N�鼦�ţ����1~N�������������ǵ��Լ����ʵ�Ŀ��
    ��û��ʵ�֣�����ֻ�ܿ��ǰ���N�鼦�ŷֳɺܶ�ѣ����������ֲ�������һ�� ����i j ���ϲ�i��j �����鼦������
    �Ķѣ��ڶ��ֲ����ǲ�ѯ��k��ļ��Ŷ����ж��ٿ鼦�š�


    0< N,M <100000

    hint: 2 2 1 ��1����2����2����2����3����1

    input:
        5 4
        0 1 2
        1 2
        0 3 4
        1 2
    ouput:
        1
        2
*/


#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

#define MAXN 500000

int fa[MAXN],a[MAXN],bit[MAXN];

int ufind(int x){
    return x==fa[x]?x:fa[x] = ufind(fa[x]);
}
int lowbit(int x){
    return x&-x;
}
int add(int x,int d){
    while(x<=MAXN){
        bit[x] +=d;
        x+=lowbit(x);
    }
    return 0;
}

int find_k(int k){
    int now = 0;
    int ret = 0;
    for(int i = 20;i>=0;i--){
        now += (1<<i);
        if( now >= MAXN || ret+bit[now]>=k){
            now-=(1<<i);
        }else{
            ret+=bit[now];
        }
    }
    return now+1;
}

int main(){
    freopen("in","r",stdin);

    freopen("out","w",stdout);
    int N,M;
    int tN;
    while(scanf("%d%d",&N,&M)!=EOF){
        for(int i=0;i<=N;i++)fa[i]=i;
        for(int i=0;i<=N;i++)a[i] = 1;
        tN = N;
        add(1,N);

        for(int i=0;i<M;i++){
            int op;
            scanf("%d",&op);
            if(op==0){
                int x,y;
                scanf("%d %d",&x,&y);
                if((x>tN || y>tN)){
                    cout<<x<<" "<<y<<" "<<tN<<endl;
                }
                assert (! (x > tN || y > tN));
                int fx = ufind(x),fy = ufind(y);
               // cout<<fx<<" "<<fy<<endl;
                if( fx == fy) continue;
                else{
                    add( a[fx] , -1 );
                    add( a[fy] , -1 );
                    add( a[fx]+ a[fy] ,1);
                    a[fx] += a[fy];
                    fa[fy] = fx;
                    N--;
                    //cout<<N<<endl;
                }
            }else{
                int k;
                scanf("%d",&k);
                k = N - k+1;
                int ans = find_k(k);
                printf("%d\n",ans);
            }
        }
    }

    return 0;
}
