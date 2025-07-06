class FindSumPairs {
    unordered_map<int, int> Nums1; // Num to Freq
    unordered_map<int, int> Nums2; // Num to Freq
    unordered_map<int, int> Nums2IndexToNum;// Index to num
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        for(int& Num : nums1)
        {
            Nums1[Num]++;
        }

        for(int& Num : nums2)
        {
            Nums2[Num]++;
        }

        const int N = static_cast<int>(nums2.size());
        for(int i = 0; i < N; i++)
        {
            Nums2IndexToNum[i] = nums2[i];
        }
    }
    
    void add(int index, int val)
    {
        int CurrIndexNum = Nums2IndexToNum[index];
        Nums2IndexToNum[index] += val;

        Nums2[CurrIndexNum]--;
        Nums2[Nums2IndexToNum[index]]++;
    }
    
    int count(int tot)
    {
        int Count = 0;
        for(auto& [Num, Freq] : Nums1)
        {
            int FindNum = tot - Num;
            if(Nums2.find(FindNum) != Nums2.end())
            {
                Count += (Freq * Nums2[FindNum]);
            }
        }
        return Count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */