#include<iostream>
#include<vector>

int binary_search(const std::vector<int> &a, const int x){
    int begin = 0;
        int end = a.size() - 1;
    while (begin < end){
        int mid = (begin + end) / 2;
        if (a[mid] == x)
            return mid;
        if (x < a[mid])
            end = mid - 1;
        else // x > a[mid]
            begin = mid + 1;

    }
    return -1;
}

std::vector<std::pair<int, int>> pair_search(const std::vector<int> &a, const int diff){
    std::vector<std::pair<int, int>> result;
    for(auto x2:a){
        int x1 = x2 + diff;
        if(binary_search( a, 0, a.size() - 1, x1) >= 0)
        result.push_back(std::make_pair(x1,x2));

        int x1 = x2 + diff;
        if(binary_search( a, 0, a.size() - 1, x1) >= 0)
        result.push_back(std::make_pair(x1,x2));
    }
    return result;
}

int main(){
    std::vector<int> arr = {1, 5, 10, 75, 200, 325, 360, 800};
    std::cout << "tim x = 300:" << binary_search(arr, 300) << std::endl;
    std::cout << "tim x = 325:" << binary_search(arr, 325);

}