class Solution {
    typedef pair<int, int> Score;
public:
    long long maxScore(vector<int>& IntToAdd, vector<int>& Multiples, int k)
    {
        int N = static_cast<int>(IntToAdd.size());
        vector<Score> Scores(N);
        
        for(int i = 0; i < N; i++)
        {
            Scores[i] = {Multiples[i], IntToAdd[i]};
        }
        sort(Scores.begin(), Scores.end(), greater<Score>());
        
        long long MaxScore = 0;
        long long CurrSum = 0;
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        
        for(auto& [Multiple, Add] : Scores)
        {
            MinHeap.push(Add);
            CurrSum += Add;
            if(MinHeap.size() > k)
            {
                CurrSum -= MinHeap.top();
                MinHeap.pop();
            }
            if(MinHeap.size() == k)
            {
                MaxScore = max(MaxScore, CurrSum * Multiple);
            }
        }

        return MaxScore;
    }
};