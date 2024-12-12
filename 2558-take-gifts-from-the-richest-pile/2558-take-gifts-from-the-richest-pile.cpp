class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int, vector<int>> MaxHeap;
        for(int& Num : gifts)
        {
            MaxHeap.push(Num);
        }
        
        for(int i = 0; i < k; i++)
        {
            int MaxNum = MaxHeap.top();
            MaxHeap.pop();
            
            int SquareRoot = sqrt(MaxNum);
            MaxHeap.push(SquareRoot);
        }
        
        long long RemainGift = 0;
        while(!MaxHeap.empty())
        {
            RemainGift += MaxHeap.top();
            MaxHeap.pop();
        }
        
        return RemainGift;
    }
};