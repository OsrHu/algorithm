#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;

int n, m, S, T;
int w[N];
int d[N][N];
int dist[N], cnt[N], sum[N];
bool st[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0, cnt[S] = 1, sum[S] = w[S];

    for(int i = 0; i < n; i ++)
    {
        int t = -1;
        for(int j = 0; j < n; j ++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }

        st[t] = true;

        for(int j = 0; j < n; j ++)
        {
            if(dist[j] > dist[t] + d[t][j])
            {
                dist[j] = dist[t] + d[t][j];
                cnt[j] = cnt[t];
                sum[j] = sum[t] + w[j];
            }
            else if(dist[j] == dist[t] + d[t][j])
            {
                cnt[j] += cnt[t];
                sum[j] = max(sum[j], sum[t] + w[j]);
            }
        }
    }
}

int main()
{   
    cin >> n >> m >> S >> T;
    for(int i = 0; i < n; i ++) cin >> w[i];

    memset(d, 0x3f, sizeof d);

    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }

    dijkstra();

    cout << cnt[T] << " " << sum[T] << endl;

    return 0;


}