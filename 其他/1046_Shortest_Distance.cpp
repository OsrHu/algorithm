#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int s[N];


int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n; i ++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    int sum = s[n];
    
    int m;
    cin >> m;
    while(m --)
    {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        
        int tmp = s[r - 1] - s[l - 1];
        int ans = min(tmp, sum - tmp);
        cout << ans << endl;
    }

    return 0;


}