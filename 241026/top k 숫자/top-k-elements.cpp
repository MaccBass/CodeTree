#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n, k; cin>>n>>k;
    for (int i=0;i<n;i++){
        int tmp; cin>>tmp; s.insert(tmp);
    }

    auto it = s.rbegin();
    for (int i=0;i<k;i++){
        cout<<*it<<' ';
        it++;
        
    }
    return 0;
}