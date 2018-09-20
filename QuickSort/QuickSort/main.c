//
//  main.c
//  QuickSort
//
//  Created by apple on 2018/9/19.
//  Copyright © 2018年 apple. All rights reserved.
//

// 流程
// 1.挑出数列中的一个基准数
// 2.将所有比基准数小的放在它前面，基准数大的放在它后面，在这个分区退出之后，该基准数处于数列的中间位置
// 3.递归地把基准值前面的子序列和基准值后的序列进行排序。


#include <stdio.h>

 #define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
/**
 快速排序
 
 @param a 待排序的数组
 @param l 数组的左边界
 @param r 数组的右边界
 */
void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int i,j,x;
        
        i = l;
        j = r;
        x = a[i];
        while (i < j) {
            while (i < j && a[j] > x) {
                j --;
            }
            if (i < j) {
                a[i++] = a[j];
            }
            while (i < j && a[i] < x) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = x;
        quick_sort(a, l, i - 1);
        quick_sort(a, i+1, r);
    }
}

int main(int argc, const char * argv[]) {

    int i;
    int a[] = {30,40,60,10,20,50};
    int ilen = LENGTH(a);
    
    printf("before sort:");
    for (i=0; i<ilen; i++)
    printf("%d ", a[i]);
    printf("\n");
    
    quick_sort(a, 0, ilen-1);
    
    printf("after  sort:");
    for (i=0; i<ilen; i++)
    printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}
