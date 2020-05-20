#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int* mergeSort(int n, int* arr){
    if(n==1) return arr;
    int i=0;
    int* left = malloc(n/2*sizeof(int));
    for(i=0; i<n/2; i++) left[i] = arr[i];
    int* right = malloc((n-n/2)*sizeof(int));
    for(i=0; i<n-n/2; i++) right[i] = arr[n/2+i];
    
    left = mergeSort(n/2, left);
    right = mergeSort(n-n/2, right);
    
    int* ans = malloc(n*sizeof(int));
    int l=0, r=0;
    char sign='l';
    for(i=0; i<n; i++){
        if(l>=n/2) sign='r';
        else if(r>=n-n/2) sign='l';
        else{
            if(left[l]<=right[r]) sign='l';
            else sign='r';
            }

        if(sign=='l'){
            ans[i]=left[l];
            l+=1;
        }
        else{
            ans[i]=right[r];
            r+=1;
        }
    }
    return ans;
}

int binSearch(int n, int* arr, int x){
    int i=0;
    for(i=0;i<n;i++) printf("%d ", arr[i]); printf("\n");
    
    if(n<1){
        if(arr[0]==x) return 0;
        else return -1;
    }
    else{
        int i=0;
        if(x==arr[n/2]) return n/2;
        else if(x<arr[n/2]){
            int* new = malloc(n/2*sizeof(int));
            for(i=0; i<n/2; i++) new[i]=arr[i];
            return binSearch(n/2, new, x);
        }
        else{
            int* new = malloc((n-n/2)*sizeof(int));
            for(i=0; i<n-n/2; i++) new[i]=arr[n/2+i];
            return n/2 + binSearch(n-n/2, new, x);
        }
    }
}

int main()
{
    
    int i=0, n=10;
    int* r = malloc(n*sizeof(int));
    srand(3);
    for(i=0; i<n; i++) r[i] = rand()%10;
    for(i=0; i<n; i++) printf("%d ", r[i]);

    printf("\n");
    r = mergeSort(n, r);
    for(i=0; i<n; i++) printf("%d ", r[i]);

    printf("\n");
    int ans = binSearch(n,r,5);
    printf("%d", ans);
    
    return 0;
}