#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int st,int end){
    int idx = st-1;
    int pvt = arr[end];
    for(int j=st;j<end;j++){
     if(arr[j]<pvt){
        idx++;
        swap(arr[idx],arr[j]);
     }
    }
    swap(arr[++idx],arr[end]);
    return idx;
}

   
void quicksort(vector<int> &arr,int st,int end){
    if(st<end){
        int pi = partition(arr,st,end);
        quicksort(arr,st,pi-1);
        quicksort(arr,pi+1,end);
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}