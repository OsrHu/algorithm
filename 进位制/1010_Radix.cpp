#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

int get(char c)
{
    if(c <= '9') return c - '0';
    else return c - 'a' + 10;
}

LL cal(string n, int r)
{
    LL res = 0;
    for(auto c: n)
    {
        if((double) res * r + get(c) > 1e16) return 1e18;
        res = res * r + get(c);
    }
    return res;
}

int main()
{
    string s1, s2;
    int tag, radix;
    cin >> s1 >> s2 >> tag >> radix;
    if(tag == 2) swap(s1, s2);

    LL target = cal(s1, radix);


    LL l = 0, r = target + 1;
    for(auto c: s2) l = max(l, (LL)get(c) + 1); 

    while(l < r)
    {
        LL mid = l + r + 1 >> 1;
        cout << mid << endl;
        if(cal(s2, mid) >= target) l = mid;
        else r = mid - 1;
    }

    cout << l << " " << r << endl;
    if(cal(s2, r) != target) cout << "Impossible\n";
    else cout << r << endl;
    return 0;
}