#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;

int n;
struct Person
{
    string id;
    int ihh, imm, iss;
    int ohh, omm, oss;
};
unordered_map<string, Person>persons;

bool cmp1(Person a, Person b)
{
    if(a.ihh != b.ihh) return a.ihh < b.ihh;
    if(a.imm != b.imm) return a.imm < b.imm;
    if(a.iss != b.iss) return a.iss < b.iss;
}


bool cmp2(Person a, Person b)
{
    if(a.ohh != b.ohh) return a.ohh > b.ohh;
    if(a.omm != b.omm) return a.omm > b.omm;
    if(a.oss != b.oss) return a.oss > b.oss;
}

int main()
{
    cin >> n;
    Person ans1, ans2;
    for(int i = 0; i < n; i ++)
    {   
        char id[20];
        int ihh, imm, iss;
        int ohh, omm, oss;
        scanf("%s %d:%d:%d", id, &ihh, &imm, &iss);
        scanf("%d:%d:%d",&ohh, &omm, &oss);
        persons[id] = {id, ihh, imm, iss, ohh, omm, oss};
        if(!i || cmp1(persons[id], ans1))
        {
            ans1 = persons[id];
        }

        if(!i || cmp2(persons[id], ans2))
        {
            ans2 = persons[id];
        }
    }

    cout << ans1.id << " " << ans2.id << endl;

    return 0;

}