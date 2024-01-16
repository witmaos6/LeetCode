class RandomizedSet
{
    unordered_set<int> Table;
public:
    RandomizedSet()
    {
        
    }
    
    bool insert(int val)
    {
        if(Table.find(val) == Table.end())
        {
            Table.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val)
    {
        if(Table.find(val) != Table.end())
        {
            Table.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom()
    {
        int RandomIndex = rand() % Table.size();
        int CheckIndex = 0;
        int RandomValue = 0;
        
        for(const int Value : Table)
        {
            if(CheckIndex == RandomIndex)
            {
                RandomValue = Value;
            }
            CheckIndex++;
        }
        return RandomValue;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */