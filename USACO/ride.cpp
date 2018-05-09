/*
ID: francis40
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getValue(char ch)
{
    switch(ch){
        case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        case 'E': return 5;
        case 'F': return 6;
        case 'G': return 7;
        case 'H': return 8;
        case 'I': return 9;
        case 'J': return 10;
        case 'K': return 11;
        case 'L': return 12;
        case 'M': return 13;
        case 'N': return 14;
        case 'O': return 15;
        case 'P': return 16;
        case 'Q': return 17;
        case 'R': return 18;
        case 'S': return 19;
        case 'T': return 20;
        case 'U': return 21;
        case 'V': return 22;
        case 'W': return 23;
        case 'X': return 24;
        case 'Y': return 25;
        case 'Z': return 26;
    }
    return 1;
}

bool isValid(char commet[], char group[])
{
    int product1 = 1, product2 = 1;

    for (int i = 0; i < 6; i++)
    {
        product1 *= getValue(commet[i]);
        product2 *= getValue(group[i]);
    }

    if ((product1 % 47) == (product2 % 47))
        return true;
    return false;
}

int main() {
    ofstream fout ("ride.out");
    ifstream ifs;
    ifs.open("ride.in");
    string line;
    
    if(ifs.is_open())
    {
        char commet[6];
        char group[6];
        for (int i = 0; i < 2; i++)
        {
            getline(ifs, line);
            if (i == 0)
                for (int j = 0; j < 6; j++)
                {
                    commet[j] = line.c_str()[j]; 
                }
            else
                for (int j = 0; j < 6; j++)
                {
                    group[j] = line.c_str()[j]; 
                }
        }
        if (isValid(commet, group))
            fout << "GO" << endl;
            //cout << "GO" << endl;
        else
            fout << "STAY" << endl;
            //cout << "STAY" << endl;
    }
    return 0;
}
