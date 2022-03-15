#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 1e5 + 10;

struct Person
{
    string id;
    int virtue, talent, sum, level;

    bool operator<(const Person& t)const
    {
        if(level != t.level) return level < t.level;
        if(sum != t.sum) return sum > t.sum;
        if(virtue != t.virtue) return virtue > t.virtue;
        if(id != t.id) return id < t.id;
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    vector<Person> persons;

    int n,l,h;
    cin >> n >> l >> h;
    while(n --)
    {
        string id;
        int virtue, talent, sum, level;
        cin >> id >> virtue >> talent;
        if(virtue < l || talent < l) continue;

        if(virtue >= h && talent >=h) level = 1;
        else if(virtue >=h && talent < h ) level = 2;
        else if(virtue < h && talent < h && virtue >= talent) level = 3;
        else level = 4;
        persons.push_back({id, virtue, talent, virtue + talent, level});
    }

    sort(persons.begin(), persons.end());

    cout << persons.size() << endl;

    for(auto p: persons)
    {
        cout << p.id << " " << p.virtue << " " << p.talent << endl;
    }


    
}