class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int Count = 0;
        int i = 0, j = 0;
        int P = static_cast<int>(players.size());
        int T = static_cast<int>(trainers.size());

        while(i < P && j < T)
        {
            if(players[i] <= trainers[j])
            {
                Count++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return Count;
    }
};