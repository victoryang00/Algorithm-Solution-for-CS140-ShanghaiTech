#include <iostream>
#include <stack>
using namespace std;

void showstack(stack<int> s) {
    while (!s.empty()) {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int main() {
    stack<int> s;
    int        k, *m, count;
    cin >> k;
    if (k == 0)
        return 0;
    for (int i = 0; i < k; ++i) {
        cin >> m[ i ];
    }
    s.push(m[ 0 ]);
    for (int i = 0; i < k; ++i) {
        if (m[ i ] <= s.top()) {
            s.push(m[ i ]);
            count++;
        } else {
            while (!s.empty()) {
                if (m[ i ] > s.top()) {
                    s.pop();
                    count++;
                } else {
                    break;
                }
            }
            if (s.empty()) {
                count++;
            }
            s.push(m[ i ]);
        }
    }

    return 0;
}