#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
#include<cctype>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int a[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> a[i];

    sort(a, a + n);

    int cnt = (n + m - 1) / m;
    int k = 0 ;
    int t = 0;
    while(cnt --)
    {
        vector<int>ans;
        int i;
        for(i = k; i < k + m && i < n; i ++)
        {
            ans.push_back(a[i]);
        }
        k += ans.size();
        t ++;
        if(t % 2 == 0) reverse(ans.begin(), ans.end());
        // cout << k << endl;
        for(int i = 0; i < ans.size(); i ++)
        {
            if(i != 0) cout << " ";
            cout << ans[i];
        }

        cout << endl;

    }
}