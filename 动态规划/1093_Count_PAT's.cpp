#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10, MOD = 1000000007;

int left[N], right[N];

int main()
{
    string s;
    cin >> s;
    int p = 0, pa = 0, pat = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] == 'P')
        {
            p ++;
            p %= MOD;
        }
        if(s[i] == 'A')
        {
            pa += p;
            pa %= MOD;
        }
        if(s[i] == 'T')
        {
            pat += pa;
            pat %= MOD;
        }
    }

    cout << pat << endl;

    return 0;
}
