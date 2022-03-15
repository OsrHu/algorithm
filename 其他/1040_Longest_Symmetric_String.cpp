#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int ans = 0;
    for(int i = 0; i < s.size(); i ++)
    {
        int l = i - 1, r = i + 1;
        while(l>=0 && r < s.size() && s[l] == s[r]) l--, r ++;
        ans = max(ans, r -l - 1);

        l = i,r = i + 1;
        while(l>=0 && r < s.size() && s[l] == s[r]) l--, r ++;
        ans = max(ans, r -l - 1);
    }

    cout << ans << endl;


}