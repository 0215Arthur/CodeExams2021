#include<iostream>
#include<map>
using namespace std;
map<string,int>cnt;
map<string,string>fir;
int main()
{
 string s;
 while(cin>>s)
 {
  string ori,ss;

  for(int i = 0; i <s.size(); i++) {
        char c = s[i];
       if(c>='A'&&c<='Z'||c>='a'&&c<='z')
        ori+=c;
    s=ori;

    if(c>='A'&&c<='Z')
        c=c-'A'+'a';
    if(!fir.count(s))
        fir[s]=ori;
    cnt[s]++;
    
 }
 pair<string,int> ans=*cnt.begin();
 for( map<string, int>::iterator p = cnt.begin(); p != cnt.end(); p++) {
  if(p -> second > ans.second||p->second==ans.second&&p->first<ans.first)
   ans=*p;
}
 cout<<fir[ans.first]<<" "<<ans.second;
 return 0;
}