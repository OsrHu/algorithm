#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int n;
string ge[14]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string shi[14]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
unordered_map<string, int> um;

void numtostring(int x)
{       
    bool flag = false;
    vector<int> v;
    if(x >= 13)
    {   flag = true;
        while(x >=13)
        {   
            v.push_back(x % 13);
            x = x / 13;   
            
        }
    }

    v.push_back(x);
    if(flag)
    {
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i ++)
        {   
            if(i == 0) cout << shi[v[i]];
            if(i == 1 && v[i] != 0) cout << " " <<ge[v[i]];
        }
    }
    else
    {
        cout << ge[v[0]];
    }
    cout << endl;
}

void stringtonum(string x)
{   
    bool flag = false;
    int pos = x.find(" ");
    if(pos != -1) flag = true;

    if(flag)
    {
        string s = x.substr(0, pos);
        string ss = x.substr(pos+1);
        cout << um[s] + um[ss]<< endl;
    }
    else
    {   
        string s = x.substr(0);
        cout << um[s] << endl;
    }
}

int main()
{   
    for(int i = 0; i < 13; i ++)
    {
        um[ge[i]] = i;
    }
    for(int i = 1 ; i < 13; i ++)
    {
        um[shi[i]] = i * 13;
    }
    cin >> n;
    getchar();
    while(n --)
    {
        string s;
        getline(cin, s);
        if(isdigit(s[0]))
        {
            numtostring(stoi(s));
        }
        else
        {
            stringtonum(s);
        }
    }

    return 0;
}