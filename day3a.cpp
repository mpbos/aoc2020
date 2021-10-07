#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Amount of trees
    int trees = 0;
    // Horizontal position
    int x = 1;

    string line;
    ifstream myfile("input3.txt");
    if (myfile.is_open())
    {
        // Loop over all lines of the input file
        while (getline(myfile, line))
        {
            if (line[x-1] == '#')
                trees++;

            // Increase horizontal position
            x += 3;
            if (x > line.size())
                x -= line.size();
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    cout << trees << endl;

    return 0;
};
