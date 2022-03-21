#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
    string s, p;

    getline(cin, s);

    getline(cin, p);

    for(int i = 0; i < p.size(); i ++)
    {
        while(s.find(p[i]) != -1)
        {
            s.erase(s.find(p[i]), 1);
        }
    }

    cout << s << endl;

    return 0;
}