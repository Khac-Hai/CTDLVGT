#include <iostream>
#include "bam.h"

HashSet::HashSet(const long bucket_array_size): BUCKET_ARRAY_SIZE(bucket_array_size),
bucket_array(bucket_array_size, BucketType())
{}

HashSet::~HashSet(){
}

bool Search(const KeyType key) const {
    return true
}

int HashSet::HashFun(const KeyType key) const{
    return static_cast<int> (key) % BUCKET_ARRAY_SIZE;
}

void HashSet::Insert(const KeyType key) const{
    int k = HashFun(key);
    BucketType &bucket = bucket_array[k];
    bucket_array[k].push_back(key);
}

void HashSet::Print() const {
    for( auto it = bucket_array.begin(); it != bucket_array.end();it++){
        if(it->empty())
        continue;
        for(auto it1 = it->begin(); it1 != it->end(); it1++){
            std::cout << *it1 << " ";
        }
        std::cout << std::endl; 
    }
}

int main(){
    HashSet Set(5);
}
