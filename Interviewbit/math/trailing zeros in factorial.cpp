int Solution::trailingZeroes(int A) {
    int temp = A;
    int zeros = 0;
    while(floor(temp) != 0){
        zeros += temp/5;
        temp = temp/5;
    }
    return zeros;
}