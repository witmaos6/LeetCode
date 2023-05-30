class MyHashSet
{
    vector<bool> Table;
public:
    MyHashSet()
    {
        Table.resize(1000001);
    }
    
    void add(int key)
    {
        Table[key] = true;
    }
    
    void remove(int key)
    {
        Table[key] = false;
    }
    
    bool contains(int key)
    {
        return Table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */