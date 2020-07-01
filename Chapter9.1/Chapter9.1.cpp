/*
    折半查找
*/

#include <stdio.h>
#include <stdlib.h>

int RecurFindPosition(int arr[], int find, int start, int end); // 二分查找
int FindPosition(int* a, int len, int find);

int main()
{
    int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    printf("递归查找结果:%d", RecurFindPosition(arr, 15, 0, 14));
    printf("\n非递归查找结果:%d", FindPosition(arr, 14, 2));
}

/*
    i项查过了，在后续递归中需要绕过把i项，否则会有死循环呀
*/
int RecurFindPosition(int arr[], int find, int start, int end) {
    int i;
    i = (end - start) / 2 + start;
    if (find == arr[i]) return i;
    if (find > arr[i]) return RecurFindPosition(arr, find, i+1, end);
    if (find < arr[i]) return RecurFindPosition(arr, find, start, i-1);
}

int FindPosition(int *a, int len, int find) {
    int i = len / 2, start = 0, end = len;
    while (start < end && a[i] != find)
    {
        if (a[i] > find) end = i - 1;
        else if (a[i] < find) start = i + 1;
        i = (end - start) / 2 + start;
    }
    return i;
}
