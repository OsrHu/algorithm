#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cmath>

using namespace std;

int p, m, n;
struct Student
{
    string id;
    int gp, gm, gf;
    double g;

    Student():gp(-1), gm(-1), gf(-1), g(-1) {}

    bool operator<(const Student& t) const
    {
        if(g != t.g) return g > t.g;
        return id < t.id;
    }
    
};

unordered_map<string, Student> students;

int main()
{
    cin >> p >> m >> n;
    while(p --)
    {
        string id;
        int gp;
        cin >> id >> gp;
        if(gp >= 200) 
        {   
            Student s;
            s.id = id;
            s.gp = gp;
            students[id] = s;
        }
    }

    while(m --)
    {
        string id;
        int gm;
        cin >> id >> gm;
        if(students.count(id) == 0) continue;

        students[id].gm = gm;
    }
    vector<Student> stu;
    while(n --)
    {
        string id;
        int gf;
        cin >> id >> gf;
        if(students.count(id) == 0) continue;

        students[id].gf = gf;
        stu.push_back(students[id]);
    }

    for(int i = 0; i < stu.size(); i ++)
    {
        auto& t = stu[i];
        if(t.gm > t .gf)
        {
            t.g = round(t.gm * 0.4 + t.gf * 0.6);
        }
        else
        {
            t.g = t.gf;
        }
    }

    sort(stu.begin(), stu.end());

    for(int i = 0; i < stu.size(); i ++)
    {       
        auto t = stu[i];
        if(t.g < 60) continue;
        cout << t.id << " " << t.gp << " " << t.gm << " " << t.gf << " " << t.g << endl;
        
    }


}