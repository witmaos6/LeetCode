class SmallestInfiniteSet {
    vector<int> SIS;
    const int Erase = -1;
    int PopValue = 0;
public:
    SmallestInfiniteSet()
    {
        SIS.resize(1001);
        SIS[0] = -1;
        
        for(int i = 1; i <= 1000; i++)
        {
            SIS[i] = i;
        }
        PopValue = 1;
    }
    
    int popSmallest()
    {
        if(SIS[PopValue] == Erase)
        {
            for(int i = PopValue; i <= 1000; i++)
            {
                if(SIS[i] != Erase)
                {
                    PopValue = SIS[i];
                    SIS[i] = Erase;
                    break;
                }
            }
        }
        else
        {
            SIS[PopValue] = Erase;
        }
        
        PopValue++;
        
        return PopValue - 1;
    }
    
    void addBack(int num)
    {
        SIS[num] = num;
        PopValue = min(PopValue, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */