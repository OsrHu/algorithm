#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N];
bool st[N];
vector<int> v[N];

PII bfs(int S)
{
    queue<int>q;
    memset(st, 0, sizeof st);
    
    q.push(S);
    st[S] = true;
    while(q.size())
    {
        int t = q.front();
        v[S].push_back(t);
        q.pop();
        for(int i = 1; i <= n; i ++)
        {
            if(!st[i] && g[t][i])
            {
                q.push(i);
                st[i] = true;
                break;
            }
        }
    }    

    return make_pair(S, v[S].size());
    
}

int main()
{
    cin >> n >> m;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    int ans_idx = -1, ans_number = 0;
    for(int i = 1; i <= n; i ++)
    {
        auto t = bfs(i);

        if(i == 1 || ans_number < t.y)
        {
            ans_number = t.y;
            ans_idx = i;
        }
        else if(ans_number == t.y && ans_idx > t.x)
        {
            ans_idx = t.x;
        }
    }

    cout << ans_idx << " " << ans_number << endl;

    return 0;


}
