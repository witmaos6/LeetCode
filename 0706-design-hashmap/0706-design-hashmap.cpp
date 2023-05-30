class MyHashMap {
    typedef pair<int, int> Node;
    vector<list<Node>> Table;
    const int Empty = -1;
    const int NrOfBuckets = 1000;
    
    int Hash(int key)
    {
        return key % NrOfBuckets;
    }
    
    list<Node>::iterator Find(int key)
    {
        int Index = Hash(key);
        list<Node>::iterator It = Table[Index].begin();
        
        while(It != Table[Index].end())
        {
            if(It->first == key)
            {
                return It;
            }
            It++;
        }
        
        return It;
    }
    
public:
    MyHashMap()
    {
        Table.resize(NrOfBuckets);
    }
    
    void put(int key, int value)
    {
        int Index = Hash(key);
        
        remove(key);

        Table[Index].push_back({key, value});
    }
    
    int get(int key)
    {
        int Index = Hash(key);
        list<Node>::iterator It = Find(key);
        
        if(It == Table[Index].end())
        {
            return Empty;
        }
        
        return It->second;
    }
    
    void remove(int key)
    {
        int Index = Hash(key);
        
        list<Node>::iterator It = Find(key);
        if(It != Table[Index].end())
        {
            Table[Index].erase(It);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */