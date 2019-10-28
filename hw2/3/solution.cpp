#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define HASHSIZE 5
#define MAXSIZE 30005
int list_arr[ MAXSIZE ][ MAXSIZE ];
struct list {

    int  count = 0;
    void push_back(int val, int time) {
        count++;
        list_arr[ count ][ 0 ] = val;
        list_arr[ count ][ 1 ] = time;
    };
    void push_front(int val, int time) {
        count++;
        for (int i = count - 1; i >= 0; --i) {
            list_arr[ i + 1 ][ 0 ] = list_arr[ i ][ 0 ];
            list_arr[ i + 1 ][ 1 ] = list_arr[ i ][ 1 ];
        }
        list_arr[ 0 ][ 0 ] = val;
        list_arr[ 0 ][ 1 ] = time;
    }

    void erase(int index) {
        --count;
        for (int i = index; i < count; ++i) {
            list_arr[ i ][ 0 ] = list_arr[ i + 1 ][ 0 ];
            list_arr[ i ][ 1 ] = list_arr[ i + 1 ][ 1 ];
        }
    }
    void insert(int index, int val, int time) {
        ++count;
        for (int i = count - 1; i >= index; --i) {
            list_arr[ i + 1 ][ 0 ] = list_arr[ i ][ 0 ];
            list_arr[ i + 1 ][ 1 ] = list_arr[ i ][ 1 ];
        }
        list_arr[ index ][ 0 ] = val;
        list_arr[ index ][ 1 ] = time;
    }
    void remove(int num) {
        int num1 = num;
        while (num1 >= 0) {
            if (list_arr[ count ][ 1 ] >= num1) {
                list_arr[ count ][ 1 ] -= num1;
            } else {
                count--;
                num1 -= list_arr[ count ][ 1 ];
            }
        }
    }
    void stack_remove(int index, int result) {
        if (list_arr[ index ][ 1 ] > list_arr[ index + 1 ][ 1 ]) {
            this->insert(index, result, list_arr[ index + 1 ][ 1 ]);
        } else {
            this->insert(index, result, list_arr[ index ][ 1 ]);
        }
    }
};

const int   buffsize = 1e5;
char        buf[ buffsize ], *pp = buf - 1;
int         readsize = 0, freadsize = 0;
inline void readinit() {
    fread(buf + (((readsize + buffsize - 1) % buffsize >= buffsize / 2 - 1) ? 0 : buffsize / 2), 1,
          buffsize / 2, stdin);
    freadsize += buffsize / 2;
}
inline int read() {
    if (readsize + buffsize / 2 > freadsize)
        readinit();
    while ((++readsize, *++pp) < '-')
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    register int x = *pp & 15;
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    while ((++readsize, *++pp) > '-') {
        x = x * 10 + (*pp & 15);
        if (pp == buf + buffsize - 1)
            pp = buf - 1;
    }
    if (pp == buf + buffsize - 1)
        pp = buf - 1;
    return x;
}

int main() {
    int n = read();
    int m = read();
    int k = read();
    int key[ MAXSIZE ][ MAXSIZE ];
    // Queue     q;
    // HashTable ht;
    int num1;
    int num2;

    for (int i = 0; i < m; ++i) {
        num1                = read();
        num2                = read();
        key[ num2 ][ num1 ] = key[ num1 ][ num2 ] = read();
    }
    list opt;
    for (int i = 0; i < k; ++i) {
        int val1 = read();
        int val2 = read();
        if (val1 == -1) {
            opt.remove(val2);
        } else {
            opt.push_back(val1, val2);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (key[ list_arr[ i ][ 0 ] ][ list_arr[ i + 1 ][ 0 ] ] >= 0) {
            opt.stack_remove(i, key[ list_arr[ i ][ 0 ] ][ list_arr[ i + 1 ][ 0 ] ]);
            --i;
        }
    }
}
