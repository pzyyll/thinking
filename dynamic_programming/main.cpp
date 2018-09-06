#include <iostream>
#include <vector>
#include <map>

#define N 10 + 1

int graph[N][N] = {0};

int main() {

    std::vector<std::map<int, int>> mmap;

    for (unsigned i = 0; i < 10; ++i) {
        std::map<int, int> iimap;
        mmap.push_back(iimap);
    }

    for (auto itr : mmap) {
        for (auto mitr : itr) {
            std::cout << mitr.second << "|" << mitr.first << std::endl;
        }
        std::cout << std::endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}