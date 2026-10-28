#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int capacity;

    list<pair<int, int>> cache;

    unordered_map<
        int,
        list<pair<int, int>>::iterator
    > positions;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (positions.find(key) == positions.end()) {
            return -1;
        }

        auto it = positions[key];

        int value = it->second;

        cache.splice(cache.begin(), cache, it);

        return value;
    }

    void put(int key, int value) {
        if (positions.find(key) != positions.end()) {
            auto it = positions[key];

            it->second = value;
            cache.splice(cache.begin(), cache, it);

            return;
        }

        if (cache.size() == capacity) {
            int oldestKey = cache.back().first;

            positions.erase(oldestKey);
            cache.pop_back();
        }

        cache.push_front({key, value});
        positions[key] = cache.begin();
    }
};
