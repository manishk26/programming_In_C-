// Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.
int Solution::divide(int A, int B) {
    long long int divident=A;
    long long int divisor=B;
    int sign=(divident<0)^(divisor<0)? -1 : 1;
   unsigned long long int temp=0,quitent=0;
   divident=abs(divident);
   divisor=abs(divisor);
    for(int i=31;i>=0;i--){
        if(temp+(divisor<<i)<=divident){
            temp+=divisor<<i;
            quitent |= 1LL<<i;
        }
    }
    if(sign<0 && quitent>INT_MAX)
    return INT_MIN;
    else if(sign>0 && quitent>INT_MAX)
    return INT_MAX;
    return sign*quitent;
}
