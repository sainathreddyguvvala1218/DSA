#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //LOGIC 

   for(int i=1;i<n;i++){
    int curr = arr[i];
    int prev = i-1;
    while(prev>=0 && curr<arr[prev]){
        arr[prev+1] = arr[prev];
        prev--;
    }
    arr[prev+1] = curr;
   }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}