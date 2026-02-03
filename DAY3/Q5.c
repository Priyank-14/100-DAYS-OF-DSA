/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.
Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)
Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"
Example:
Input:
5
10 20 30 40 50
30
Output:
Found at index 2
Comparisons = 3
Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include<stdio.h>
int main(){
    int n,key,count=0;
    int index=-1;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search in the array:");
    scanf("%d",&key);
     int res=0;
    for(int i=0;i<n;i++){
        count+=1;
        if(arr[i]==key){
            index=i;
            res=1;
            break;
        }
    }
    
if(res==1){
    printf("Element found at index:%d\n",index);
    printf("Number of comparisions:%d",count);
}
else{
    printf("Element not found!\n");
}
return 0;
}