#include <iostream>
using namespace std;

const int MAXSIZE = 1e5 + 5;

int       n;
long long m[ MAXSIZE ], k[ MAXSIZE ], sum[ MAXSIZE ];
int       main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[ i ];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[ i ];
        sum[ i ] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[ j ] <= k[ i ]) {
                sum[ i ] += m[ j ];
                m[ j ] = 0;
            } else {
                m[ j ] -= k[ i ];
                sum[ i ] += k[ i ];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sum[ i ] << " ";
    }
    cout << "\n";
}