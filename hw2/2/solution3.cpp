#include <iostream>

using namespace std;
int main() {
    int m[ 5 ];
    m[ 0 ]    = 1;
    m[ 1 ]    = 213;
    m[ 2 ]    = 1;
    m[ 3 ]    = 1;
    m[ 4 ]    = 1;
    m[ 5 ]    = 1322;
    int index = 0;
    for (int i = 0; i < 5; ++i) {
        // for (int i = 0; i < i - 5 - 1; ++i) {
        if (m[ i ] > m[ i + 1 ]) {
            index = i;
        } else {
            index = i + 1;
        }
        // }
    }
    cout << index << endl;
}