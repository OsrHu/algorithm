#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> a[i];

    sort(a, a + n);
    int ans = 0;
    if(n % 2 == 0) ans = 0;
    else ans = 1;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n/2; i ++)   s1 += a[i];
    for(int i = n/2; i < n; i ++)   s2 += a[i];

    cout << ans << " " << s2 - s1;
}