#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
struct Student
{
    string name,gender,id;
    int grade;

    Student():grade(-1){}

    Student(string name, string gender, string id, int grade) :name(name),gender(gender),id(id),grade(grade){}
};

int main()
{
    cin >> n;
    Student female, male;
    male.grade = 101;
    for(int i = 0; i < n;i ++)
    {
        string name, gender,id;
        int grade;
        cin >> name >> gender >> id >> grade;
        Student tmp = {name, gender, id, grade};
        if(gender=="F" && tmp.grade > female.grade)
        {
            female = tmp;
        }
        else if(gender=="M" && tmp.grade < male.grade)
        {
            male = tmp;
        }
    }
    if(female.grade == -1) cout << "Absent" << endl;
    else cout << female.name << " " << female.id << endl;

    if(male.grade == 101) cout << "Absent" << endl;
    else cout << male.name << " " << male.id << endl;

    if(female.grade == -1 || male.grade == 101) cout <<"NA" << endl;
    else cout << female.grade - male.grade << endl;
}