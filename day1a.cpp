#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> inputs;
    string line;
    ifstream myfile("input1.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            inputs.push_back(stoi(line));
        }
        myfile.close();
    }
    else
        cout << "Unable to open file";

    for (int i = 0; i < inputs.size(); ++i)
    {
        for (int j = i + 1; j < inputs.size(); ++j)
        {
            if (inputs[i] + inputs[j] == 2020)
                cout << inputs[i] << " + " << inputs[j] << " = 2020       " << inputs[i] << " * "
                     << inputs[j] << " = " << inputs[i] * inputs[j] << endl;
        }
    }

    return 0;
};
