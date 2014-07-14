#include<iostream>
using namespace std;
//���� 3x+4y=1 ax+by=1
//�õ�һ���x0=-1��y0=1 ͨ��Ϊx=-1+4k,y=1-3k
inline __int64 extend_gcd(__int64 a,__int64 b,__int64 &x,__int64 &y)//ax+by=1����a,b��gcd��ͬʱ���һ��������Ŀ����С��������
{#include<iostream>
using namespace std;
template<class T>
class Modular_Linear_Equation_Solver{
private:
	//d��a��n�����Լ��
	//flag�ж�ax��b mod n�Ƿ��н�
	//x0��ax��b mod n���е�һ����������
	//min_result��ax��b mod n���е�һ����С��������
	//max_result��ax��b mod n���е�һ�������������
	T  x,y,d,x0,min_result,max_result;
	bool flag;
	void extend_euclid(T  a,T  b)
	{
		if(b==0){x=1;y=0;d=a;}
		else
		{
			extend_euclid(b,a%b);
			T  temp=x;
			x=y;
			y =temp-a/b*y;
		}
	}
public:
	void modular_linear_equation(T  a,T  b,T  n)
	{
		extend_euclid(a,n);
		if(b%d) flag=false;
		else
		{
			x0=(x*(b/d)%n+n)%n;
			min_result= x0%(n/d);
			max_result=min_result+(d-1)*(n/d);
			flag=true;
		}
	}
	T get_d(){return d;}
	bool get_flag(){return flag;}
	T get_min_result(){return min_result;}
	T get_max_result(){return max_result;}
	void print_all_result(int n){
		for(int i=0;i<d;i++)
			printf("%d\n",min_result+i*(n/d));
	}

};
int main()
{
	Modular_Linear_Equation_Solver<__int64 > ml;
	__int64  a,b,c,k;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k),a||b||c||k)
	{
		ml.modular_linear_equation(c,b-a,(__int64)1<<k);
		if(ml.get_flag())
			printf("FOREVER\n");
		else
			printf("%I64d\n",ml.get_min_result());
	}

}

    __int64 ans,t;
    if(b==0){x=1;y=0;return a;}
    ans=extend_gcd(b,a%b,x,y);t=x;x=y;y=t-(a/b)*y;
    return ans;
    }
//(a/b)%mod=c ��ԪΪp��(p*b)%mod=1
//(a/b)*(p*b)%mod=c*1%mod=c
// (p*b)%mod=1 �ȼ��� p*b-(p*b)/mod*mod=1����Ҫ��p��b��֪ �ȼ��� ax+by=1
//����x=p��x������Ԫ��,y=p/mod,a=b,b=b*mod ��ô����extend_gcd(b,b*mod,x,y)������(a/b)%mod����Ԫ�ȼ���a*p%mod
int main()
{
    __int64 a,b,x,y,c,gcd,mod,p;//ax+by=c
    while(cin>>a>>b>>c)
    {
          gcd=extend_gcd(a,b,x,y);
          if(c%gcd){cout<<"no solutions"<<endl;continue;}
          cout<<"x="<<x*c/gcd<<" y="<<y*c/gcd<<endl;
          }
    return 0;
}
