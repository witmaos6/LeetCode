class TopVotedCandidate {
    typedef pair<int, int> Vote;
    vector<Vote> Memo;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
    {
        size_t N = persons.size();
        Memo.resize(N);
        vector<int> Candidate(N);
        int MaxVote = 0;
        int CurrentTop = 0;
        
        for(size_t i = 0; i < N; i++)
        {
            Candidate[persons[i]]++;
            
            if(Candidate[persons[i]] >= MaxVote)
            {
                MaxVote = Candidate[persons[i]];
                CurrentTop = persons[i];
            }
                        
            Memo[i] = {times[i], CurrentTop};
        }
    }
    
    int q(int t)
    {
        int Index = LowerBound(t);
        
        if(Memo[Index].first > t && Index > 0)
        {
            Index--;
        }
        
        return Memo[Index].second;
    }
    
    int LowerBound(int Target)
    {
        int Low = 0, High = static_cast<int>(Memo.size()) - 1;
        
        while(Low < High)
        {
            int Middle = (High + Low) / 2;
            
            if(Memo[Middle].first == Target)
            {
                return Middle;
            }
            else if(Memo[Middle].first > Target)
            {
                High = Middle - 1;
            }
            else
            {
                Low = Middle + 1;
            }
        }
        
        return Low;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */