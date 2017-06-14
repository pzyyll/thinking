#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <iterator>
#include<bits/stdc++.h>

using namespace std;

#ifdef FILEINPUT
ifstream fin("input.txt");
ofstream fout("out.txt");
#define cin fin
#define cout fout
#endif  //FILEINPUT

typedef int arrele_t;
const unsigned int MAXN = 250000 + 1000;
arrele_t usA[MAXN];
arrele_t tempA[MAXN];
arrele_t alloc[MAXN];
long long res[11000];

long long merge(arrele_t *arr, int p, int q, int r) {
  int llen = q - p + 1;
  int rlen = r - q;
  long long cnt = 0;
  arrele_t *larr = alloc;
  arrele_t *rarr = alloc + llen;

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
      cnt += llen - il;
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
  return cnt;
}

long long merge_sort_(arrele_t *arr, int p, int r) {
  long long n = 0;
  if (p < r) {
    int m = p + (r - p) / 2;
    n = merge_sort_(arr, p, m);
    n += merge_sort_(arr, m + 1, r);
    n += merge(arr, p, m, r);
  }

  return n;
}

long long count_inver(arrele_t *arr, int size_) {
  memcpy(tempA, arr, size_ * sizeof(arrele_t));
  return merge_sort_(tempA, 0, size_ - 1);
}

long long sort_part(arrele_t *arr, int n, int step) {
  int loop = n / step;
  long long invcnt = 0;
  int p = 0, m = 0, r = 0;
  int i = 0;
  for (i = 0; i < loop; ++i) {
    p = step * i;
    r = p + step - 1;
    m = p + (r - p) / 2;
    invcnt += merge(arr, p, m, r);
  }

  //这里好像不太严谨
  if ((p = step * i) < n) {
    int residue = n - p;
    if (residue > step / 2)
      invcnt += merge(arr, p, p + step / 2 - 1, n - 1);
  }

  return invcnt;
}

long long merge_sort_v2(arrele_t *arr, int n) {
  int step = 2;
  long long invcnt = 0;
  while (step < n) {
    invcnt += sort_part(arr, n, step);
    step *= 2;
  }
  invcnt += sort_part(arr, n, step);

  return invcnt;
}

long long count_inver_v2(arrele_t *arr, int size_) {
  memcpy(tempA, arr, size_ * sizeof(arrele_t));
  return merge_sort_v2(tempA, size_);
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
    int x, y;
    cin >> x >> y;
    usA[x - 1] = y;

    cout << count_inver_v2(usA, n) << endl;
    //cout << count_inver(usA, n) << endl;
  }

  return 0;
}