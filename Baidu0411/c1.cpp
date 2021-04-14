/* 交换前缀

*/
#include<iostream>

using namespace std;
int n,m,h[105][26];
char s[105];
using ll=long long;
ll ans=1;
const ll mod=1e9+7;
int main()
{
 scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)
 {
  scanf("%s",s);
  for(int j=0;j<m;j++)
  // 记录每个位置上出现的字符
   h[j][s[j]-'A']=1;
 }
 for(int i =0; i < m; i++) {
     for (int j =0; j< 26; j++) {
         cout << h[i][j];
     }
     cout << endl;
 }
 for(int i=0;i<m;i++)
 {
  ll c=0;
  for(int j=0;j<26;j++)
   c+=h[i][j];
  ans=ans*c%mod;
 }
 printf("%lld\n",ans);
 return 0;
}