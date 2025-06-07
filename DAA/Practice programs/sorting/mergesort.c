#include<stdio.h>
#include<math.h>

void merge(int arr[], int l, int m , int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1] , R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m+1+j];

    //merging process
    int x=0;
    int y=0;
    int k=l;  //this is l not 1
    while(x < n1 && y < n2){
        
        if (L[x] <= R[y])
            arr[k++] = L[x++];
        else
            arr[k++] = R[y++];

    }

    while (y<n2)
        arr[k++] = R[y++]; 
        
    while (x<n1)
        arr[k++] = L[x++];
}

void merge_sort(int arr[], int l, int r){
    if (l<r){
        int m = (l + (r-l))/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr, l, m , r);
    }
    
}

int main(){

    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("raama");
    return 0;
}

