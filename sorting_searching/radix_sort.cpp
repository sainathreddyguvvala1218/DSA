#include<iostream>
#include<vector>
using namespace std;
   
void countsort(vector<int> &arr,int n,int pos){

    vector<int> freq(10,0);
    for(int i=0;i<n;i++){
        freq[(arr[i]/pos)%10]++;
    }

    for(int i=0;i<9;i++){
        freq[i+1] += freq[i];
    }

    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        freq[(arr[i]/pos)%10]--;
        ans[freq[(arr[i]/pos)%10]] = arr[i];
    }
    
    for(int i=0;i<n;i++){
        arr[i] = ans[i];
    }
}

void radixsort(vector<int> &arr,int n){
    int max = arr[0];
    for(int val: arr){
        if(val>max) max = val; 
    }

    for(int pos=1;max/pos > 0;pos*=10){
        countsort(arr,n,pos);
    }
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radixsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}