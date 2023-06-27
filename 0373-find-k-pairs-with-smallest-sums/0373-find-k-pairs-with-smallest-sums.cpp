class Solution {
    typedef pair<int, int> FPair;
    typedef pair<int, FPair> FNode;
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int N = static_cast<int>(nums1.size());
        int M = static_cast<int>(nums2.size());       
        
        priority_queue<FNode, vector<FNode>, greater<FNode>> MinHeap;
        
        for(int i = 0; i < N; i++)
        {
            FPair Pair = {i, 0};
            FNode Node = {nums1[i] + nums2[0], Pair};
            MinHeap.push(Node);
        }
        
        vector<vector<int>> Result;
        
        while(!MinHeap.empty() && k > 0)
        {
            FPair Pair = MinHeap.top().second;
            MinHeap.pop();
            
            int Index1 = Pair.first;
            int Index2 = Pair.second;
            
            Result.push_back({nums1[Index1], nums2[Index2]});
            
            if(Index2 < M - 1)
            {
                FPair Pair = {Index1, Index2 + 1};
                FNode Node = {nums1[Index1] + nums2[Index2 + 1], Pair};
                
                MinHeap.push(Node);
            }
            k--;
        }
        
        return Result;
    }
};