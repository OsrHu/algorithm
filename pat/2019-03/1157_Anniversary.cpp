#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int N = 1e5 + 10, M = N;

int n, m;
unordered_map<string, int> um;
string people[M];
vector<string> peoples;
int cnt;

bool cmp(string a, string b)
{
    return a.substr(7, 8) < b.substr(7, 8);
}

int main()
{
    cin >> n;
    while(n --)
    {
        string s;
        cin >> s;
        um[s] = 1;
    }

    cin >> m;

    for(int i = 0; i < m; i ++)
    {
        cin >> people[i];
        if(um.count(people[i]))
        {   
            peoples.push_back(people[i]);
        }
    }

    cout << peoples.size() << endl;
    if(peoples.size())
    {
        sort(peoples.begin(), peoples.end(), cmp);
        cout << peoples[0] << endl;
    }
    else
    {
        sort(people, people + m , cmp);
        cout << people[0] << endl;
    }

}