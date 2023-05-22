class Solution {
    typedef pair<int, int> Element;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int, int> Freq;
        
        for(int& Num : nums)
        {
            Freq[Num]++;
        }
        
        auto Compare = [](Element E1, Element E2)
        {
            return E1.second > E2.second;
        };
        priority_queue<Element, vector<Element>, bool(*)(Element, Element)> MaxHeap(Compare);
        
        for(pair<const int, int>& Num : Freq)
        {
            MaxHeap.push({Num.first, Num.second});
            if(MaxHeap.size() > k)
            {
                MaxHeap.pop();
            }
        }
        
        vector<int> Answer(k);
        
        for(int i = 0; i < k; i++)
        {
            Answer[i] = MaxHeap.top().first;
            MaxHeap.pop();
        }
        
        return Answer;
    }
};