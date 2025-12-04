#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void pressEnterToContinue(); bool readFromFile(string filename);


int main() {

    string datafile;
    string word;
    //
    int numWord = 0;
    int numChars = 0;

    cout << "Lab 12 Intro to Text Files!\n";
    cout << "Enter filename: ";
    getline(cin, datafile);

    bool status = readFromFile(datafile);
    if (status) {
        cout << "Success!\n";

        ifstream file(datafile);
        char c;

        while (file.get(c)) {
           if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c=='-' || c == '\'' || (c == '!') || (c == '.') || c == ';' || (c == ',') || c == '?' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') {
                numChars++;
            }
        }

        file.clear();
        file.seekg(0);

        while (file >> word) {
            string cleanWord;
            //for (char ch : word) {
               // if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
                    //cleanWord += ch;
                //}
            //}

            //if (!cleanWord.empty()) {
                //numWord++;
            //}
                numWord++;
        }

        file.close();

        cout << "Words: " << numWord << endl;
        cout << "Characters: " << numChars << endl;
    }
    else {
        cout << "failure. :-(\n";
    }



    pressEnterToContinue();
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
    ifstream inFile;
    string movieTitle;
    int year;
    inFile.open(filename);

    if (inFile.fail()) {
        cout << "read error - sorry\n";
        return false;
    }

    while (true) {
        inFile >> movieTitle >> year;
        if (inFile.fail()) break;

    }

    inFile.close();
    return true;
}