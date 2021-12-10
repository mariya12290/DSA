#include <iostream>

/** How to define the problem that facilitate recursion */
/** 1. sub divided the problem, which resemblence the original problem structure 
 * 2. Some times we can convert the recusriive problem into nonrecursive
 */ 

int LinearRecursion(int *A, int n){
    if(n==1){
        return A[0];
    }else{
        return LinearRecursion(A, n-1)+A[n-1];
    }
}



int main(){

    int a[]{1,2,3,4,5};
    std::cout<<LinearRecursion(a,5)<<std::endl;
}
