#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<int, int> count(const std::vector<int> &vec) {
    std::unordered_map<int, int> map;
    for (const auto &it : vec) {
        map[it]++;
    }
    return map;
}

int main() {
    std::vector<int> exampleVector = {1, 2, 3, 2, 1, 3, 4, 5, 4, 5, 1};
    std::unordered_map<int, int> map = count(exampleVector);
    for (const auto &it1 : map) {
        std::cout << "Phan tu: " << it1.first << ", So lan xuat hien: " << it1.second << std::endl;
    }
    return 0;
}