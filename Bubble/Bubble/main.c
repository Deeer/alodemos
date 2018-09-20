//
//  main.c
//  Bubble
//
//  Created by apple on 2018/9/19.
//  Copyright © 2018年 apple. All rights reserved.
//

#include <stdio.h>
// 交互数值
#define swap(a,b)    (a^=b,b^=a,a^=b)
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
void bubble_sort(int a[], int n) {
    int i,j;
    int flag;
    
    for (i = n - 1; i > 0; i--) {
        // 这里的标记意味着是否在一次循环中有位置交换，如果没有表示数据已经处于有序状态，可以提前退出了
        flag = 0;
        // 在 0 ... i 中遍历，两两比较，将最大的放在最后，
        // 这样单独的一次遍历之后，有序的数据处于最右侧
        for (j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
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
  
   bubble_sort(a, ilen);


  printf("after  sort:");
  for (i=0; i<ilen; i++)
  printf("%d ", a[i]);
  printf("\n");
    
    return 0;
}



