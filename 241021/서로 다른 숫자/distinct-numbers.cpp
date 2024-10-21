#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> us;
int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        us.insert(tmp);
    }
    cout<<us.size();

    return 0;
}