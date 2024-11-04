#include <iostream>
#include <vector>

void quick_sort(std::vector<int> arr, const int begin, const int end){
    if(begin >= end)
    return;
    int pi;
    ip = partition(arr, begin, end);
        quick_sort(arr, begin, ip - 1);
        quick_sort(arr, ip + 1, end);
    }

int partition(std::vector<int> arr, const int begin, const int end){
    int pivot = a[begin];
    int i = begin - 1;
    int j = begin + 1;
    while(1){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while (a[i] > pivot);

        if(i >= j){
            return j;
        }
        swap(a[i], a[j]);
    }
}