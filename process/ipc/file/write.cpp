#include <iostream>
#include <fstream>

using namespace std;

const char* FILENAME = "file.txt";

int main(void)
{
    fstream wFile(FILENAME, fstream::out);
    if (!wFile.is_open())
    {
        cout << "Failed to open " << FILENAME << endl;
        exit(EXIT_FAILURE);
    }
    wFile << "Hello, File!";
    wFile.close();
    return 0;
}
