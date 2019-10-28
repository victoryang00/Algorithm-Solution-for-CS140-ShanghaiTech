#include <iostream>
// #include <sstream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
using namespace std;
#define HASHSIZE 5
#define MAXSIZE 300005
int list_arr[ MAXSIZE ][ HASHSIZE ];
int key[ 3000 ][ 3000 ];
struct list {
    int  count = -1;
    void push_back(int val, int time) {
        count++;
        list_arr[ count ][ 0 ] = val;
        list_arr[ count ][ 1 ] = time;
        // for (int j = 0; j < 10; j++)
        //     cout << count << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
    }
    void insert(int index, int val, int time) {
        ++count;
        for (int i = count - 1; i >= index; --i) {
            list_arr[ i + 1 ][ 0 ] = list_arr[ i ][ 0 ];
            list_arr[ i + 1 ][ 1 ] = list_arr[ i ][ 1 ];
            // for (int j = 0; j < 10; j++)
            //     cout << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
        }
        list_arr[ index ][ 0 ] = val;
        list_arr[ index ][ 1 ] = time;
    }
    void remove(int num) {
        // int num1 = num;
        while (num > 0) {
            if (list_arr[ count ][ 1 ] >= num) {
                list_arr[ count ][ 1 ] -= num;
                num = -1;
                // cout << list_arr[ count ][ 1 ];
            } else {

                num -= list_arr[ count ][ 1 ];
                list_arr[ count ][ 1 ] = 0;
                list_arr[ count ][ 0 ] = 0;
                count--;
            }
        }
    }
    void erase(int index) {

        for (int i = index; i < count; ++i) {
            list_arr[ i ][ 0 ] = list_arr[ i + 1 ][ 0 ];
            list_arr[ i ][ 1 ] = list_arr[ i + 1 ][ 1 ];
        }
        list_arr[ count ][ 1 ] = 0; // list_arr[ i + 1 ][ 1 ];
        list_arr[ count ][ 0 ] = 0;
        --count;
    }
    void stack_remove(int index, int result) {
        if (list_arr[ index ][ 1 ] >= list_arr[ index + 1 ][ 1 ]) {
            int temp = list_arr[ index + 1 ][ 1 ];
            list_arr[ index ][ 1 ] -= list_arr[ index + 1 ][ 1 ];
            this->erase(index + 1);
            this->insert(index + 1, result, temp);
        } else if (list_arr[ index ][ 1 ] < list_arr[ index + 1 ][ 1 ]) {
            int temp = list_arr[ index ][ 1 ];
            list_arr[ index + 1 ][ 1 ] -= list_arr[ index ][ 1 ];
            this->erase(index);
            this->insert(index + 1, result, temp);
        } else {
            this->insert(index, result, list_arr[ index ][ 1 ]);
            this->erase(index + 1);
            this->erase(index + 1);
        }
    }
    int sum() {
        int sum = 0;
        for (int i = 0; i < count + 100000; i++) {
            sum += list_arr[ i ][ 1 ];
        }
        return sum;
    }
    int get_val(int index) {
        return list_arr[ index ][ 0 ];
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    // Queue     q;
    // HashTable ht;
    int num1;
    int num2;
    for (int i = 0; i < m; ++i) {
        int num3;
        cin >> num1 >> num2 >> num3;
        num1 += 1;
        num2 += 1;
        num3 += 1;
        key[ num2 ][ num1 ] = num3;
        key[ num1 ][ num2 ] = num3;
    }
    list opt;

    for (int i = 0; i < k; ++i) {
        int val1, val2;
        cin >> val1 >> val2;
        // cout << val;
        val1 += 1;
        if (val1 == 0) {
            opt.remove(val2);
        } else {
            opt.push_back(val1, val2);
        }
    }

    for (int i = 0; i < opt.count; ++i) {
        if (key[ opt.get_val(i) ][ opt.get_val(i + 1) ] > 0) {
            opt.stack_remove(i, key[ opt.get_val(i) ][ opt.get_val(i + 1) ]);
            // for (int j = 0; j < 10; j++)
            //     cout << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
        }
    }
    cout << opt.sum() << "\n";
}