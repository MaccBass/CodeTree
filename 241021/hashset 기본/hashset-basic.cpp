#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unordered_set<int> us;
    int n; cin>>n;

    for (int i; i<n; ++i){
        string op; int tmp;
        cin>>op>>tmp;
        if (op == "add"){
            us.insert(tmp);
        }
        if (op == "remove"){
            us.erase(tmp);
        }
        if (op == "find"){
            if (us.find(tmp) != us.end()){
                cout<<"true"<<'\n';
            }
            else{
                cout<<"false"<<'\n';
            }
        }
    }
    return 0;
}