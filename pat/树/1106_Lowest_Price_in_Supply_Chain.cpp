#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
double P,r;
int h[N], e[N], ne[N], idx;
int mindepth = INF;
int cnt[N];
vector<int> is_leaf;
int ansi ;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int depth)
{
    if(h[u] == -1)
    {      
        ansi = u;
        cnt[depth] ++;
        mindepth = min(mindepth, depth);
        return;
    }

    for(int i = h[u]; ~i; i = ne[i])
    {
        dfs(e[i], depth + 1);
    }

}

int main()
{   
    memset(h , -1, sizeof h);
    cin >> n >> P >> r;
    for(int i = 0; i < n;i ++ )
    {
        int k;
        cin>>k;
        if(!k)
        {
            is_leaf.push_back(i);
        }

        while(k --)
        {
            int son;
            cin >> son;

            add(i, son);
        }
    }


    dfs(0, 0);

    printf("%.4f %d",P * pow((1 + r / 100), mindepth), cnt[mindepth]);
    
}
