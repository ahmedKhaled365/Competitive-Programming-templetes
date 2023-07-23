int addJthBit(int x, int bit){
    return (1 << bit) | x;
}
int removeJthBit(int x, int bit){
    return ~(1 << bit) & x;
}
bool checkBit(int x, int bit){
    return (1 << bit) & x;
}
int toggleBit(int x, int bit){
    return x ^ (1 << bit);
}
ll allBitsOne(int numberOfBits){
    return (1ll << numberOfBits) - 1;
}
bool checkPowerOfTwo(int x){
    return !(x & (x - 1));
}
