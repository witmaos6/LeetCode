class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex)
    {
        const int N = words.size();
        const int Range = N >> 1;

        for(int i = 0; i <= Range; i++)
        {
            if(words[(startIndex + i) % N] == target | words[(startIndex - i + N) % N] == target)
            {
                return i;
            }
        }
        return -1;
    }
};