class MyHashMap {
    static const int SIZE = 1009;
    vector<list<pair<int, int>>> table;

    int hash(int key) { return key % SIZE; }

public:
    MyHashMap() : table(SIZE) {}

    void put(int key, int value) {
        int h = hash(key);
        for (auto& [k, v] : table[h])
            if (k == key) { v = value; return; }
        table[h].emplace_back(key, value);
    }

    int get(int key) {
        int h = hash(key);
        for (auto& [k, v] : table[h])
            if (k == key) return v;
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        table[h].remove_if([&](auto& p) { return p.first == key; });
    }
};
