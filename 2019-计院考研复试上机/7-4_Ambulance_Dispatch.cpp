#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1050, INF = 0x3f3f3f3f;

int n, na,m, k;
int g[N][N];
int dist[N], sum[N];
int pre[N];
int cnt[N];
bool st[N];
int minsum = INF;

    //最短路，最小边
vector<int>tmp, path;

unordered_map<int, string>um;

int get(string x)
{
    if(x[0] == 'A')
    {
        um[n + stoi(x.substr(x.find('-') + 1))] =  x;
        return n + stoi(x.substr(x.find('-') + 1));
    }
    else
    {
        um[stoi(x)] =  x;
        return stoi(x);
    }
    
}

void dijkstra(int S)
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    memset(sum, 0x3f, sizeof sum);
    
    int last = -1;
    dist[S] = 0;
    sum[S] = 0;
    // priority_queue<PII, vector<PII>, greater<PII>> heap;
    // heap.push({0, S});
    // while(heap.size())
    // {
    //     auto t = heap.top();
    //     heap.pop();

    //     int ver = t.second, distance = t.first;

    //     if(st[ver]) continue;
    //     st[ver] = true;

    //     for(int j = 1; j <= n + na; j ++)
    //     {
    //         if(g[ver][j] != INF)
    //         {
    //             if(dist[j] > distance + g[ver][j])
    //             {
    //                 dist[j] = distance + g[ver][j];
    //                 heap.push({dist[j], j});
    //                 sum[j] = sum[ver] + 1;
    //                 pre[j] = ver;
    //             }
    //             else if(dist[j] == distance + g[ver][j] && sum[j] > sum[ver] + 1)
    //             {   
    //                 sum[j] = sum[ver] + 1;
    //                 pre[j] = ver;
    //             }
    //         }
    //     }
    // }
    for(int i = 0; i < n + na + 1; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n + na + 1; j ++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        st[t] = true;
        if(dist[t] == INF) break;

        for(int j = 1; j <= n + na +1; j ++)
            if(dist[j] > dist[t] + g[t][j])
                dist[j] = dist[t] + g[t][j];
    }

    // for(int i = 1; i <= 11; i ++) cout << dist[i] << " " ;
    // cout << endl;
}

void dfs(int u, int S, int sum, int &max_n, int& min_sum, int& ans_idx)
{
    if(u == S)
    {   
        if(cnt[tmp[tmp.size() - 2]] > max_n)
        {   
            max_n = cnt[tmp[tmp.size() - 2]];
            minsum = sum;
            ans_idx = tmp[tmp.size() - 2];
            path = tmp;
        }
        else if(cnt[tmp[tmp.size() - 2]] == max_n)
        {   
            if(sum < minsum)
            {
                minsum = sum;
                ans_idx = tmp[tmp.size() - 2];
                path = tmp;
            }

        }
        return ;
    }

    for(int i = 1; i <= n + na + 1 ; i ++)
    {   
        // if(i >= n && i <= n + na && cnt[i] <= 0) continue;

        if(dist[u] == dist[i] + g[u][i])
        {   
            // cout << u << " " << i << endl;
            
            tmp.push_back(i);
            dfs(i, S, sum + 1, max_n, min_sum, ans_idx);
            tmp.pop_back();
        }
    }
}

int main()
{
    cin >> n >> na;
    
    for(int i = 1; i <= na; i ++)
    {   
        cin >> cnt[i + n];
    }

    int S = n + na + 1;

  

    cin >> m;
    memset(g, 0x3f, sizeof g);
    while(m --)
    {
        string x, y;
        int c;
        cin >> x >> y >> c;
        int a = get(x), b = get(y);
        g[a][b] = g[b][a] = c;
    }

    for(int i = 1;i <= na; i ++)
    {
        g[i + n][S] = g[S][i + n] = 0;        
    }

    cin >> k;


    while(k --)
    {   
        for(int i = n + 1; i <= n + na; i ++) 
        {
            if(cnt[i] == 0)
            {
                g[S][i] = g[i][S] = INF;
            }
        }
        
        dijkstra(S);

        int D; cin >> D;    
        int max_n = -INF;
        int min_sum = INF;
        int ans_idx = 10;
        
        tmp.push_back(D);
        dfs(D, S, 0, max_n, min_sum, ans_idx);
        tmp.pop_back();

        // cout << ans_idx << endl;
        // cnt[ans_idx] --;
        
        if(ans_idx < n || ans_idx > n + na) cout << "All Busy\n";
        else
        {   
            path.pop_back();
            for(int i = path.size() - 1; i >= 0; i --)
            {   
                if(i != path.size() - 1) cout << " ";
                cout << um[path[i]];
            }
            cout << endl;
            cout << dist[D] << endl;
            cnt[ans_idx] --;
        }

        
        // else 
        // {   

        //     for(int i = ans_idx; i != S; i = pre[i])
        //     {
        //         cout << um[i] << " ";
        //     }
        //     cout << um[S];
        //     cout << endl;
        //     cout << dist[ans_idx] << endl;
        //     cnt[ans_idx] --;
        // }
    }


}