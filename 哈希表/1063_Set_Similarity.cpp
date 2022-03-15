#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

const int N = 55;

int n, k;
// set<int>s[N];

int main()
{   
    cin >> n;
    vector<set<int>> s(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        int m;
        cin >> m;
        set<int> tmp;
        for(int i = 0;i < m; i ++)
        {
            int a;
            cin >> a;
            tmp.insert(a);
        }
        s[i] = tmp;
    }

    cin >> k;
    while(k --)
    {
        int a, b;
        cin >> a >> b;
        set<int> total;
        for(auto x: s[a])
        {
            total.insert(x);
        }
        for(auto x: s[b])
        {
            total.insert(x);
        }

        double sum = 1.0 * (s[a].size() + s[b].size() - total.size()) / total.size() * 100;

        printf("%0.1f%%\n", sum);
    }

    return 0;

}

