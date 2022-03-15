#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 2510;

int n, k, m;
struct Course
{
    vector<string> stu;
}courses[N];

int main()
{   
    // ios::sync_with_stdio(false),  cin.tie(0), cout.tie(0);
    cin >> n >> k;

    for(int i = 0; i < n; i ++)
    {
        string name;
        cin >> name;
        cin >> m;

        for(int j = 0; j < m; j ++)
        {
            int id;
            cin >> id;
            courses[id].stu.push_back(name);
        }
    }

    for(int i = 1; i <= k; i ++)
    {
        cout << i << " " << courses[i].stu.size() << endl;
        auto t = courses[i].stu;
        sort(t.begin(), t.end());
        for(int j = 0; j < t.size(); j ++)
        {
            printf("%s\n", t[j].c_str());
        }
    }

}