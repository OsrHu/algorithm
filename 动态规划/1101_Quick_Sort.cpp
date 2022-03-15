#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
int a[N], l[N], r[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) l[i] = max(l[i-1],a[i]);
    r[n + 1] = INF;
    for(int i = n; i >= 1; i --) r[i] = min(r[i+1], a[i]);

    vector<int>res;
    for(int i = 1; i <= n;i ++)
        if(l[i - 1] < a[i] && a[i] < r[i + 1])
        {
            res.push_back(a[i]);
        }

    cout << res.size() << endl;
    sort(res.begin(), res.end());

    if (res.size())
    {
        cout << res[0];
        for (int i = 1; i < res.size(); i ++ ) cout << ' ' << res[i];
    }
    cout << endl;
}

