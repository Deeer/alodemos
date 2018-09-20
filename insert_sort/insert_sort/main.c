//
//  main.c
//  insert_sort
//
//  Created by apple on 2018/9/19.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <stdio.h>

// 把n个待排序的元素看成是一个有序表和无序表。开始时有序表中只包含一个元素，无序表中包含n-1个元素
// 排序过程中每次从无序表中取出第一个元素，将它插入到有序表中的合适位置，使之成为一个新的有序表，重复n - 1次即可完成排序
// 时间复杂度 O(n^2)
// 稳定
 // 数组长度
 #define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

void insert_sort(int a[], int n) {
    int i,j,k;
    
    // 从 1 到 n 正向循环
    for (i = 1; i < n; i ++) {
        
        // 寻找合适的位置 -找到后，记录这个j
        
        for (j = i - 1; j >= 0; j --) {
            if (a[j] < a[i]) {
                break;
            }
        }
        
        // 在 i - 1 到 j
        //
        if ( j != i - 1 ) {
            int temp = a[i];
            for (k = i - 1; k > j; k --) {
                a[k+1] = a[k];
            }
            a[k+1] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = LENGTH(a);
    
    printf("before sort:");
    for (i=0; i<ilen; i++)
             printf("%d ", a[i]);
         printf("\n");
    
         insert_sort(a, ilen);
    
         printf("after  sort:");
         for (i=0; i<ilen; i++)
                 printf("%d ", a[i]);
         printf("\n");
    
    return 0;
}
