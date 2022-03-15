#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

typedef long long LL;

int n;

bool is_prime(LL x)
{
    if(x < 2) return false;
    for(LL i = 2; i <= x / i; i ++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n;

    map<int,int> mp;

    for(int i = 2; i * i <= n; i ++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n = n / i;
                mp[i] ++;
            }
        }
    }

    if(n > 1) mp[n] ++;
    string num = "1";
    for(auto it = mp.begin(); it != mp.end(); it ++)
    {   
        if(num == "1") num.clear();
        if(it->second != 1) num += to_string(it->first) + to_string(it->second);
        else num += to_string(it->first);
    }

    LL ans = stoll(num);

    cout << ans << endl;
    if(is_prime(ans))
    {
        cout << "Yes\n";
    }
    else cout << "No\n";

    return 0;
}