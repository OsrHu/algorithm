#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
#include<cctype>
#include<cmath>
#include<sstream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 1e5 + 10;

int n,m;
struct edge
{
    int a, b;
}e[M];
bool st[N];
unordered_map<int, int>number;

// void add(int a, int b)
// {
//     e[i] = b, ne[i] = h[a], h[a] = idx ++;
// }

bool cmp(PII a,PII b)
{
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    cin >> n >> m;
    int cnt = 0;
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        e[cnt ++] = {a, b};
    }

    int k;
    while(cin >> k,k)
    {       
        vector<PII>ans;
        memset(st,0, sizeof st);
        vector<int>a(k);
        for(int i = 0; i < k; i ++)
        {
            int t;
            cin >> t;
            a[i] = t;
            st[t] = true;
        }
        
        number.clear();

        for(int i = 0; i < cnt; i ++)
        {
            if(st[e[i].a] && st[e[i].b])
            {
                number[e[i].a] ++;
                number[e[i].b] ++;
            }
        }

        for(int i = 0; i < k; i ++)
        {
            PII t(number[a[i]], a[i]);
            ans.push_back(t);
        }

        sort(ans.begin(), ans.end(), cmp);

        // for(auto x: ans)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }

        for(int i = 0; i < 3; i ++)
        {
            if(i != 0) cout << " ";
            cout << ans[i].second;
        }
        cout << endl;
    }
}