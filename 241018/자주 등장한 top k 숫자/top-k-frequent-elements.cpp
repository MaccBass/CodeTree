#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    if (a.second == b.second){
        return a.first>b.first;
    }
    return a.second>b.second;
}

unordered_map<int, int> um;
vector<pair<int, int>> v;
int main() {
    
    int n, k;
    cin>>n>>k;

    while(n){

        int tmp; cin>>tmp;
        um[tmp]++;

        n--;
    }

    v = vector<pair<int, int>>(um.begin(), um.end());
    sort(v.begin(), v.end(), compare);
    for (int i=0;i<k;i++){
        cout<<v[i].first<<' ';
    }
    
    return 0;
}