#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e4 + 10, M = 2 * N ;

int n, m, k;
int e[M], ne[M], h[N], idx;
bool flag;
bool st[N];
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    st[u] = true;

    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(color[u] == color[j])
        {
            flag = false;
            break;
        }

        if(!st[j])
        {
            dfs(j);
        }
    }


}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m --)
    {
        int a,b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    } 

    cin >> k;

    while(k --)
    {           
        memset(st, 0, sizeof st);
        flag =  true;
        vector<int>v;
        for(int i = 0; i < n; i ++)
        {
            int c;
            cin >> c;
            color[i] = c;
            v.push_back(c);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        
        for(int i = 0; i < n; i ++)
            if(!st[i])
                dfs(i);

        if(flag)
        {
            cout << v.size() << "-coloring"<< endl;
        }
        else cout << "No\n";
    }

    return 0;
    
}