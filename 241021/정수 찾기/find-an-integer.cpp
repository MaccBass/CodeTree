#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_set<int> us;
    int n, m;
    
    cin>>n;
    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        us.insert(tmp);
    }

    cin>>m;
    for (int i=0;i<m;i++){
        int tmp; cin>>tmp;
        if (us.find(tmp)!=us.end()){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}