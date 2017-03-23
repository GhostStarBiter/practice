/*
** From given 'x' from 'p' position 'n' bits are taken
** and placed on the left to 'n' rightmost bits of 'y'.
** Other bits unchanged.
*/

unsigned int setBits(unsigned int x,    
                     unsigned int p,    
                     unsigned int n,    
                     unsigned int y){   
    int bitfields = sizeof(int) * 8;
    if((2*n) > bitfields || (p < n) || (p > bitfields)){
        return 1;
    };
    x <<= (bitfields-p);
    x >>= (bitfields-n);
    x <<= n;
    int bitmask = ((~0 >> (bitfields - n)) << n);
    return (x | (y & ~bitmask));
}
