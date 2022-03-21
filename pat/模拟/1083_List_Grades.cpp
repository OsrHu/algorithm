#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n;

struct Student
{
    string name, id;
    int grade;

    bool operator<(const Student& t)const
    {
        return grade > t.grade;
    }
};

int main()
{
    cin >> n;
    vector<Student> stu(n);
    for(int i = 0; i < n; i ++)
    {   
        string name, id;
        int grade;
        cin >> name >> id >> grade;
        stu[i] = {name, id, grade};
    }
    int l, h;
    cin >> l >> h;

    sort(stu.begin(), stu.end());

    bool f = false;
    for(auto& s: stu)
    {
        if(s.grade >= l && s.grade <= h)
        {
            f = true;
            cout << s.name << " " << s.id  << endl;
        }
    }

    if(!f) cout << "NONE";

}