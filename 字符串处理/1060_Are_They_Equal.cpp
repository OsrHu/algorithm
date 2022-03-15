#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int n;

string change(string s, int n)
{
    int k = s.find('.');

    if(k == -1) s += '.';
    k = s.find('.');
    
    string res = s.substr(0, k) + s.substr(k + 1);

    while(res.length() > 1 && res[0] == '0') res = res.substr(1), k--;
    
    if(res == "0") k = 0;

    if(res.size() > n) res = res.substr(0, n);
    else res += string(n - res.size(), '0');
    
    return "0." + res + "*10^" + to_string(k);
}

int main()
{
    string a,b;
    cin >> n >> a >> b;
    
    a = change(a, n);
    b = change(b, n);

    if(a == b) cout << "YES " << a << endl;
    else cout << "NO " << a << " " << b << endl;


}

