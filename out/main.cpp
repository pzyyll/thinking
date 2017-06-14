#include <iostream>
#include <fstream>

using namespace std;

int main() {

  ofstream fout("out.txt");

  int n = 250000;
  fout << n << endl;
  for (int i = 0; i < n; ++i) {
    int num = rand() % 5000 + 1;
    fout << num << " ";
  }
  fout << endl;
  int m = 10000;
  fout << m << endl;
  for (int i = 0; i < m; ++i) {
    int x = rand() % n + 1;
    int y = rand() % 5000 + 1;
    fout << x << " " << y << endl;
  }

  return 0;
}