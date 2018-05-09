/*
ID: francis40
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

int n = 0;
map <string, int> moneyCount;

pair<int, int> getPair(string line)
{
    int money, nPeople;
    money = stoi(line.substr(0, line.find(' ')));
    line = line.erase(0, line.find(' ') + 1);
    nPeople = stoi(line.substr(0, line.size()));
    return pair<int, int>(money, nPeople);
}

void addMoney(string name, int n)
{
    for (map<string, int> :: iterator it = moneyCount.begin(); it != moneyCount.end(); it++)
    {
        if (it->first == name)
        {
            int previous = it->second;
            it->second = n + previous;
        }
    }
}

void storeData()
{
    ifstream ifs;
    ifs.open("gift1.in");
    string line;
    
    if(ifs.is_open())
    {
        getline(ifs, line);
        n = stoi(line);

        for (int i = 0; i < n ; i++)
        {
            getline(ifs, line);
            moneyCount.insert(pair<string, int> (line, 0));
        }

        while(getline(ifs, line)){
            string name;
            int money = 0, nPeople = 0;
            for (int i = 0; i < 2; i++)
            {
                if (i == 0)
                {
                    name = line;
                }
                else
                {
                    getline(ifs, line);
                    money = getPair(line).first;
                    nPeople = getPair(line).second;
                    
                    if (money != 0)
                    {
                        int inc = money / nPeople;
                        int dec = money % nPeople;
                        addMoney(name, dec - money);

                        for (int j = 0; j < nPeople; j++)
                        {
                            getline(ifs, line);
                            addMoney(line, inc);
                        }
                    }
                    else{
                        for (int j = 0; j < nPeople; j++)
                        {
                            getline(ifs, line);
                        }
                    }
                }
                    
            }
        }
    }
}

int main() {
    ofstream fout ("gift1.out");
    storeData();

    for (map<string, int> :: iterator it = moneyCount.begin(); it != moneyCount.end(); it++)
    {
        fout << it->first << " " << it->second << endl;
    }
    return 0;
}