#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

const int K = 6;

int n, k, m;
int p_score[K];

struct Student
{
    string id;
    int grade[K];
    int total, cnt;

    Student(){}
    Student(string _id): id(_id)
    {
        for(int i = 1; i <=k; i ++) grade[i] = -2;
        total = cnt = 0;
    }

    void calc()
    {
        for(int i = 1; i <= k; i ++)
        {
            total += max(0, grade[i]);
            if(grade[i] == p_score[i]) cnt ++;
        }
    }
    
    bool has_submit()
    {
        for(int i = 1; i <= k; i ++)
            if(grade[i] >= 0)
                return true;
        return false;
    }

    bool operator< (const Student& t)const
    {
        if(total != t.total) return total > t.total;
        if(cnt != t.cnt) return cnt > t.cnt;
        return id < t.id;
    }
};

int main()
{   
    unordered_map<string, Student> students;
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= k; i ++) cin >> p_score[i];

    while(m --)
    {
        string id;
        int pid, grade;
        cin >> id >> pid >> grade;

        if(students.count(id) == 0) students[id] = Student(id);
        students[id].grade[pid] = max(students[id].grade[pid], grade);
    }

    vector<Student> res;
    for(auto& item: students)
    {
        auto& s = item.second;
        if(s.has_submit())
        {
            s.calc();
            res.push_back(s);
        }
    }

    sort(res.begin(), res.end());

    for(int i = 0, rank = 1; i < res.size(); i ++)
    {
        if(i && res[i].total != res[i - 1].total) rank = i + 1;
        cout << rank << " " << res[i].id << " " << res[i].total ;
        for(int j = 1; j <=k; j ++)
        {
            if(res[i].grade[j] == -2) cout << " -";
            else cout << " " << max(0, res[i].grade[j]);
        }
        cout << endl;
    }

    return 0;


}