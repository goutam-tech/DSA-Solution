#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;

    map<string, int> db;

    while (n--)
    {
        string name;
        cin >> name;

        if (db.find(name) == db.end())
        {
            db[name] = 0;
            cout << "OK\n";
        }
        else
        {
            db[name]++;
            string newName = name + to_string(db[name]);
            while (db.find(newName) != db.end())
            {
                db[name]++;
                newName = name + to_string(db[name]);
            }
            db[newName] = 0;
            cout << newName << "\n";
        }
    }
    return 0;
}