#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("input.txt");
#define cin fin

typedef unsigned short arrele_t;
const unsigned int MAXN = 250000 + 1000;
arrele_t usA[MAXN];
arrele_t tempA[MAXN];

int merge(arrele_t *arr, int p, int q, int r) {
  int llen = q - p + 1;
  int rlen = r - q;
  int cnt = 0;
  arrele_t *larr = new arrele_t[llen];
  arrele_t *rarr = new arrele_t[rlen];

  for (int i = 0; i < llen; ++i) {
    larr[i] = arr[p + i];
  }
  for (int i = 0; i < rlen; ++i) {
    rarr[i] = arr[q + i + 1];
  }

  int il = 0, ir = 0, ik = p;
  for (; il < llen && ir < rlen; ++ik) {
    if (larr[il] > rarr[ir]) {
      arr[ik] = rarr[ir++];
      cnt = cnt + (llen - il);
    } else {
      arr[ik] = larr[il++];
    }
  }

  while (il < llen) {
    arr[ik++] = larr[il++];
  }

  while (ir < rlen) {
    arr[ik++] = rarr[ir++];
  }

  delete[] larr;
  delete[] rarr;

  return cnt;
}

int merge_sort_(arrele_t *arr, int p, int r) {
  int n = 0;
  if (p < r) {
    int m = p + (r - p) / 2;
    n = merge_sort_(arr, p, m);
    n += merge_sort_(arr, m + 1, r);
    n += merge(arr, p, m, r);
  }

  return n;
}

int count_inver(arrele_t *arr, int size_) {
  memcpy(tempA, arr, size_ * sizeof(arrele_t));
  return merge_sort_(tempA, 0, size_ - 1);
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
    usA[x - 1] = y;

    cout << count_inver(usA, n) << endl;
  }
  return 0;
}