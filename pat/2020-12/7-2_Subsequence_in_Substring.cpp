/*
atpaaapbtat
pat
*/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

string S, P;

int main()
{
    cin >> S >> P;

    int minlen = INF;
    string ans;
    for(int i = 0; i < S.size(); i ++)
    {   
        int len = 0;
        if(S[i] == P[len])
        {
            string s = S.substr(i);
            // int pos = s.find(P[P.size() - 1]);
            // if(pos == -1) continue;
            // s = s.substr(0, pos + 1);
            int j;
            for(j = 0; j < s.size(); j ++)
            {   
                if(len == P.size()) break;

                if(s[j] == P[len]) len ++;


            }
            s = s.substr(0, j);
            if(len == P.size())
            {
                if(s.size() < minlen)
                {
                    minlen = s.size();
                    ans = s;
                }
            }
        }

    }

    cout << ans << endl;
}

