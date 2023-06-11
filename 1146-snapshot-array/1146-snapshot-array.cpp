class SnapshotArray {
    typedef pair<int, int> SnapShot;
    
    unordered_map<int, vector<SnapShot>> Structure;
    int CurrSnap = 0;
public:
    SnapshotArray(int length)
    {
        
    }
    
    void set(int index, int val)
    {
        if(!Structure[index].empty() && Structure[index].back().first == CurrSnap)
        {
            Structure[index].back().second = val;
        }
        else
        {
            Structure[index].push_back({CurrSnap, val});
        }
    }
    
    int snap()
    {
        CurrSnap++;
        
        return CurrSnap - 1;
    }
    
    int get(int index, int snap_id)
    {
        vector<SnapShot>& Temp = Structure[index];
        SnapShot Find = {snap_id, INT_MAX};
        
        int Index = upper_bound(Temp.begin(), Temp.end(), Find) - Temp.begin();
        
        if(Index == 0)
            return 0;
        
        return Temp[Index - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */