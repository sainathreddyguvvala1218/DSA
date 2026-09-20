#include<iostream>
#include<vector>
using namespace std;
   
void countsort(vector<int> &arr,int n){
    int max = arr[0];
    for(int val: arr){
        if(val>max) max = val; 
    }

    vector<int> freq(max+1,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<max;i++){
        freq[i+1] += freq[i];
    }

    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        freq[arr[i]]--;
        ans[freq[arr[i]]] = arr[i];
    }
    
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }

}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}