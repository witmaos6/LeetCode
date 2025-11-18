class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        const int N = static_cast<int>(bits.size());
        for(int i = 0; i < N; i++) 
        {
            if(i == N - 1)
                return true;

            if(bits[i] == 1)
                i++;
        }
        return false;
    }
};