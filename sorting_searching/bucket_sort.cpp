#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
   
void bucketsort(vector<float> &arr,int n){
    vector<vector<float> >bucket(n);
    //INSERT TO BUCKETS
    for(float val:arr){
        int idx = val*n;
        bucket[idx].push_back(val);
    }
    // SORT BUCKETS
    for(int i=0;i<n;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    //COMBINING
    int k=0;
    for(int i=0;i<n;i++){
        for(float val:bucket[i]){
            arr[k++] = val;
        }
    }

}


int main(){
    int n;
    cin>>n;
    vector<float> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bucketsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}