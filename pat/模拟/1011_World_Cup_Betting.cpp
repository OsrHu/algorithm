#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string title[3] = {"W", "T", "L"};

int main()
{
    double ans = 1;
    for(int i = 0; i < 3;i ++)
    {   
        double number = 0, max_number = -1;
        int idx = 0;
        for(int j = 0; j < 3; j ++)
        {
            cin >> number;
            if(number > max_number)
            {
                max_number = number;
                idx = j;
            }
        }
        ans *= max_number;
        cout << title[idx] << " ";
    }

    printf("%.2lf",(ans * 0.65 - 1) * 2);
}