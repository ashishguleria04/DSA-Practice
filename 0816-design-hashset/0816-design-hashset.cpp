class MyHashSet {
private:
    static const int SIZE = 1009; 
    vector<list<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() : table(SIZE) {}

    void add(int key) {
        int h = hash(key);
        for (int val : table[h])
            if (val == key) return;
        table[h].push_back(key);
    }

    void remove(int key) {
        int h = hash(key);
        table[h].remove(key);
    }

    bool contains(int key) {
        int h = hash(key);
        for (int val : table[h])
            if (val == key)
                return true;
        return false;
    }
};
