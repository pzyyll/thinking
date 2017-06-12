#include <iostream>

using namespace std;

typedef unsigned short arrele_t;
const unsigned int MAXN = 250000;
arrele_t usA[MAXN];
unsigned int cnt;

struct SArr {
    arrele_t *usA;
    unsigned int len;
};

void merge(arrele_t *arr, int p, int q, int r)
{
    int llen = q - p + 1;
    int rlen = r - q;

    arrele_t *larr = new arrele_t[llen + 1];
    arrele_t *rarr = new arrele_t[rlen + 1];

    for (int i = 0; i < llen; ++i) {
        larr[i] = arr[p + i];
    }
    larr[llen] = static_cast<arrele_t>(-1);
    for (int i = 0; i < rlen; ++i) {
        rarr[i] = arr[q + i + 1];
    }
    rarr[rlen] = static_cast<arrele_t>(-1);

    int il = 0, ir = 0;
    for (int i = 0; i < llen + rlen; ++i) {
        if (larr[il] > rarr[ir]) {
            arr[i] = rarr[ir++];
            ++cnt;
        } else {
            arr[i] = larr[il++];
        }
    }

    delete[] larr;
    delete[] rarr;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> usA[i];
    }

    int m = 0;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        unsigned short x, y;
        cin >> x >> y;
        usA[x] = y;
    }


    return 0;
}