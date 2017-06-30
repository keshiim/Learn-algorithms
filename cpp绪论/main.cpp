//
//  main.cpp
//  cpp绪论
//
//  Created by Jason on 2017/6/30.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <iostream>

void bubblesort1A(int A[], int n) {
    bool sorted = false;
    
    while (!sorted) {
        sorted = true;//假定已排好序
        for (int i = 1; i < n; i++) {
            if (A[i - 1] > A[i]) {
                swap(A[i - 1], A[i]);
                sorted = false;
            }
        }
        n--;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
