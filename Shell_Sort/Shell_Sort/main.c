//
//  main.c
//  Shell_Sort
//
//  Created by apple on 2018/9/19.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

// 对于n是个待排序的数列，取小于n的整数gap， 将待排序分组分成若干个子序列。所有距离为gap的倍数的记录放在同一个数组中，然后对各组内元素进
// 进行插入排序，这一趟排序完成之后，每一个组的元素都是有序的。然后减小gap的值。并重复执行上述的分组和排序，重复这样的操作，当gap = 1 时，整个数列就是有序的。
//

void shell_sort(int a[], int n) {
    int i , j , gap;
    // 确定步长
    for (gap = n / 2; gap > 0; gap /= 2) {
        
        // 从index = gap 开始逐项遍历
        for (i = 0; i < gap; i ++) {
            // i = gap 然后依照步长 -- 这里可以理解为找到每个分组的头部
            for (j = i + gap; j < n; j += gap) {
                /* 这里主要进行交换工作 */
                // 每组中相邻两个元素遍历
                if (a[j] < a[j - gap]) {
                    // 临时存储要替换的数据
                    int tmp = a[j];
                    // 找到对应的index
                    int k = j - gap;
                    
                    //// 把index之前的移动到后面去
                    // 注意这里要符合a[k] > tmp的条件，所以不会一直遍历到每组的最前面
                    while (k >= 0 && a[k] > tmp) {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    // 完成交换工作
                    a[k+gap] = tmp;
                }
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int i;
     int a[] = {80,30,60,40,20,10,50,70};
    int ilen = LENGTH(a);
    
     printf("before sort:");
      for (i=0; i<ilen; i++)
          printf("%d ", a[i]);
          printf("\n");
    
         shell_sort(a, ilen);
    
    
         printf("after  sort:");
         for (i=0; i<ilen; i++)
                 printf("%d ", a[i]);
         printf("\n");
    
    return 0;
}
