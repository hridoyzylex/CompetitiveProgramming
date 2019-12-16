#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        string number;
        cin >> number;        // read input as a string
        cout << number[0];    // output the leftmost digit
        for (int i=1; i < number.length(); i++) {
            // if the position is divisible by 3 from the right side
            //    put a comma
            if ((number.length()-i) % 3 == 0)
                cout << ',';
            cout << number[i];
        }
        cout << endl;
    }
    return 0;
}
