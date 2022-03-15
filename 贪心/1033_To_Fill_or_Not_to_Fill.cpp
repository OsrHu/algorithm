#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int c, d, davg, n;
struct Station
{
    double price, distance;

    bool operator<(const Station& t)const
    {
        return distance < t.distance;
    }

}stations[N];

int main()
{
    cin >> c >> d >> davg >> n;

    for(int i = 1; i <= n; i ++)
    {
        double price, distance;
        cin >> price >> distance;
        stations[i] = {price, distance};
    }

    sort(stations + 1, stations + n + 1);

    double drange = c * davg;
    double totaldis = 0;


    if(stations[1].distance !=0)
    {
        printf("The maximum travel distance = %.2lf\n", totaldis);
        return 0;
    }
    
    int k = 1;
    double curdrange = 0;
    double oil = 0,price = 0;
    int id = k;
    while(totaldis < d)
    {   
       


        // vector<int> station;
        // curdrange = oil * davg;
        double min_price = INF;
        bool flag = false;
        for(int i = k + 1; i <= n;i ++)
        {      
            
            if(stations[i].distance <= totaldis + drange)
            {
                if(stations[i].price < stations[k].price)
                {
                    id = i;
                    flag = true;
                    break;
                }

                if(stations[i].price < min_price)
                {  
                    min_price = stations[i].price;
                    id = i;
                }
            }
            // else
            // {   
            //     break;
            //     cout << "second_min " << id << endl;
            //     printf("The maximum1 travel distance = %.2lf\n", stations[k].distance);
            //     return 0;
            // }
        }
        if(stations[k].price < stations[id].price && stations[k].distance + drange > d)
        {   
            price += (d - totaldis) / davg * stations[k].price;
            printf("%.2lf\n",price);
            return 0;
        }
        if(k == id) 
        {   
            if(totaldis + drange > d)
            {   
                // cout << d << endl;
                // cout << stations[k].distance << endl;
                price += (d - totaldis) / davg * stations[k].price;
                printf("%.2lf\n",price);
                return 0;
            }
            else
            {
                printf("The maximum travel distance = %.2lf\n", stations[k].distance + drange);
                return 0;
            }
            
        }

        // cout << "station " << k << endl;
        if(flag)
        {   
            double addoil = (stations[id].distance - stations[k].distance) / davg;
            if(addoil > oil) addoil = addoil - oil;
            oil += addoil;
            price += addoil * stations[k].price;
            // cout << "addoil1 " << addoil << endl;

        }
        else
        {
            double addoil = c - oil;
            oil += addoil;
            price += addoil * stations[k].price;
            // cout << "addoil2 " << addoil << endl;

        }

        totaldis += stations[id].distance - stations[k].distance;
        // cout << k << " " << id << endl;
        // cout << price << endl;
        oil -= (stations[id].distance - stations[k].distance) / davg;
        // cout << "oid left " << oil << endl; 
        // cout << "totaldis " << totaldis << endl;
        k = id;
    }
    

}