#include <iostream>
using namespace std;

int iYear;

int main() {
    cin >> iYear;
    
    if (iYear % 4 == 0) {
        if (iYear % 100 != 0) {
            cout << "1" << endl;
        }
        else if (iYear % 400 == 0) {
            cout << "1" << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
    else
        cout << "0" << endl;
}