#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e4 + 10;

int n;
string s[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> s[i];
    }

    sort(s, s + n, [](string a, string b){return a + b < b + a;});


    string res;
    for(int i = 0; i < n;i ++)
    {
        res += s[i];
    }

    int k = 0;

    while(res.substr(k).size() > 1 && res[k] == '0') k ++;
    cout << res.substr(k) << endl;

    return 0;

}