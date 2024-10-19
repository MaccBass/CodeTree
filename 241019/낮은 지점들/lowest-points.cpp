#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> point;

int main() {

    int n; cin>>n;
    long long ans = 0;
    while (n){

        int x, y;
        cin>>x>>y;
        if (point.find(x) != point.end()){
            if (point[x] > y) point[x]=y;
        }
        else{
            point[x]=y;
        }

        n--;
    }

    for (const auto& i: point){
        ans += (long long)i.second;
    }


    cout<<ans;
    return 0;
}