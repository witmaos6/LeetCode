class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int V1s = static_cast<int>(version1.size());
        int V2s = static_cast<int>(version2.size());
        
        int i = 0;
        int j = 0;
        while(i < V1s || j < V2s)
        {
            int Value1 = 0, Value2 = 0;
            
            while ((i < V1s) && (version1[i] != '.'))
            {
                Value1 = Value1 * 10 + (version1[i] - '0');
                i++;
            }
            while ((j < V2s) && (version2[j] != '.'))
            {
                Value2 = Value2 * 10 + (version2[j] - '0');
                j++;
            }
            if (Value1 < Value2)
                return -1;
            if (Value1 > Value2)
                return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};