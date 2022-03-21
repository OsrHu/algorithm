#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;

int n, k;
unordered_map<int, int> um;
set<int> ans;

int main()
{
    cin >> n;
    while(n --)
    {
        int a, b;
        cin >> a >> b;
        um[a] = b;
        um[b] = a;
    }

    cin >> k;
    while(k --)
    {
        int t;
        cin >> t;
        ans.insert(t);
    } 
    set<int> back = ans;
    for(auto x: back)
    {
        if(ans.count(um[x]))
        {
            ans.erase(x);
            ans.erase(um[x]);
        }
    }

    bool is_first = true;

    cout << ans.size() << endl;
    for(auto x: ans)
    {   
        if(!is_first) cout << " ";
        string s = to_string(x);
        s = string(5 - s.size(), '0') + s;
        cout << s ;
        if(is_first == true) is_first = false;
    }
}

