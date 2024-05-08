class Solution {
    array<string, 3> RankIn = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    using Rank = pair<int, int>;
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        const int N = static_cast<int>(score.size());
        priority_queue<Rank, vector<Rank>> MaxHeap;
        
        for(int i = 0; i < N; i++)
        {
            MaxHeap.push({score[i], i});
        }
        
        vector<string> Result(N);
        
        for(const string& In : RankIn)
        {
            if(!MaxHeap.empty())
            {
                auto [Score, Index] = MaxHeap.top();
                MaxHeap.pop();
                
                Result[Index] = In;
            }
            else
            {
                break;
            }
        }
        
        for(int i = 4; i <= N; i++)
        {
            auto[Score, Index] = MaxHeap.top();
            MaxHeap.pop();
            
            Result[Index] = to_string(i);
        }
        
        return Result;
    }
};