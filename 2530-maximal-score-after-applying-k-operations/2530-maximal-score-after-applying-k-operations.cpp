class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>> MaxHeap;
        
        for(int Num : nums)
        {
            MaxHeap.push(Num);
        }
        
        long long Score = 0;
        while(!MaxHeap.empty() && k > 0)
        {
            int MaxNum = MaxHeap.top();
            MaxHeap.pop();
            
            Score += MaxNum;
            
            int OperationNum = (MaxNum + 2) / 3;
            MaxHeap.push(OperationNum);
            k--;
        }
        
        return Score;
    }
};