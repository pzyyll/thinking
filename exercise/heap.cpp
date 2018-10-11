#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef bool (*compare)(const int a, const int b);

bool Less(const int a, const int b) {
    return a < b;
}

bool Greater(const int a, const int b) {
    return a > b;
}

inline int Left(const int p) {
    return p * 2 + 1;
}

inline int Right(const int p) {
    return Left(p) + 1;
}

inline int Parent(const int c) {
    return (c - 1) / 2;
}

inline int GetDepth(const int i) {
    if (0 == i) return 1;
    int depth = 1;
    while (true) {
        int min = (0x1 << (depth - 1)) - 1;
        int max = (0x1 << depth) - 2;
        if (min <= i && i <= max)
            return depth;
        else
            ++depth;
    }
}

void PrintHeap(const vector<int> &seq, const unsigned root) {
    if (root >= seq.size())
        return;

    deque<int> que;
    que.push_front(root);
    int depth = 1;
    while (que.size() > 0) {
        int idx = que.back();
        que.pop_back();

        if (depth != GetDepth(idx)) {
            cout << endl;
            depth = GetDepth(idx);
        }

        cout << seq[idx] << " ";
        if (Left(idx) < seq.size())
            que.push_front(Left(idx));
        if (Right(idx) < seq.size())
            que.push_front(Right(idx));
    }
    cout << endl;
}


void KeepHeap(vector<int> &seq, const unsigned heap_size, const unsigned root, const compare compare_func = Less) {
    if (root >= heap_size) {
        return;
    }

    unsigned left_idx = Left(root);
    unsigned right_idx = Right(root);

    unsigned cmp_idx = root;
    if (left_idx < heap_size && compare_func(seq[cmp_idx], seq[left_idx]))
        cmp_idx = left_idx;
    if (right_idx < heap_size && compare_func(seq[cmp_idx], seq[right_idx]))
        cmp_idx = right_idx;

    if (root != cmp_idx) {
        std::swap(seq[root], seq[cmp_idx]);
        KeepHeap(seq, heap_size, cmp_idx, compare_func);
    }
}

void BuildHeap(vector<int> &seq, const compare compare_func = Less) {
    for (unsigned i = seq.size() / 2; ; --i) {
        KeepHeap(seq, seq.size(), i, compare_func);
        if (0 == i) break;
    }
}

void HeapSort(vector<int> &seq, const compare compare_func = Less) {
    BuildHeap(seq, compare_func);

    unsigned heap_size = seq.size();
    for (unsigned i = seq.size(); i >= 2; --i) {
        std::swap(seq[0], seq[heap_size - 1]);
        --heap_size;
        KeepHeap(seq, heap_size, 0, compare_func);
    }
}

int main() {
    std::vector<int> seq{88,1,2,5,3,3,90,8};

    HeapSort(seq);

    for (const auto &itr : seq) {
        cout << itr << " ";
    }
    cout << endl;

    cout << "end" << endl;
    return 0;
}
