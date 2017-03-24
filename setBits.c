/*
 *                          x                        
 *          |________|********|________|________|
 *     (bitfields) (p+n)     (p)               (0)
 * 
 *                          y
 *                            (replaced)
 *          |________|________|********|________|
 *      (bitfields)         (n+n)     (n)      (0)
 * 
 */
unsigned int replaceBits(unsigned int x,
                         unsigned int p,
                         unsigned int n,
                         unsigned int y){
    int bitfields = sizeof(int) * 8;
    if((2*n) > bitfields || (p+n) > bitfields || (p > bitfields))
        return 1;
    x <<= (bitfields-(p+n));
    x >>= (bitfields-n);
    x <<= n;
    unsigned int bitmask = ~0;
    bitmask >>= (bitfields-n);
    bitmask <<=n;
    return (x | (y & ~bitmask));
}
