/*
    yao��ÿ��Լ��Ŷ������˷ǳ�ǿ׳�ļ��⣬�����������ܶ�ǿ׳�Ĺ�������޺�����Ϸ��
    ÿֻ����������ֵs������w��yao�綨��Σ��ֵ�ǵ���һֻ�����������й�������֮�ͼ�ȥ��ֻ������
    ����ֵ������yao�������������С�����Σ��ֵ

    input:
        3
        10 3
        2 5
        3 3
    output:
        2
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 50000+10
#define LL long long
#define min(x,y) x<y?x:y
#define max(x,y) x<y?y:x
int N;

struct P
{
    LL w,s;
    bool operator < (const P& x) const
    {
        return (w+s)<(x.w+x.s);
    }
};

P cow[MAXN];


int main()
{
    //freopen("bin","r",stdin);
    //freopen("bout","w",stdout);
    while(cin>>N){
        //cout<<N<<endl;
        LL l =0 , r= 0;
        for(int i=0;i<N;i++)
        {
            cin>>cow[i].w>>cow[i].s;
           // scanf("%lld%lld",&cow[i].w,&cow[i].s);
        }
        sort( cow,cow+N);
        LL ans = -10000000000;
        LL sum =0;
        for(int i=0;i<N;i++)
        {
            ans = max( sum - cow[i].s, ans);
            sum+= cow[i].w;
        }
        cout<<ans<<endl;
        //printf("%lld\n",ans);
    }
    return 0;
}
