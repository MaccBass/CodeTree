#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> a, b, asubb, bsuba;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin>>n>>m;

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp; a.insert(tmp);
    }
    for (int i=0;i<m;i++){
        int tmp; cin>>tmp; b.insert(tmp);
    }

    asubb=a; bsuba=b;
    for (const auto& i: a){
        bsuba.erase(i);
    }
    for (const auto& i: b){
        asubb.erase(i);
    }

    for (const auto& i: bsuba){
        asubb.insert(i);
    }
    cout<<asubb.size();

    return 0;
}