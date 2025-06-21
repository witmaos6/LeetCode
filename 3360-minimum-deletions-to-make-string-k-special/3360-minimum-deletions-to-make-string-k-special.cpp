class Solution {
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> Table;
        for(char& C : word)
        {
            Table[C]++;
        }

        vector<int> Freq;
        for(auto&[C, Num] : Table)
        {
            Freq.push_back(Num);
        }
        sort(Freq.begin(), Freq.end());

        int MinDelete = INT_MAX;
        const int N = static_cast<int>(Freq.size());

        for(int i = 0; i < N; i++)
        {
            int Base = Freq[i];
            int Total = 0;

            for(int j = 0; j < i; j++)
            {
                Total += Freq[j];
            }
            for(int j = i; j < N; j++)
            {
                if(Freq[j] > Base + k)
                {
                    Total += Freq[j] - (Base + k);
                }
            }

            MinDelete = min(MinDelete, Total);
        }
        return MinDelete;
    }
};