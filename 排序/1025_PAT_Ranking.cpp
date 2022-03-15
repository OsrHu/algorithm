/*
存两个vector
一个存当前地区的考生，进行排名
另一个存所有地区的考生，然后再次排名
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 110;

struct Student
{
    string id;
    int grade;
    int location_number, local_rank, final_rank;

    bool operator< (const Student& t) const
    {
        if(grade != t.grade) return grade > t.grade;
        return id < t.id;
    }
};

vector<Student> grades[N];
vector<Student> all;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n;i ++)
    {
        int k;
        cin >> k;
        for(int j = 0 ; j < k; j ++)
        {
            string id;
            int grade;
            cin >> id >> grade;
            grades[i].push_back({id, grade, i});
        }

         auto& g = grades[i];
         sort(g.begin(), g.end());
         for(int i = 0; i < g.size(); i ++)
         {
            if(!i || g[i].grade != g[i - 1].grade)
                g[i].local_rank = i + 1;
            else
                g[i].local_rank = g[i - 1].local_rank;
            all.push_back(g[i]);
         }
    }

    sort(all.begin(), all.end());

    for(int i = 0; i < all.size(); i ++)
    {
        if(!i ||  all[i].grade != all[i - 1].grade)
            all[i].final_rank = i + 1;
        else
            all[i].final_rank = all[i - 1].final_rank;
    }

    cout << all.size() << endl;
    for(auto& s: all)
        cout << s.id << " " << s.final_rank << " " << s.location_number << " " << s.local_rank << endl;

    return 0;

   
}

