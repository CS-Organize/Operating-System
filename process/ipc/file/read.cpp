#include <iostream>
#include <fstream>

using namespace std;

const char* FILENAME = "file.txt";

int main(void)
{
    fstream rFile(FILENAME);
    string s;
    if (!rFile.is_open())
    {
        cout << "Failed to open " << FILENAME << endl;
        exit(EXIT_FAILURE);
    }
    getline(rFile, s);
    cout << s << endl;
    remove(FILENAME);
    rFile.close();
    return 0;
}
