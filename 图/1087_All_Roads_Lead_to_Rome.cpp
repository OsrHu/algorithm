#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

const int N = 210;

int n, m;
int w[N];
int d[N][N];
int dist[N], cnt[N], cost[N], sum[N];
// 最短距离， 最短路径数量, 最大点权，最小点数
int pre[N];
bool st[N];

string city[N];
unordered_map<string, int> mp;

void dijkstra()
{   
    
    memset(dist, 0x3f, sizeof dist);
    memset(sum, 0x3f, sizeof sum);

    dist[1] = 0, cnt[1] = 1;
    sum[1] = 0;

    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 1; j <= n; j ++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;

        for(int j = 1; j <= n; j ++)
        {
            if(dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cost[j] = cost[t] + w[j];
                sum[j] = sum[t] + 1;
                cnt[j] = cnt[t];
                pre[j] = t;
            }
            else if(dist[j] == dist[t] + d[t][j])
            {   
                cnt[j] += cnt[t];
                if(cost[j] < cost[t] + w[j])
                {
                    cost[j] = cost[t] + w[j];
                    sum[j] = sum[t] + 1;
                    pre[j] = t;
                }
                else if(cost[j] == cost[t] + w[j])
                {
                    if(sum[j] > sum[t] + 1)
                    {
                        sum[j] = sum[t] + 1;
                        pre[j] = t;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> city[1];
    mp[city[1]] = 1;

    for(int i = 2; i <= n; i ++)
    {
        cin >> city[i] >> w[i];
        mp[city[i]] = i; 
    }

    memset(d, 0x3f, sizeof d);

    while(m--)
    {
        string x, y;
        int c;
        cin >> x >> y >> c;
        int a = mp[x], b = mp[y];
        d[a][b] = d[b][a] = c;
    }

    dijkstra();

    int T = mp["ROM"];

    cout << cnt[T] << " " << dist[T] << " " << cost[T] << " " << (int) cost[T]  / sum[T] << endl;

    vector<int> path;
    for(int i = T; i != 1; i = pre[i]) path.push_back(i);

    cout << city[1] ;
    for(int i = path.size() - 1; i >= 0; i --)
    {
        cout << "->" << city[path[i]];
    }

    return 0;


}