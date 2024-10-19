#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> um;
int main() {
    
    int n; cin>>n;
    int ans=0;

    while(n){
        string tmp; cin>>tmp;
        sort(tmp.begin(), tmp.end());
        
        um[tmp]++;

        n--;
    }

    for (const auto& i: um){
        if (i.second>ans) ans=i.second;
    }

    cout<<ans;
    return 0;
}