#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cmath>

using namespace std;

const int N = 1e5 + 10;
int w[N],p[N],d[N];
// unordered_map<int, int> leaf;
vector<int> isleaf;

int n;
double P, r, ans;

int dfs(int u)
{      
    if(d[u] != -1) return d[u];

    if(p[u] == -1) return d[u] = 0;
    else d[u] = dfs(p[u]) + 1;
}

int main()
{   
    memset(p, -1, sizeof p);
    memset(d, -1, sizeof d);
    cin >> n >> P >> r;
    for(int i = 0; i < n; i ++)
    {
        int k;
        cin >> k;
        if(!k)
        {
            cin >> w[i];
            isleaf.push_back(i);
        }
        while(k --)
        {
            int b;
            cin >> b;
            p[b] = i;
        }
    }

    for(auto i: isleaf)
    {
        ans += w[i] * P * pow(1 + r/100, dfs(i));
    }

    printf("%.1f", ans);

    


}
