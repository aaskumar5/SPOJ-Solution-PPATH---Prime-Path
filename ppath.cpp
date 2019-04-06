#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> umap;
vector<int> v;
vector<int> g[10000];
char ch[]={'0','1','2','3','4','5','6','7','8','9'};
bool check(int n)
{
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void checkCombination(int n)
{
    string str=to_string(n);
    string s=str;
    for(int i=0;i<=3;++i)
    {
        for(int j=0;j<=9;++j)
        {
            if(s[i]!=ch[j])
            {
                s[i]=ch[j];
                int temp=stoi(s);
               // cout<<temp<<"--- > ";
                if(umap[temp]>0)
                {
                    g[n].emplace_back(temp);
                    //cout<<temp<<" got it try next ";
                }
                s=str;
            }
        }
    }
}
void setup()
{
    for(int i=1000;i<=9999;++i)
    {
        if(check(i))
        {
            umap[i]++;
            v.emplace_back(i);
        }
    }
    for(auto i : v)
      checkCombination(i);

}
void dfs(int start,int n2)
{
    //int siz=v.size();
    vector<int> height(10000,-1);
    vector<bool> visit(10000,false);
    queue<int> q;
    q.push(start);
    height[start]=0;
    visit[start]=1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto i : g[temp])
        {
            if(!visit[i])
            {
                visit[i]=1;
                q.push(i);
                height[i]=height[temp]+1;
            }
        }
    }
    if(height[n2]>=0)
    {
        cout<<height[n2]<<endl;
    }
    else
        cout<<"Impossible"<<endl;

}
main()
{
    int t; cin>>t;
    setup();

    //for(auto i : g[v[1]]) cout<<i<<" ";
    while(t--)
    {
        int n1,n2; cin>>n1>>n2;
        dfs(n1,n2);

    }
}
