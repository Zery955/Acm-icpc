#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

#define MAXV 500000
struct edge{
    int to,cap,rev;
};
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];

void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}


void bfs(int s){
    CLR(level,-1);
    queue<int> que;
    level[s]= 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int i=0;i<G[v].size();i++){
            edge& e = G[v][i];
            if( e.cap>0 && level[e.to]<0){
                level[e.to] = level[v] +1;
                que.push(e.to);
            }
        }
    }

}

int dfs(int v,int t,int f){
    if( v==t)return f;

    for(int &i = iter[v];i<G[v].size();i++){
        edge &e = G[v][i];
        if( e.cap>0 && level[v]<level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow = 0;
    for(;;){
        bfs(s);
        if(level[t]<0)return flow;
        CLR(iter,0);
        int f;
        while( f= dfs(s,t,INF)>0){
            flow +=f;
        }
    }
}
int N,F,D;

int main()
{
	ios::sync_with_stdio(false);
    #ifdef LOCAL
        freopen("in","r",stdin);
    #endif

    cin>>N>>F>>D;

    //0-F-1;
    //F- F+N-1;
    //F+N - F+2*N-1;
    //F+2*N--F+2*N+D-1;
    int s = F+2*N+D, t = s+1;
    for(int i=0;i<N;i++){
        int tf,td;
        cin>>tf>>td;
        for(int j=0;j<tf;j++){
            int a;cin>>a;
            add_edge( a-1,i+F ,1);
        }
        for(int j=0;j<td;j++){
            int a;cin>>a;
            add_edge(F+N+i , F+2*N+a-1,1);
        }
    }
    for(int i=0;i<N;i++){
        add_edge(F+i,F+N+i,1);
    }
    for(int i=0;i<F;i++){
        add_edge(s,i,1);
    }

    for(int i=0;i<D;i++){
        add_edge(F+2*N+i,t,1);
    }
    int ret = max_flow(s,t);
    cout<<ret<<endl;
    return 0;
}

