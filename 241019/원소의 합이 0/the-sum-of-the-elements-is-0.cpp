#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> a;
vector<int> c;
unordered_map<int, int> ab;
unordered_map<int, int> cd;

int main() {
    
    int n; int cnt=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        a.push_back(tmp);
    }

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        for (int j=0;j<n;j++){
            ab[tmp+a[j]]++;
        }
    }

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        c.push_back(tmp);
    }

    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        for (int j=0;j<n;j++){
            cd[tmp+c[j]]++;
        }
    }

    for (const auto& i: ab){
        int target = 0 - i.first;
        cnt += i.second * cd[target];
    }

    cout<<cnt;
    return 0;
}