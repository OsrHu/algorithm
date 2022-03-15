#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 210;

int n,m;
struct Person
{
    string name;
    int age,w;

    bool operator<(const Person& t) const
    {
        if(w != t.w) return w > t.w;
        if(age != t.age) return age < t.age;
        return  name < t.name;
    }
};

vector<Person> ages[N];
int idx[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        string name;
        int age, w;
        cin >> name >> age >> w;
        ages[age].push_back({name, age, w});
    }

    for (auto& age : ages) sort(age.begin(), age.end());

    for(int C = 1; C <= m; C ++)
    {   
        cout << "Case #" << C << ":" << endl;
        // printf("Case111 #%d:\n", C);
        int cnt, a, b;
        cin >> cnt >> a >> b;

        memset(idx, 0, sizeof idx);
        bool exists = false;
        while(cnt --)
        {
            int t = -1;
            for(int i = a; i <= b; i ++)
            {   
                if(idx[i] < ages[i].size())
                    if(t == -1 || ages[i][idx[i]] < ages[t][idx[t]])
                        t = i;
            }
            if(t == -1) break;
            
            auto& p = ages[t][idx[t]];
            idx[t] ++;

            cout << p.name << " " << p.age << " " << p.w << endl;
            exists = true;
        }
        if (!exists) cout << "None\n"; 
    }
    return 0;
}