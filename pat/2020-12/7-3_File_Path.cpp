#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 10010;

int n, q;

unordered_map<string, string> p;
vector<string> ans;


int main()
{
    cin >> n;
    getchar();
    int lastidx = 0;
    string pre = "0000";
    for(int i = 0; i < n; i ++)
    {   
        string id;
        getline(cin, id);
        int idx = 0;
        while(id[idx] == ' ') idx ++;
        id = id.substr(idx);
        
        if(idx == 0) continue;
        while(lastidx >= idx && lastidx >= 0)
        {
            lastidx --;
            pre = p[pre];
        }

        // cout << lastidx << " " << idx << " " << id <<  " " <<  pre  << endl;

        if(lastidx == idx - 1)
        {
            p[id] = pre;
            lastidx = idx;
            pre = id;
        }

    }

    cin >> q;
    while(q --)
    {
        string T;
        ans.clear();
        cin >> T;
        if(T == "0000")
        {
            cout << "0000\n";
            continue;
        }
        
        if(p.count(T))
            for(string i = T; i != "0000"; i = p[i]) ans.push_back(i);

        if(ans.size() == 0)
        {
            cout << "Error: " + T + " is not found.\n";
        }
        else
        {
            cout << "0000";
            for(int i = ans.size() - 1; i >= 0; i --)
                cout << "->" << ans[i];
            cout << endl;
        }

    }


}