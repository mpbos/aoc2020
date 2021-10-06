#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    ifstream myfile("input2.txt");
    if (myfile.is_open())
    {
        // Loop over all lines of the input file
        while (getline(myfile, line))
        {
            // Get the lowest number
            auto idx = line.find('-');
            int lowest = stoi(line.substr(0, idx));
            line = line.substr(idx + 1, line.size() - idx);

            // Get the highest number
            idx = line.find(' ');
            int highest = stoi(line.substr(0, idx));
            line = line.substr(idx + 1, line.size() - idx);

            // Get the letter
            idx = line.find(':');
            string letter = line.substr(0, idx);
            line = line.substr(idx+2, line.size() - idx);

            // Get the corrupted password
            string password = line;

            cout << lowest << "...";
            cout << highest << "...";
            cout << letter << "...";
            cout << password << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    return 0;
};
