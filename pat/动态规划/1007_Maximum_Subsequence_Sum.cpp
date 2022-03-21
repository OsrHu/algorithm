/**
 区间长度为1，和区间长度大于1是集合两边
 */

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010, INF = 0x3f3f3f3f;
int a[N],n;
int s[N];


int main()
{
    cin >> n;

    for(int i = 1; i <= n; i ++) cin >> a[i];
    
    int ans = -INF;
    int l = 1, r = 1;
    int ltmp = 1;
    for(int i = 1; i <= n; i ++)
    {
        s[i] = max(s[i - 1] + a[i], a[i]);
        if(s[i] == a[i])
        {
            ltmp = i;
        }
        if(s[i] > ans)
        {
            ans = s[i];
            r = i;
            l = ltmp;
        }
    }

    if(ans < 0) ans = 0, l = 1, r = n;

    cout << ans << " " << a[l] << " " << a[r] <<  endl;
    
}