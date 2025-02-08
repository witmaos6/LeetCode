class NumberContainers {
    unordered_map<int, set<int>> NumToIndices;
    unordered_map<int, int> IndexToNum;
public:
    NumberContainers()
    {
        
    }
    
    void change(int index, int number)
    {
        if(IndexToNum.count(index))
        {
            const int PrevNum = IndexToNum[index];
            NumToIndices[PrevNum].erase(index);
        }
        IndexToNum[index] = number;
        NumToIndices[number].insert(index);
    }
    
    int find(int number)
    {
        if(NumToIndices.count(number))
        {
            if(NumToIndices[number].empty())
            {
                return -1;
            }
            return *NumToIndices[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */