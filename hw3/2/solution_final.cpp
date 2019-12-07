#include <iostream>
using namespace std;
const int KMAX = 400 + 5;
const int INF  = 99999999;
const int NMAX = 2e5 + 5;
int       a[ NMAX ];
int       b[ NMAX ];
int       c[ 3 ][ NMAX ];
int       d[ NMAX ];
int       e[ 2 * KMAX ][ 2 * KMAX ];
int       p[ KMAX ];
int       tmp[ NMAX ];

int QuickSort(int *nums, int left, int right, int k) {
    if (left == right) {
        return nums[ left ];
    }

    if (left < right) { 
        int i   = left;
        int j   = right;
        int key = nums[ left ];
        while (i < j) {
            while (i < j && nums[ j ] < key)
                j--;
            if (i < j) {
                nums[ i ] = nums[ j ];
                i++;
            }
            while (i < j && nums[ i ] >= key)
                i++;
            if (i < j) {
                nums[ j ] = nums[ i ];
                j--;
            }
        }
        nums[ i ] = key;
        if (i > k)
            return QuickSort(nums, left, i - 1, k);
        else if (i < k)
            return QuickSort(nums, i + 1, right, k);
        else
            return nums[ i ];
    }
}

void sort(int array[], int len) {
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (array[ j ] < array[ i ]) {
                temp       = array[ i ];
                array[ i ] = array[ j ];
                array[ j ] = temp;
            }
        }
    }
}
int *sort1(int array[], int len, int kt, int *tmp) // Time complexity k*n,return the index
{
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < kt - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (array[ j ] < array[ i ]) {
                temp       = array[ i ];
                array[ i ] = array[ j ];
                array[ j ] = temp;
                temp       = tmp[ i ];
                tmp[ i ]   = tmp[ j ];
                tmp[ j ]   = temp;
            }
        }
    }
    return tmp;
}
int main() {
    int *dd;
    int  n, m, k, count = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> b[ i ] >> d[ i ] >> a[ i ];
    }
    for (int i = 0; i < m; i++)
        tmp[ i ] = i;
    if (m > 2000) {
        dd = sort1(a, m, 401, tmp);
        n  = 200;
        m  = 400;
    } else {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                e[ i ][ j ] = 0;
            else
                e[ i ][ j ] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        e[ b[i-1] ][ d[i-1] ] = a[i-1];
        e[  d[i-1] ][b[i-1] ] = a[i-1];
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (e[ i ][ j ] > e[ i ][ k ] + e[ k ][ j ])
                    e[ i ][ j ] = e[ i ][ k ] + e[ k ][ j ];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (e[ i ][ j ] != 0 && e[ i ][ j ] != INF) {
                a[ count ] = e[ i ][ j ];
                count++;
            }
        }
    }
    //     for (int l = 1; l <= n; l++) {
    //         for (int j = 1; j <= n; j++) {
    //             printf("%3d", e[ l ][ j ]);
    //         }
    //         cout << endl;
    //     }
    // for (int i = 0 ; i <count ; i ++)
    //     cout<<a[i]<<endl;
    sort(a, count);
    cout << a[ k - 1 ];
    return 0;
    }
    int t = 0;
    int f[ 400 ];
    for (int i = 0; i < n; i++) {
        t = dd[ i ];
        c[ 0 ][ i ]    = b[ t ];
        c[ 1 ][ i ]    = d[ t ];
        c[ 2 ][ i ]    = a[ i ];
        f[ 2 * i ]     = c[ 1 ][ i ];
        f[ 2 * i + 1 ] = c[ 0 ][ i ];
    }
    // for (int i = 0; i < 2 * n; i++) {
    //     cout << f[ i ] << " ";
    // }
    sort(f, 400);
    // for (int i = 0; i < 2 * n; i++) {
    //     cout << f[ i ] << " ";
    // }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (f[ j ] == c[ 0 ][ i ]) {
                c[ 0 ][ i ] = j;
            }
            if (f[ j ] == c[ 1 ][ i ]) {
                c[ 1 ][ i ] = j;
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << c[ 0 ][ i ] << " " << c[ 1 ][ i ] << " " << c[ 2 ][ i ] << endl;
    //     // if (c[ 0 ][ i ] == c[ 1 ][ i ] == 0)== 0 {
    //     //     n = i;
    //     //     break;
    // }
    
    for (int i = 0; i < m; i++) //初始化数组
    {
        for (int j = 0; j < m; j++) {
            if (i == j)
                e[ i ][ j ] = 0;
            else
                e[ i ][ j ] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        e[ c[ 0 ][ i ] ][ c[ 1 ][ i ] ] = c[ 2 ][ i ];
        e[ c[ 1 ][ i ] ][ c[ 0 ][ i ] ] = c[ 2 ][ i ];
    }
    for (int k = 0; k < m; k++) {
        for (int i =0; i < m; i++) {
            for (int j = 1; j <= m; j++) {
                if (e[ i ][ j ] > e[ i ][ k ] + e[ k ][ j ])
                    e[ i ][ j ] = e[ i ][ k ] + e[ k ][ j ];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (e[ i ][ j ] != 0) {
                p[ count ] = e[ i ][ j ];
                count++;
            }
        }
    }

    // for (int i = 0; i < m; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         if (e[ i ][ j ] != INF)
    //             printf("%3d ", e[ i ][ j ]);
    //             else
    //             printf("%3d ", 99);
    //     }
    //     cout << endl;
    // }
    // for (int i = 0 ; i <count ; i ++)
    //     cout<<a[i]<<endl;
    cout << QuickSort(p, 0, count - 1, count - k);
    return 0;
}