class RandomizedSet
{
    unordered_map<int, int> IndexTable;
    vector<int> Values;
public:
    RandomizedSet()
    {
        
    }
    
    bool insert(int val)
    {
        if(IndexTable.find(val) != IndexTable.end())
        {
            return false;
        }
        
        Values.push_back(val);
        IndexTable[val] = Values.size() - 1;
        
        return true;
    }
    
    bool remove(int val)
    {
        if(IndexTable.find(val) == IndexTable.end())
        {
            return false;
        }
        
        int RemoveIndex = IndexTable[val];
        int LastValue = Values.back();
        
        IndexTable[LastValue] = RemoveIndex;
        swap(Values[RemoveIndex], Values[Values.size() - 1]);
        
        Values.pop_back();
        IndexTable.erase(val);
        return true;
    }
    
    int getRandom()
    {
        int Index = rand() % Values.size();
        return Values[Index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */