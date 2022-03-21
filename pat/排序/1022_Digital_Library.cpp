#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<sstream>
#include<vector>

using namespace std;

struct Book
{
    string id, name, author;
    set<string> keywords;
    string publisher, year;
};

int main()
{
    int n, m;
    cin >> n;
    vector<Book> books;
    while(n --)
    {
        string id, name, author;
        cin >> id;
        getchar();
        getline(cin, name), getline(cin, author);
        string line;
        getline(cin, line);
        stringstream ssin(line);
        string keyword;
        set<string> keywords;
        while (ssin >> keyword) keywords.insert(keyword);
        string publisher, year;
        getline(cin, publisher);
        cin >> year;
        books.push_back({id, name, author, keywords, publisher, year});
    }

    cin >> m;
    getchar();
    string line;
    while(m --)
    {
        getline(cin, line);
        cout << line << endl;

        string info = line.substr(3);
        char t = line[0];
        vector<string> res;
        if (t == '1')
        {
            for (auto& book : books)
                if (book.name == info)
                    res.push_back(book.id);
        }
        else if (t == '2')
        {
            for (auto& book : books)
                if (book.author == info)
                    res.push_back(book.id);
        }
        else if (t == '3')
        {
            for (auto& book : books)
                if (book.keywords.count(info))
                    res.push_back(book.id);
        }
        else if (t == '4')
        {
            for (auto& book : books)
                if (book.publisher == info)
                    res.push_back(book.id);
        }
        else
        {
            for (auto& book : books)
                if (book.year == info)
                    res.push_back(book.id);
        }

        if (res.empty()) puts("Not Found");
        else
        {
            sort(res.begin(), res.end());
            for (auto id : res) cout << id << endl;
        }
    }

        
}
