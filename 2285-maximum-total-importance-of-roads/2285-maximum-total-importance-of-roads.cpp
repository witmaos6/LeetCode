class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        unordered_map<int, int> Freqs;
        for(vector<int>& Road : roads)
        {
            Freqs[Road[0]]++;
            Freqs[Road[1]]++;
        }
        
        priority_queue<int, vector<int>> MaxHeap;
        for(auto&[Num, Freq] : Freqs)
        {
            MaxHeap.push(Freq);
        }
        
        long long Result = 0;
        while(!MaxHeap.empty())
        {
            long long Freq = MaxHeap.top();
            MaxHeap.pop();
            
            Result += (Freq * n);
            n--;
        }
        
        return Result;
    }
};