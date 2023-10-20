#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <climits>

int find_min_distance(const std::string& s)
{
    int min_distance = INT_MAX;
    auto pos_x = s.find('X');
    auto pos_y = s.find('Y');

    if (pos_x == std::string::npos)
        return -1;
    if (pos_y == std::string::npos)
        return -1;
    int counter = 0;
    for (size_t i = pos_x; i < s.size(); ++i)
    {
        if (s[i] == 'Y' && counter < min_distance)
            min_distance = counter;
        else if (s[i] == 'X')
            counter = 0;
        else
            ++counter;
    }
    counter = 0;
    for (size_t i = pos_y; i < s.size(); ++i)
    {
        if (s[i] == 'X' && counter < min_distance)
            min_distance = counter;
        else if (s[i] == 'Y')
            counter = 0;
        else
            ++counter;
    }

    return min_distance;
}

void test_cases()
{
    std::vector<std::pair<std::string, int>> test_vector = {
        std::pair<std::string, int>{"XOOOY", 3},
        std::pair<std::string, int>{"XOOOOOOO", -1},
        std::pair<std::string, int>{"XOXXXOOOYXOYXYYOY", 0},
        std::pair<std::string, int>{"YOOXOOOYOXOOOX", 1},
        std::pair<std::string, int>{"YOOXOYX", 0},
        std::pair<std::string, int>{"XOOOOOYOOOOXOOY", 2},
        std::pair<std::string, int>{"YYYOOOOOOYYYOO", -1}
    };
    for (int i = 0; i < test_vector.size(); ++i)
    {
        auto result = find_distance(test_vector[i].first);
        std::cout << "test " << i + 1 << ": " << test_vector[i].first << ", result: " << result << " | exptected: " << test_vector[i].second << std::endl;
        assert(result == test_vector[i].second);
    }
    std::cout << "\n-------------SUCCESS-------------";
}

int main()
{
    test_cases();
}
