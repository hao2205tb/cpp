#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

int main() {
    
    fstream file;
    file.open("../data.csv", ios::in);
    
    string str;
    
    vector<vector<string>> db;
    string line;

    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line); 
        string cell;

        while (getline(ss, cell, ',')) // note: using ',' (char) instead "," (string)
        {
            row.push_back(cell);
            cout << cell;
        }
        db.push_back(row);
        cout << endl;  
    }

    file.close();

    return 0;
}
