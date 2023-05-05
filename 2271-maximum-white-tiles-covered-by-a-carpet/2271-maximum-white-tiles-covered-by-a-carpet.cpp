class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        const int N = static_cast<int>(tiles.size());
        
        int Result = 0;
        int Count = 0;
        
        int i = 0, j = 0;
        
        while(Result < carpetLen && i < N)
        {
            if(tiles[j].front() + carpetLen > tiles[i].back())
            {
                Count += GetCarpetSize(tiles[i]);
                Result = max(Result, Count);
                i++;
            }
            else
            {
                int Temp = max(0, tiles[j].front() + carpetLen - tiles[i].front());
                Result = max(Result, Count + Temp);
                Count -= GetCarpetSize(tiles[j]);
                j++;
            }
        }
        
        return Result;
    }
    
private:
    inline int GetCarpetSize(const vector<int>& tile)
    {
        return tile[1] - tile[0] + 1;
    }
};