#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> dna_a;
vector<string> dna_b;
unordered_set<string> mask_set;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int cnt=0;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string dna; cin>>dna;
        dna_a.push_back(dna);
    }
    for (int i=0;i<n;i++){
        string dna; cin>>dna;
        dna_b.push_back(dna);
    }

    for (int i=0; i<m-2; i++){
        for (int j=i+1; j<m-1; j++){
            for (int k=j+1; k<m; k++){
                bool chk=false;
                for (const auto& dna: dna_a){
                    string mask;
                    mask += dna[i];
                    mask += dna[j];
                    mask += dna[k];
                    mask_set.insert(mask);
                }

                for (const auto& dna: dna_b){
                    string mask;
                    mask += dna[i];
                    mask += dna[j];
                    mask += dna[k];
                    if (mask_set.find(mask) != mask_set.end()){
                        chk=true; break;
                    }
                }

                if (chk==false) ++cnt;
                mask_set.clear();
            }
        }
    }

    cout<<cnt;
    return 0;
}