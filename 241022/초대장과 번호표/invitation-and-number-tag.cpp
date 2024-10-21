#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<unordered_set<int>> groups;
vector<bool> invited;
queue<int> invitation;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, g;
    int cnt = 0;
    cin >> n >> g;

    for (int i = 0; i <= n; i++) {
        invited.push_back(false);
    }
    for (int i = 0; i < g; i++) {
        int k; cin >> k;
            int tmp; cin >> tmp; invitation.push(tmp);
            unordered_set<int> group;
            for (int j = 0; j < k - 1; j++) {
                cin >> tmp;
                group.insert(tmp);
            }
        groups.push_back(group);
    }

    while (!invitation.empty()) {
        int num;
        num = invitation.front();
        invitation.pop();
        // 이미 초대된 사람은 무시
        if (invited[num]) continue;

        invited[num] = true;
        cnt++;
        for (auto& group : groups) {
            group.erase(num);
            if (group.size() == 1) {
                int remain = *group.begin();
                invitation.push(remain);
                group.erase(remain);
            }
        }
    }

    cout << cnt;
    return 0;
}