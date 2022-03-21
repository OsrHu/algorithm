#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
#include<set>
#include<sstream>
#include<cctype>
#include<queue>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m, k;
int g[N][N], w[N][N];
int dist[N], cost[N];
int id[N], idback[N];
bool st[N];
int test[N];
vector<int> v;

bool topsort()
{
    queue<int>q;

    for(int i = 0; i < n; i ++)
        if(id[i] == 0)
            q.push(i);

    while(q.size())
    {
        int t = q.front();
        v.push_back(t);
        q.pop();

        for(int i = 0; i < n; i ++)
        {
            if(g[t][i] != INF)
            {
                id[i]--;
                if(id[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
    return v.size() == n;  
}

int pre[N];
void dijkstra(int S)
{   
    memset(dist, 0x3f, sizeof dist);
    // memset(cost, 0x3f, sizeof cost);
    dist[S] = 0;
    cost[S] = 0;
    
    for(int i = 0; i <= n; i ++ )
    {
        int t = -1;
        for(int j = 0; j <= n; j ++)
        if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
    
        for(int j = 0; j <= n; j ++)
        {
            if(dist[j] > dist[t] + g[t][j])
            {
                dist[j] = dist[t] + g[t][j];
                cost[j] = cost[t] + w[t][j];
                pre[j] = t;
            }
            else if(dist[j] == dist[t] + g[t][j] && cost[j] < cost[t] + w[t][j])
            {
                cost[j] = cost[t] + w[t][j];
                pre[j] = t;
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(w, 0x3f, sizeof w);
    while(m --)
    {
        int a, b, s, d;
        cin >> a >> b >> s >> d;
        g[a][b] = s;
        w[a][b] = d;
        // od[a] ++;
        id[b] ++;
    }
    memcpy(idback, id,sizeof id);

    vector<int>S;

    for(int i = 0; i < n; i ++)
    {
        if(id[i] == 0) 
        {
            S.push_back(i);
        }
        
    }


    for(int i = 0; i < S.size(); i ++)
    {
        g[n][S[i]] = 0;
        w[n][S[i]] = 0;
    }
    
   

    if(!topsort())
    {
        cout << "Impossible." << endl;

        cin >> k;

        while(k--)
        {   
            int t;
            cin >> t;
            if(idback[t] == 0)
            {
                printf("You may take test %d directly.\n", t);
            }
            else
            {
                printf("Error.\n");
            }
        }
    }
    else
    {
        cout << "Okay." << endl;

        dijkstra(n);

    
        cin >> k;
        while(k --)
        {
            int t;
            cin >> t;
            
            vector<int>ans;
            for(int i = t; i != n; i = pre[i])
            {
                ans.push_back(i);
            }

            if(ans.size() == 1)
            {
                printf("You may take test %d directly.\n", t);
            }
            else
            {   
                reverse(ans.begin(), ans.end());
                for(int i = 0; i < ans.size(); i ++)
                {
                    if(i != 0) cout << "->";
                    cout << ans[i];
                }
                cout << endl;
            }
        }


    }

}
