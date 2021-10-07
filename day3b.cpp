#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Slope
{
    Slope(int x_in, int y_in):
        x(x_in),
        y(y_in)
    {}

    int x;
    int y;
};

int main()
{
    // Slopes
    vector<Slope> slopes = {Slope(1,1), Slope(3,1), Slope(5,1), Slope(7,1), Slope(1,2)};

    // Pre-define variable to which the input will be read
    string line;

    // Vector in which the number of trees will be stored for each slope
    vector<int> trees_vector;

    // Loop over all slopes
    for (auto slope : slopes)
    {
        // Amount of trees in this slope
        int trees = 0;
        // Horizontal and vertical position
        int x = 1;
        int y = 0;

        ifstream myfile("input3.txt");
        if (myfile.is_open())
        {
            // Loop over all lines of the input file
            while (getline(myfile, line))
            {
                // Increase y, and if y is even and the y slope = 2, we skip one line
                y++;
                if (slope.y == 2 && y%2==0)
                    continue;

                if (line[x - 1] == '#')
                    trees++;

                // Increase horizontal position
                x += slope.x;
                if (x > line.size())
                    x -= line.size();
            }
            myfile.close();
        }
        else
            cout << "Unable to open file";

        trees_vector.push_back(trees);
    }

    long int multiplied_trees = 1;
    // Loop over the trees vector and multiply all elements
    for (auto trees : trees_vector)
        multiplied_trees *= trees;

    cout << multiplied_trees << endl;

    return 0;
};
