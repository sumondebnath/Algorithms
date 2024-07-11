#include<bits/stdc++.h>
using namespace std;

void merge_two_sorted_array(int arr[], int left, int mid, int right){
    int leftSize = (mid-left)+1;
    int rightSize = right-mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    int temp = 0;
    for(int i=left; i<=mid; i++){
        leftArr[temp] = arr[i];
        temp++; 
    }
    temp = 0;
    for(int i=mid+1; i<=right; i++){
        rightArr[temp] = arr[i];
        temp++;
    }

    int l=0, r=0;
    int current_index = left;

    while(l<leftSize and r<rightSize){
        if(leftArr[l] < rightArr[r]){
            arr[current_index] = leftArr[l];
            l++;
        }
        else{
            arr[current_index] = rightArr[r];
            r++;
        }
        current_index++;
    }

    while(l<leftSize){
        arr[current_index] = leftArr[l];
        l++;
        current_index++;
    }

    while(r<rightSize){
        arr[current_index] = rightArr[r];
        r++;
        current_index++;
    }

}

void merge_sort(int arr[], int left, int right){

    if(left < right){
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);

        merge_two_sorted_array(arr, left, mid, right);
    }
}

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}