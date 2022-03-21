#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;


int n;
struct School
{
    string name;
    int num;
    double total;

    School(): num(0), total(0){}

    bool operator<(const School& t) const
    {
        if(total != t.total) return total > t.total;
        if(num != t.num) return num < t.num;
        return name < t.name;
    }
};

int main()
{
    cin >> n;
    unordered_map<string, School> um;
    while(n --)
    {
        string id, school;
        double score;
        cin >> id >> score >> school;
        for (char& c : school)  //学校id转换成小写字母
            c = tolower(c);

        double total = 0;
        if(id[0] == 'B') total += score / 1.5;
        if(id[0] == 'A') total += score;
        if(id[0] == 'T') total += score * 1.5;

        um[school].name = school;
        um[school].total += total;
        um[school].num ++;
    }

    vector<School> schools;
    for(auto& item: um)
    {   
        item.second.total = (int)item.second.total;
        schools.push_back(item.second);
    }

    sort(schools.begin(), schools.end());

    cout << schools.size() << endl;
    for(int i = 0, rank =1; i < schools.size(); i ++)
    {
        if(i && schools[i].total != schools[i - 1].total) rank = i + 1;
        cout << rank << " " << schools[i].name << " " << schools[i].total << " " << schools[i].num << endl;
    }

    return 0;
}