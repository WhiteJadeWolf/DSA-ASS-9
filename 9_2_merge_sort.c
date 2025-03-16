/* Given an array arr[], its starting position l and its ending position r. 
Sort the array using the merge sort algorithm.
Examples :--
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]  */

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } 
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    while(1){
        int ch;
        printf("\nEnter your choice :--\n1 - Merge-Sort an array\n2- Exit\nChoice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            {
                int n;
                printf("Enter length of array : ");
                scanf("%d",&n);
                int arr[n];
                printf("Enter an space separated array of %d numbers : ",n);
                for(int _ = 0; _ < n; _++){
                    scanf("%d",&arr[_]);
                }
                mergeSort(arr, 0, n - 1);
                printf("Sorted array : ");
                printArray(arr, n);
                break;
            }
            case 2: exit(0);
                    break;
            default: printf("INVALID INPUT - TRY AGAIN.\n");
        }
    }
    return 0;
}
