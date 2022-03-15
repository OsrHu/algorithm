#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

int n;
string s;
unordered_map<char, bool> isbad;
vector<char> ans;


int main()
{
    cin >> n;
    getchar();
    getline(cin, s);
    for(int i = 0; i < s.length();)
    {   
        int j = i;
        while(s[j] == s[i] && j < s.length()) j ++;

        if((j - i) % n == 0 && isbad[s[i]] == false)
        {   
            isbad[s[i]] = true;
            ans.push_back(s[i]);

        }
        i = j;
    }

    for(int i = 0; i < s.length();)
    {   
        int j = i;
        while(s[j] == s[i] && j < s.length()) j ++;

        if((j - i) % n != 0 && isbad[s[i]] == true)
        {
            isbad[s[i]] = false;
        }
        i = j;
    }



    for(auto x: ans)
    {   
        if(isbad[x])
            cout << x;
    }
    cout << endl;
    string ss;
    for(int i = 0; i < s.length(); )
    {   
        int j = i + 1;
        if(isbad[s[i]])
        {   
            while(s[i] == s[j] && j < s.length())
            {
                j ++;
            }
        }

        if((j - i) % n == 0)    ss += s.substr(i, (j - i) / n );
        else    ss += s.substr(i, j - i);
        i = j;
    }

    cout << ss << endl;
}