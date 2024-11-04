#pragma once

#include<vector>
#include<list>

using KeyType = char;
using BucketType = std::list<KeyType> ;

class HashSet{
    public:
        HashSet(const long bucket_array_size);
        ~HashSet();
        bool Search(const KeyType key);
        void Insert(const KeyType key);
        void Remove(const KeyType key);
        void Print() const;

        int HashFun(const KeyType key) const;

    private:
        long BUCKET_ARRAY_SIZE;
        std::vector<BucketType> bucket_array; //bảng băm
        
};
