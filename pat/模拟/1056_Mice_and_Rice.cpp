#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1010;

int w[N],Rank[N];

int main()
{
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++) cin >> w[i];

    vector<int>cur(n);
    for(int i = 0; i < n; i ++) cin >> cur[i];

    while(cur.size() > 1)
    {   
        vector<int> next;
        int cur_rank = (cur.size() + m - 1) / m;
        for(int i = 0; i < cur.size(); )
        {
            int j = min((int)cur.size(), i + m);
            
            int t = i;
            for(int k = i; k < j; k ++)
            {
                if(w[cur[k]] > w[cur[t]]) t = k;
            }
            next.push_back(cur[t]);
            for(int k = i; k < j; k ++)
            {
                if(k != t)
                    Rank[cur[k]] = cur_rank + 1;
            }

            i = j;
        }

        cur = next;
    }

    Rank[cur[0]] = 1;

    cout << Rank[0];
    for(int i = 1 ; i < n; i ++)
    {
        cout << " " << Rank[i];
    }

    return 0;
}