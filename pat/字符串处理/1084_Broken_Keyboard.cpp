#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<char, bool>st;

int main()
{
    string s, p;

    cin >> s >> p;

    
    for(int i = 0, j = 0; i < s.size(); i ++)
    {
        char a = toupper(s[i]), b = toupper(p[j]);
        if(a == b)
        {
            j ++;
        }
        else 
        {
            if(!st[a])
            {
                cout << a ;
                st[a] = true;
            }
        }
    }
}