#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// A struct containing whether each of the fields of the passport is there or not
struct Passport
{
    bool byr = false;
    bool iyr = false;
    bool eyr = false;
    bool hgt = false;
    bool hcl = false;
    bool ecl = false;
    bool pid = false;
    bool cid = false;

    bool is_valid() {
        return (byr && iyr && eyr && hgt && hcl && ecl && pid);
    }
};

int main()
{
    // Amount of valid passports
    int valid = 0;

    string line;
    ifstream myfile("input4.txt");
    if (myfile.is_open())
    {
        Passport passport;

        // Loop over all lines of the input file
        while (getline(myfile, line))
        {
            // Load the passport information
            if ((line.find("byr") != string::npos))
                passport.byr = true;
            if ((line.find("iyr") != string::npos))
                passport.iyr = true;
            if ((line.find("eyr") != string::npos))
                passport.eyr = true;
            if ((line.find("hgt") != string::npos))
                passport.hgt = true;
            if ((line.find("hcl") != string::npos))
                passport.hcl = true;
            if ((line.find("ecl") != string::npos))
                passport.ecl = true;
            if ((line.find("pid") != string::npos))
                passport.pid = true;
            if ((line.find("cid") != string::npos))
                passport.cid = true;

            // If there is a newline, then the previous passport is complete
            // We can check whether it is valid and then empty the Passport object
            if (line == "")
            {
                cout << passport.is_valid() << endl;
                if (passport.is_valid())
                    valid++;
                passport.byr = false;
                passport.iyr = false;
                passport.eyr = false;
                passport.hgt = false;
                passport.hcl = false;
                passport.ecl = false;
                passport.pid = false;
                passport.cid = false;
            }
        }
        // Check whether the last passport is valid
        if (passport.is_valid())
            valid++;

        myfile.close();
    }
    else
        cout << "Unable to open file";

    cout << valid << endl;

    return 0;
};
