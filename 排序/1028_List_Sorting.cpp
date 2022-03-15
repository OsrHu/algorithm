#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n,c;
struct Row
{
    string id, name;
    int grade;
}rows[N];

bool cmp1(Row a, Row b)
{
    return a.id < b.id;
}

bool cmp2(Row a, Row b)
{
    if(a.name != b.name) return a.name < b.name;
    return a.id < b.id;
}

bool cmp3(Row a, Row b)
{
    if(a.grade != b.grade) return a.grade < b.grade;
    return a.id <  b.id;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i ++)
    {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        rows[i] = {id, name, grade};
    }

    if(c == 1) sort(rows, rows + n, cmp1);
    else if(c == 2) sort(rows, rows + n, cmp2);
    else sort(rows, rows + n, cmp3);

    for(int i = 0; i < n;i ++)
        cout << rows[i].id << " " << rows[i].name << ' ' << rows[i].grade << endl;
    return 0;
}

