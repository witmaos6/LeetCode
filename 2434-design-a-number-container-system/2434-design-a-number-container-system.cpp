class NumberContainers {
    using MinHeap = priority_queue<int, vector<int>, greater<int>>;
    unordered_map<int, MinHeap> NumToIndices;
    unordered_map<int, int> IndexToNum;
public:
    NumberContainers()
    {
        
    }
    
    void change(int index, int number)
    {
        IndexToNum[index] = number;
        NumToIndices[number].push(index);
    }
    
    int find(int number)
    {
        auto FindIt = NumToIndices.find(number);
        if(FindIt == NumToIndices.end())
        {
            return -1;
        }

        MinHeap& Heap = FindIt->second;
        while(!Heap.empty() && (IndexToNum[Heap.top()] != number))
        {
            Heap.pop();
        }
        return (Heap.empty()) ? -1 : Heap.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */