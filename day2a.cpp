#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Amount of valid passwords
    int valid = 0;

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
            // Get the password
            string password = line;

            // Find how many times the letter is in the password
            int count = 0;
            for (auto c : password)
            {
                if (c == letter[0])
                    count++;
            }

            // If the letter is in the password the correct amount of times, the password is valid
            if (count >= lowest && count <= highest)
                valid++;

        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    cout << valid << endl;

    return 0;
};
