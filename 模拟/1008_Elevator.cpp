#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int pre = 0;
    int cur = 1;

    int n;
    cin >> n;
    int ans = 0;
    while(n --)
    {
        cin >> cur;
        if(cur - pre > 0)
        {
            ans += (cur - pre) * 6 + 5;
        }
        else if(cur - pre < 0)
        {
            ans += abs(cur - pre) * 4 + 5;
        }
        else ans += 5;

        pre = cur;
    }

    cout << ans;
}