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
        for (int j = i; j < n; j++) {
            if (m[ i ] <= k[ j ]) {
                sum[ j ] += m[ i ];
                break;
            } else {
                sum[ j ] += k[ j ];
                m[ i ] -= k[ j ];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << sum[ i ] << " ";
    }
    cout << "\n";
}