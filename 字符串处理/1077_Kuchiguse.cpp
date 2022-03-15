#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 110;

int n;
string s[N];


int main()
{
    cin >> n;
    getchar();
    for(int i = 0; i < n; i ++)
    {
        getline(cin, s[i]);
    }

    for(int i = s[0].size(); i > 0; i --)
    {
        string sf = s[0].substr(s[0].size() - i);
        bool is_match = true;
        for(int j = 1; j < n; j ++)
        {
            if(i > s[j].size() || s[j].substr(s[j].size() - i) != sf)
            {
                is_match = false;
                break ;
            }
        }


        if(is_match)
        {
            cout << sf << endl;
            return 0;
        }
    }

    cout << "nai" << endl;

    return 0;
}