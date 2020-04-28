#include <iostream>
using namespace std;

int main() {
    //string to int
    // How to check? https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
    cout << stoi("1") << endl;
    cout << stoi("1a") << endl;
    //cout << stoi("a1") << endl; // Throw error
    return 0;
}
