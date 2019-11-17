#include <iostream>
#define re register int
const int   HASHSIZE = 5;
const int   MAXSIZE  = 3e5 + 5;
const int   NMAX     = 3e3 + 5;
char        ss[ 1 << 17 ], *A = ss, *B = ss;
inline char gc() {
    if (A == B) {
        B = (A = ss) + fread(ss, 1, 1 << 17, stdin);
        if (A == B)
            return EOF;
    }
    return *A++;
};
template <class T> inline void read(T &x) {
    char c;
    re   y = 1;
    while (c = gc(), c < 48 || 57 < c)
        if (c == '-')
            y = -1;
    x = c ^ 48;
    while (c = gc(), 47 < c && c < 58)
        x = (x << 1) + (x << 3) + (c ^ 48);
    x *= y;
}

const int   buffsize = 1e5;
char        buf[ buffsize ], *pp = buf - 1;
int         readsize = 0, freadsize = 0;
inline void readinit() {
    fread(buf + (((readsize + buffsize - 1) % buffsize >= buffsize / 2 - 1) ? 0 : buffsize / 2), 1,
          buffsize / 2, stdin);
    freadsize += buffsize / 2;
}
inline int read() {
    char c;
    re   y = 1;
    while (c = gc(), c < 48 || 57 < c)
        if (c == '-')
            y = -1;
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
    x *= y;
    return x;
}

int list_arr[ MAXSIZE ][ HASHSIZE ];
int key[ NMAX ][ NMAX ];

using namespace std;
struct list {
    int         count = -1;
    inline void push_back(int val, int time) {
        count++;
        list_arr[ count ][ 0 ] = val;
        list_arr[ count ][ 1 ] = time;
        // for (int j = 0; j < 10; j++)
        //     cout << count << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
    }
    inline void insert(int index, int val, int time) {
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
    inline void remove(int num) {
        while (num > 0) {
            if (list_arr[ 0 ][ 1 ] >= num) {
                list_arr[ 0 ][ 1 ] -= num;
                num = -1;
                // for (int j = 0; j < 10; j++)
                //     cout << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
                // cout << list_arr[ count ][ 1 ];
            } else {
                num -= list_arr[ 0 ][ 1 ];
                // this->remove(count);
                // list_arr[ 0 ][ 1 ] = 0; // list_arr[ i + 1 ][ 1 ];
                // list_arr[ 0 ][ 0 ] = 0;
                erase(0);
                // for (int j = 0; j < 10; j++)
                //     cout << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
            }
        }
    }
    inline void erase(int index) {
        for (int i = index; i < count; ++i) {
            list_arr[ i ][ 0 ] = list_arr[ i + 1 ][ 0 ];
            list_arr[ i ][ 1 ] = list_arr[ i + 1 ][ 1 ];
        }
        list_arr[ count ][ 1 ] = 0; // list_arr[ i + 1 ][ 1 ];
        list_arr[ count ][ 0 ] = 0;

        --count;
    }
    inline void stack_remove(int index, int result) {
        if (list_arr[ index ][ 1 ] > list_arr[ index + 1 ][ 1 ]) {
            int temp = list_arr[ index + 1 ][ 1 ];
            list_arr[ index ][ 1 ] -= list_arr[ index + 1 ][ 1 ];
            this->erase(index + 1);
            this->insert(index + 1, result, temp);
        } else if (list_arr[ index ][ 1 ] < list_arr[ index + 1 ][ 1 ]) {
            int temp = list_arr[ index ][ 1 ];
            list_arr[ index + 1 ][ 1 ] -= list_arr[ index ][ 1 ];
            this->erase(index);
            this->insert(index, result, temp);
        } else {
            this->insert(index, result, list_arr[ index ][ 1 ]);
            this->erase(index + 1);
            this->erase(index + 1);
        }
    }
    inline int sum() {
        int sum = 0;
        for (int i = 0; i < count + 1; i++) {
            sum += list_arr[ i ][ 1 ];
        }
        return sum;
    }
    inline int get_val(int index) {
        return list_arr[ index ][ 0 ];
    }
    inline int get_time(int index) {
        return list_arr[ index ][ 1 ];
    }
    inline void balance() {
        for (int i = count; i > 0; --i) {
            if (list_arr[ i - 1 ][ 0 ] == list_arr[ i ][ 0 ]) {
                list_arr[ i - 1 ][ 1 ] += list_arr[ i ][ 1 ];
                this->erase(i);
            } else {
                break;
            }
        }
    }
};

int main() {
    re n, m, k;
    cin >> n >> m >> k;
    // Queue     q;
    // HashTable ht;
    re num1;
    re num2;
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
        re val1, val2;
        read(val1);
        read(val2);
        // cout << val;
        val1 += 1;
        if (val1 == 0) {
            opt.remove(val2);
            if (opt.get_time(opt.count) == 0) {
                opt.erase(opt.count);
            }
        } else {
            // for (int y = 0; y < 10; y++)
            //     cout << list_arr[ y ][ 0 ] - 1 << " 1   " << list_arr[ y ][ 1 ] << " " << endl;
            opt.push_back(val1, val2);
            // cout << "----------------\n";
            // for (int j = 0; j < 10; j++)
            //     cout << list_arr[ j ][ 0 ] - 1 << " " << list_arr[ j ][ 1 ] << " " << endl;
            // opt.balance();
            // for (int j = 0; j < 10; j++)
            //     cout << list_arr[ j ][ 0 ] - 1 << " 1 " << list_arr[ j ][ 1 ] << " " << endl;
            re j = opt.count;
            while (j > 0) {
                if (key[ opt.get_val(j - 1) ][ opt.get_val(j) ] > 0) {
                    opt.stack_remove(j - 1, key[ opt.get_val(j - 1) ][ opt.get_val(j) ]);
                    // opt.balance();
                    // for (int y = 0; y < 10; y++)
                    //     cout << list_arr[ y ][ 0 ] - 1 << " 1   " << list_arr[ y ][ 1 ] << " "
                    //          << endl;
                    for (int k = j; k <= opt.count; ++k) {
                        if (key[ opt.get_val(k - 1) ][ opt.get_val(k) ] > 0) {
                            // for (int y = 0; y < 10; y++)
                            //     cout << list_arr[ y ][ 0 ] - 1 << " 1   " << list_arr[ y ][ 1 ]
                            //          << " " << endl;
                            opt.stack_remove(k - 1, key[ opt.get_val(k - 1) ][ opt.get_val(k) ]);
                            // opt.balance();
                            j = k + 1;
                        }
                    }
                } else {
                    break;
                }
                j--;
            }
        }

        // for (int j = 0; j < opt.count; j++) cout << list_arr[j][0]-1 << "=====\t";cout << endl;
        // for (int j = 0; j < opt.count; j++) cout << list_arr[j][1] << "\t";cout << endl;
    }

    cout << opt.sum() << "\n";
}
