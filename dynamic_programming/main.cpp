#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <sys/select.h>

struct ScorePending {
	ScorePending();

	int GetScore(const int time_s);

	std::map<int, int> _score_map;
};

ScorePending::ScorePending()
{
    _score_map[10] = 5;
    _score_map[20] = 3;
    _score_map[30] = 2;
    _score_map[60] = 1;
}

int ScorePending::GetScore(const int time_s)
{
    int score = 0;
    auto ritr = _score_map.begin();
    for (; ritr != _score_map.end(); ++ritr) {
        if (time_s > ritr->first)
            continue;
        score = ritr->second;
        break;
    }
    return score;
}

int main() {

    ScorePending sp;

    std::cout << sp.GetScore(0) << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}