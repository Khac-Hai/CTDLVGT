#include<iostream>
#include<unordered_set>

void Print(const std::unordered_set<char> &set){
    for(auto it = set.begin(); it != set.end(); it++)
    std::cout << *it << " ";
    std::cout << std::endl;
}

int main(){
    std::unordered_set<char> set;

    set.insert('c');
    set.insert('d');
    set.insert('e');
    set.insert('f');

    Print(set);
    
    auto it = set.find('d');
    if(it == set.end())
        std::cout << "These is no sush element" << std::endl;
    else
        std::cout << *it << std::endl;
    std::cout <<     
}