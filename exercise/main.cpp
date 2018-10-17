#include <iostream>

using namespace std;

int DiffDays(const unsigned begin, const unsigned end) {
    if (begin >= end) return 0;
    return (end - begin) / (1 * 24 * 3600);
}

int main() {
    cout << DiffDays(1539723599, 1539637200) << endl;
    cout << "end" << endl;
    return 0;
}
