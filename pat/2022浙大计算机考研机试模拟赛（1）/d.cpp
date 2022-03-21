#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

typedef long long ll;

const int N = 510, M = 1e5 + 10;

int n, m, S;
ll g[N][N],sum[N][N];
ll w[N];
ll dist[N];
bool st[N];
vector<int> pre[N];
vector<int> v[N];

int p[N]; 

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}


bool cmp(int a, int b)
{
    if(w[a] != w[b]) return w[a] > w[b];
    return a > b;
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[S] = 0;


    for(int i = 0 ; i < n ; i ++)
    {
        int t = -1; 
        for(int j = 0; j < n; j ++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        st[t] = true;
        
        for(int j = 0; j < n ; j ++)
            if(dist[j] > dist[t] + g[t][j])
            {
                dist[j] = dist[t] + g[t][j];
                pre[j].clear();
                pre[j].push_back(t);
            }
            else if(dist[j] == dist[t] + g[t][j])
            {
                pre[j].push_back(t);
            }
    }
}

vector<int>tmp, path;
void dfs(int u)
{   
    tmp.push_back(u);
    if(u == S)
    {   
        vector<int> ttt = tmp;
        reverse(ttt.begin(), ttt.end());
        if(path.size() == 0 || ttt < path)
        {
            path = ttt;
        }
    }

    for(int i = 0; i < pre[u].size(); i ++)
    {
        dfs(pre[u][i]);
    }
    tmp.pop_back();
}

int main()
{   
    
    cin >> n >> m >> S;
    
    for(int i = 0; i < n; i ++) p[i] = i;
    memset(g, 0x3f, sizeof g);

    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = g[b][a] = min((ll)c, g[a][b]);
        w[a] += c;
        w[b] += c;
        sum[a][b] += 1;
        sum[b][a] += 1;
    }
    
    for(int i = 0; i < n; i ++)
    {   
        for(int j = 0; j < n; j ++)
        {
            if(sum[i][j] >= 2)
            {       
                int pa = find(i), pb = find(j);
                if(pa != pb)
                {
                    if(w[pb] > w[pa])
                    {
                        p[pa] = pb;
                    }
                    else if(w[pb] < w[pa])
                    {
                        p[pb] = pa;
                    }
                    else if(pa > pb)
                    {
                        p[pb] = pa;
                    }
                    else p[pa] = pb;
                }
            }
        }
    }
    
    vector<int> T;
    for(int i = 0; i < n; i ++)
    {
        if(p[i] == i) T.push_back(i);
    }
    cout << T.size() << endl;
    for(int i = 0; i < T.size() ; i ++)
    {
        printf("%d", T[i]);
        printf(i + 1 < T.size() ? " " : "\n");
    }
    
    dijkstra();
    for(int i = 0; i < T.size(); i ++)
    {   
        if(dist[T[i]] == 0x3f3f3f3f3f3f3f3f)
        {
            cout << "Wait for tomorrow\n";
            exit(0);
        }
    }

    for(int i = 0; i < T.size(); i ++)
    {
        int end = T[i];
         
        int sum  = 0;
        path.clear();
        dfs(end);

        // for(int i = 0; i < path.size() - 1; i ++)
        // {
        //     sum += g[path[i]][path[i + 1]];
        // }
        cout << (ll)dist[end] * 2;
        cout << " ";
        for (int j = 0; j < path.size(); j++) {
            printf("%d", path[j]);
            printf(j + 1 < path.size() ? "->" : "\n");
        }
        
        
    }

}