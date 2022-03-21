#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>

using namespace std;

const int N = 1010;

int n;
int main()
{
    cin >> n;
    string s;
    int sum = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> s;
        unordered_set<string> ans;
        for(auto c: s)
        {
            if(isalpha(c)) ans.insert(to_string(c));
        }
        sum += ans.size();
    }

    cout << sum << endl;
}