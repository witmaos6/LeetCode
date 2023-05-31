class Bitset {
    string Bits;
    string Flips;
    int NrOfOne = 0;
    int NrOfZero = 0;
public:
    Bitset(int size)
    {
        NrOfZero = size;
        Bits.resize(size, '0');
        Flips.resize(size, '1');
    }
    
    void fix(int idx)
    {
        if(Bits[idx] == '0')
        {
            NrOfOne++;
            NrOfZero--;
        }
        Bits[idx] = '1';
        Flips[idx] = '0';
    }
    
    void unfix(int idx)
    {
        if(Bits[idx] == '1')
        {
            NrOfOne--;
            NrOfZero++;
        }
        Bits[idx] = '0';
        Flips[idx] = '1';
    }
    
    void flip()
    {
        swap(NrOfZero, NrOfOne);
        Bits.swap(Flips);
    }
    
    bool all()
    {
        if(NrOfZero == 0)
        {
            return true;
        }
        return false;
    }
    
    bool one()
    {
        if(NrOfOne >= 1)
        {
            return true;
        }
        return false;
    }
    
    int count()
    {
        return NrOfOne;
    }
    
    string toString()
    {
        return Bits;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */