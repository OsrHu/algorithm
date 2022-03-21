#include<vector>

using namespace std;

const int N = 40010, M = 110, K  = 10;

int n,m,k;
int cnt[N];
// int wish[N];
// int rank[N]; 因为学生序号是0--N-1

struct Student
{
    int id, ge, gi;
    int total;
    int rank;
    int wish[K];

    bool operator<(const Student& t)const
    {
        if(total != t.total) return total > t.total;
        return ge > t.ge; 
    }
};

bool cmp(Student& a, Student& b)
{
    return a.id < b.id;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++) cin >> cnt[i];
    vector<Student> stu(n);
    for(int i = 0; i < n; i ++)
    {
        int ge, gi;
        cin >> ge >> gi;
        int total = ge + gi;
        stu[i] = {i, ge, gi, total};
        for(int  j = 0; j < k; j ++) cin >> stu[i].wish[j];

    }

    sort(stu.begin(), stu.end());
    for(int i = 0, rank = 1; i < n; i ++)
    {   
        if(i && (stu[i].total != stu[i - 1].total
            || stu[i].ge != stu[i - 1].ge)) rank = i + 1;
        stu[i].rank = rank;
        // cout << stu[i].id << ' ' <<  rank << endl;
    }

    vector<vector<Student>> ans(m);
    for(auto& s: stu) // 此时序号已经不重要
    {
        for(int i = 0; i < k; i ++)
        {
            int schid = s.wish[i];
            if(ans[schid].size() < cnt[schid] || 
                (!ans[schid].empty() && s.rank == ans[schid].back().rank) )
            {
                ans[schid].push_back(s);
                break;
            }
        }
    }

    for(auto& v: ans)
    {
        sort(v.begin(), v.end(), cmp);
        for(int i = 0; i < v.size(); i ++)
        {
            cout << (i == 0 ? "" : " ") << v[i].id;
        }
        cout << endl;
    }
    return 0;




}