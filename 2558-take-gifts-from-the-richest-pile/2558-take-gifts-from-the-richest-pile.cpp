class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int, vector<int>> MaxHeap;
        long long RemainGift = 0;
        for(int& Num : gifts)
        {
            MaxHeap.push(Num);
            RemainGift += Num;
        }
        
        for(int i = 0; i < k; i++)
        {
            int MaxNum = MaxHeap.top();
            MaxHeap.pop();
            
            int SquareRoot = sqrt(MaxNum);
            RemainGift -= (MaxNum - SquareRoot);
            MaxHeap.push(SquareRoot);
        }
        
        return RemainGift;
    }
};