#include<iostream>
using namespace std;
using ll=long int;
ll n,m,x,y,q;
int main()
{
 scanf("%lld%lld%lld",&n,&m,&q);
 while(q--)
 {
  scanf("%lld%lld",&x,&y);
  if(x<=(n+1)/2)
   printf("%lld\n",(2*x-2)*m+y);
  else
   printf("%lld\n",(2*(1+n/2-(x-(n+1)/2))-1)*m+y);
 }
 return 0;
}
