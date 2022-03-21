#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

string change(string number)
{   
    char sign = number[0];
    number = number.substr(1);
    int k = number.find('.');
    int e = number.find('E');
    int len = e - k - 1;
    string res = number.substr(0, k) + number.substr(k + 1, len);
    string ex = number.substr(e + 2);
    int num = stoi(ex);
    if(!num)  //+3.9E-0000000000 输出 3.9
    {
        res = number.substr(0, k + 1) + number.substr(k + 1, len);
    }
    else
    {
        if(number[e + 1] == '-')
        {
            int k = 1;
            while(k < num)
            {
                res = '0' + res;
                k++;
            }
            res = "0." + res;
        }
        else
        {   
            if(len < num)
            {
                while(len++ < num)
                {
                    res += '0';
                }
            }
            else
            {   
                string rres;
                for(int i = 0; i < res.size(); i ++)
                {
                    
                    rres += res[i];
                    if(i == num && num < len) rres +='.';
                }
                res = rres;                
            }
        }
    }


    if(sign == '-')  res = sign + res;
    return res;
}


int main()
{
    string number;
    cin >> number;
    number = change(number);

    cout << number;
}



// 写法2
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s[0] == '-') cout << '-';

    int k = s.find("E");
    string a = s[1] + s.substr(3, k - 3);
    int b = stoi(s.substr(k + 1));
    b ++ ;

    if (b <= 0) a = "0." + string(-b, '0') + a;
    else if (b >= a.size()) a += string(b - a.size(), '0');
    else a = a.substr(0, b) + '.' + a.substr(b);

    cout << a << endl;

    return 0;
}


