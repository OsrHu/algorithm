#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m;
struct Node
{
    int v, run = INF;
    bool operator<(const Node& t)const
    {
        if(run != t.run) return run > t.run;
        return v > t.v;
    }
}nodes[N];
vector<int>ans[N];
int main()
{
    cin >> n >> m;
    priority_queue<Node, vector<Node>> q;
    for(int i = 0; i < n; i ++)
    {
        int t;
        cin >> t;
        nodes[i].v = t;
        
    }
    for(int i = 0; i < m; i ++)
    {   
        nodes[i].run = 1;
        q.push(nodes[i]);
    }
    
    int j = m;
    int cnt = 0;
    while(!q.empty())
    {       
        auto t = q.top();
        q.pop();
        if(t.run != INF) 
        {   
            cnt = max(cnt, t.run);
            ans[t.run].push_back(t.v);
        }
        
        if(j < n)
        {
            
            if(nodes[j].v < t.v)
            {
                nodes[j].run = t.run + 1;
            }
            else
            {
               nodes[j].run = t.run;
            }
            

            q.push(nodes[j]);
        }
        
        j ++;
        
    }

    for(int i = 1; i <= cnt; i ++)
    {
        for(int j = 0; j < ans[i].size(); j ++)
        {
            if(j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
}