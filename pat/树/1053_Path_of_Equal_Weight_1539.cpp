#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 110;

int n,m,sum;
int h[N], e[N], ne[N], idx;
int w[N];
bool st[N];
vector<int> path;
vector<vector<int>> ans; 

void add(int a, int b)
{
    e[idx]=b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int s, vector<int>& path)
{   

    if(h[u] == -1)
    {   
        if(s == sum)
        {   
            ans.push_back(path);
            return ;
        }
        
    }


    for(int i = h[u]; ~i; i=ne[i])
    {
        int j = e[i];
        path.push_back(w[j]);
        s += w[j];
        dfs(j, s, path);
        s -= w[j];
        path.pop_back();

        

    }

}

int main()
{   
    memset(h, -1, sizeof h);
    cin >> n >> m >> sum;
   
    for(int i = 0 ; i < n; i ++ )
    {
        cin >> w[i];
    }
    

    for(int i = 0; i < m; i ++)
    {
        int id,k;
        cin >> id >> k;
        for(int j = 0; j < k; j ++)
        {
            int b;
            cin >> b;
            add(id, b);
        }
    }

    path.push_back(w[0]);
    dfs(0, w[0], path);

    sort(ans.begin(), ans.end(), greater<vector<int>>());
    
    for(auto p: ans)
    {
        cout << p[0];
        for(int i = 1; i < p.size() ; i ++) cout << " " << p[i];
        cout << endl;
    }
    return 0;
}