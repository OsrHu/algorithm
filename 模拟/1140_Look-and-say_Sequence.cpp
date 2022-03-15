#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    int K;
    cin >> s >> K;
    for(int i = 0; i < K - 1; i ++)
    {   
        string res;
        for(int j = 0; j < s.size();)
        {
            char ch = s[j];
            int k = j + 1;
            string ss;
            for(; k < s.size(); k ++)
            {   
                if(ch != s[k]) 
                {
                    break;
                }
                
            }
            int len = k - j;
            ss = to_string(len);
            j = k;
            res += ch;
            res += ss;
        }
        // cout << res << endl;

        s = res;
    }
    cout << s << endl;

    return 0;
}