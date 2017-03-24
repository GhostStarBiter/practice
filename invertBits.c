/*
 *  the main idea is to clear requested bits in x,
 *  then take requested bits form x inverted(all other bits are 0),
 *  then perform bitwise OR operation.
 *
 * */
unsigned int invertBits(unsigned int x,
                        unsigned int p,
                        unsigned int n){
    unsigned int bitfields = sizeof(int) * 8;
    if((p > bitfields) || (p+n) > bitfields)
        return 1;
    int bitmask = ~0;   //all bits to 1
    bitmask <<= (bitfields-(p+n));//clear bits on left from (p+n) position
    int temp = (((unsigned)bitmask>>(bitfields-n))<<p);//clear bits on right from (p) position and move mask to (p)
    //in temp2 variable place x with cleared bits from (p) to (p+n)
    unsigned temp2 = (~temp)&x;
    //in temp3 variable place x's inverted bits from (p) to (p+n)
    unsigned temp3 = ((~x<<(bitfields-(p+n)) >> (bitfields-n)) << p);
    //place inverted bits back in x variable
    return (temp2|temp3);
}



/*                                version without temporary variables
*
  unsigned int invertBits(unsigned int x,
                        unsigned int p,
                        unsigned int n) {
    unsigned int bitfields = sizeof(int) * 8;
    if ((p > bitfields) || (p + n) > bitfields)
        return 1;
    int bitmask = ~0;   //all bits to 1
    return (((~(((unsigned) (bitmask <<= (bitfields - (p + n)) )>> (bitfields - n)) << p)) & x) |
            ((~x << (bitfields - (p + n)) >> (bitfields - n)) << p));
}
*/
