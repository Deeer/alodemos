//
//  main.c
//  SelecteSort
//
//  Created by apple on 2018/9/20.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) (a^=b,b^=a,a^=b)

// 思想 ： 首先在为排序的数列中h找到最大或者最小的元素，然后将其存放到数列数起始位置，接着，再从剩余的元素中查找最大或者最小的元素
// 然后放在已排列序列的末尾。以此类推

void select_sort(int a[], int n) {
    int i; // 有序区的末尾
    int j; // 无序区起始
    int min; // 无序区中的最小值位置
    
    
    for (i = 0; i< n; i++ ) {
        min = i;
        // 找出最小值index
        for (j = i+1; j<n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        // 交换

        if (min != i) {
            swap(a[i], a[min]);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = LENGTH(a);
    
    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
        printf("\n");
    
        select_sort(a, ilen);
    
         printf("after  sort:");
         for (i=0; i<ilen; i++)
                 printf("%d ", a[i]);
        printf("\n");
    return 0;
}
