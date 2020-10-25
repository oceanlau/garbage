#include <iostream>
using namespace std;

constexpr int get_ce5() {
    return 5;
}
int di1;
int main() {
    // string to int
    cout << "string to int" << endl;
    // How to check? https://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
    cout << stoi("1") << endl;
    cout << stoi("1a") << endl;
    //cout << stoi("a1") << endl; // Throw error
    cout << endl;

    // constant expression
    const string ce1 = "Hello";
    //constexpr string ce2 = ce1; // Compiler error, string is not literal type
    const int ce3 = 10;
    constexpr int ce4 = ce3;
    constexpr int ce5 = get_ce5();

    //default initialization
    cout << "default initialization" << endl;
    int di2;
    cout << di1 << endl;
    cout << di2 << endl;
    cout << endl;

    return 0;
}
