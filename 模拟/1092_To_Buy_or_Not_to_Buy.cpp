#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

unordered_map<char, int>um;

int main()
{
    string s, p;

    cin >> s >> p;

    for(int i = 0; i < s.size(); i ++)
    {
        um[s[i]] ++;
    }
    
    int miss = 0;
    for(int i = 0; i < p.size(); i ++)
    {
        if(um[p[i]] != 0)
        {
            um[p[i]] --;
        }
        else miss ++;
    }

    if(miss != 0)
    {
        cout << "No " << miss << endl;
    }
    else cout << "Yes " << s.size() - p.size() << endl;
}