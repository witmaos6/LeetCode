class SmallestInfiniteSet {
    set<int> SIS;
public:
    SmallestInfiniteSet()
    {
        for(int i = 1; i <= 1000; i++)
        {
            SIS.insert(i);
        }
    }
    
    int popSmallest()
    {
        int Pop = *SIS.begin();
        
        SIS.erase(SIS.begin());
        
        return Pop;
    }
    
    void addBack(int num)
    {
        SIS.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */