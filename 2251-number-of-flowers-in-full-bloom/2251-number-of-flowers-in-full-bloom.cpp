class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people)
    {
        const int N = static_cast<int>(flowers.size());
        vector<int> Start(N);
        vector<int> End(N);
        
        for(int i = 0; i < N; i++)
        {
            Start[i] = flowers[i][0];
            End[i] = flowers[i][1];
        }
        sort(Start.begin(), Start.end());
        sort(End.begin(), End.end());
        
        const int NrOfPeoples = static_cast<int>(people.size());
        vector<int> Result(NrOfPeoples);
        
        for(int i = 0; i < NrOfPeoples; i++)
        {
            int Day = people[i];
            
            int Bloom = upper_bound(Start.begin(), Start.end(), Day) - Start.begin();
            int Falls = lower_bound(End.begin(), End.end(), Day) - End.begin();
            
            Result[i] = Bloom - Falls;
        }
        
        return Result;
    }
};