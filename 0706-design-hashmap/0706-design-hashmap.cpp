class MyHashMap {
    vector<int> Table;
    const int Empty = -1;
public:
    MyHashMap()
    {
        Table.resize(1000001, Empty);
    }
    
    void put(int key, int value)
    {
        Table[key] = value;
    }
    
    int get(int key)
    {
        return Table[key];
    }
    
    void remove(int key)
    {
        Table[key] = Empty;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */