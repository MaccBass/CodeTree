#include <iostream>
using namespace std;

int n, k, ans=0;
int arr[1000];
int prefix[1000];

int main() {

    cin>>n>>k;
    
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    prefix[0] = arr[0];
    for (int i=1; i<n; i++){
        prefix[i] = arr[i] + prefix[i-1];
    }

    for (int i=0; i<n; i++){
        if (arr[i] == k || prefix[i] == k) {ans++; continue;}

        for (int j=0; j<i; j++){
            if (prefix[i] - prefix[j] == k){
                ans++; break;
            }

            else if (prefix[i] - prefix[j] > k) continue;
            else break;
        }
    }

    cout<<ans;

    return 0;
}