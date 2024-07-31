class Solution {
public:
void merge(vector<int>& a,int low,int mid,int high){
    vector<int> mergedArray;
    int x=low,y=mid;
    while(x<mid and y<=high){
        if(a[x]<a[y])
        mergedArray.push_back(a[x++]);
        else mergedArray.push_back(a[y++]);
    }
    while(x<mid) mergedArray.push_back(a[x++]);
    while(y<=high) mergedArray.push_back(a[y++]);
    x=0;
    for(int i=low;i<=high;i++){
        a[i]=mergedArray[x++];
    }
}

void mergeSort(vector < int > & arr,int low,int high,int& count){
    if(low>=high) return;
    int mid = low + (high-low)/2;
    mergeSort(arr, low, mid,count);
    mergeSort(arr, mid+1, high,count);
    int i=low,j=mid+1;
    while(i<=mid and j<=high){
        long check = 2* long(arr[j]);
        if (arr[i] > check) {
        count += mid - i+1;
        j++;
        }
        else i++;
    }
    merge(arr,low,mid+1,high);
}
    int reversePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        mergeSort(nums,0,n-1,count);
        return count;
    }
};