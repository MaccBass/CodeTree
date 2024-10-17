# [세 수의 합 ](https://www.codetree.ai/missions/8/problems/sum-of-three-num)

|유형|문제 경험치|난이도|
|---|---|---|
|[Intermediate Mid / 중급 자료구조 / HashMap](https://www.codetree.ai/missions?missionId=8)|60xp|![보통][medium]|








[b5]: https://img.shields.io/badge/Bronze_5-%235D3E31.svg
[b4]: https://img.shields.io/badge/Bronze_4-%235D3E31.svg
[b3]: https://img.shields.io/badge/Bronze_3-%235D3E31.svg
[b2]: https://img.shields.io/badge/Bronze_2-%235D3E31.svg
[b1]: https://img.shields.io/badge/Bronze_1-%235D3E31.svg
[s5]: https://img.shields.io/badge/Silver_5-%23394960.svg
[s4]: https://img.shields.io/badge/Silver_4-%23394960.svg
[s3]: https://img.shields.io/badge/Silver_3-%23394960.svg
[s2]: https://img.shields.io/badge/Silver_2-%23394960.svg
[s1]: https://img.shields.io/badge/Silver_1-%23394960.svg
[g5]: https://img.shields.io/badge/Gold_5-%23FFC433.svg
[g4]: https://img.shields.io/badge/Gold_4-%23FFC433.svg
[g3]: https://img.shields.io/badge/Gold_3-%23FFC433.svg
[g2]: https://img.shields.io/badge/Gold_2-%23FFC433.svg
[g1]: https://img.shields.io/badge/Gold_1-%23FFC433.svg
[p5]: https://img.shields.io/badge/Platinum_5-%2376DDD8.svg
[p4]: https://img.shields.io/badge/Platinum_4-%2376DDD8.svg
[p3]: https://img.shields.io/badge/Platinum_3-%2376DDD8.svg
[p2]: https://img.shields.io/badge/Platinum_2-%2376DDD8.svg
[p1]: https://img.shields.io/badge/Platinum_1-%2376DDD8.svg
[passed]: https://img.shields.io/badge/Passed-%23009D27.svg
[failed]: https://img.shields.io/badge/Failed-%23D24D57.svg
[easy]: https://img.shields.io/badge/쉬움-%235cb85c.svg?for-the-badge
[medium]: https://img.shields.io/badge/보통-%23FFC433.svg?for-the-badge
[hard]: https://img.shields.io/badge/어려움-%23D24D57.svg?for-the-badge

# 몰랐던 / 배운 내용
unordered_map에 관한 지식보단 수학적 직관을 요구하는 문제였다.
내가 생각한 방식은 일단 숫자 배열을 받은 뒤, 뒤에서 3번째 숫자와 k값의 차이를 um에 저장하고 나머지 조합을 순회하며 그 합이 map에 있으면 cnt를 추가하는 방식이었다. 중복을 없애기 위해 조합에는 반드시 현재 체크중인 숫자의 바로 다음 순번 숫자를 포함하게 했다.

예시를 들면, n-3번 인덱스부터 확인한다 했을 때, 조합에는 반드시 n-2번이 들어가야 한다. 그럼 순서쌍은 (n-2, n-1) 하나만 나온다.
그 다음으로 n-4번 인덱스를 확인할 땐, 조합에 반드시 n-3번이 들어가야 한다. 순서쌍은 (n-3, n-2), (n-3, n-1)과 같이 된다. 숫자 3개 중 2개를 선택하므로 가능한 조합의 수는 3C2 = 3개이지만, 반드시 n-3을 포함하기 때문에 먼저 조사한 (n-2, n-1)은 중복되어 갱신하지 않는다.

단, 풀이에서 한 방식은 내 풀이와 많이 달랐다.
일단 um에 기록하는 숫자는 각 숫자가 몇 번 나왔는지를 기록했다. 여기서 메모리 사용량이 갈린다.
풀이는 최대 n개의 데이터가 들어가지만, 나는 숫자 2개를 더한 값이 um에 들어가므로 최대 n^2-n/2개의 데이터가 들어갈 것이다. 그리고 2개의 숫자 쌍의 합을 구하고, 그 값과 k의 차이를 um에 넣는 방식이다. 즉, 나는 더 많은 데이터를 더 많은 횟수로 갱신하므로 당연히 효율적이지 못할 수밖에 없다.
내가 내 풀이를 생각한 이유는 um 내의 숫자가 자기 자신을 포함할 수 없는 경우를 고려해서 였다. 숫자 조합에 따라 2번 인덱스와 4번 인덱스에 같은 값이 들어가 있는 경우, (2, 4, 5)와 (4, 4, 5) 중 후자는 불가능한데 저런 케이스를 고려할 수 없었기 때문이다. 풀이에서는 숫자를 순회하며 자기 자신이 나온 횟수를 1회 빼주는 방법으로 저런 중복을 피했다. 이는 이미 확인한 인덱스의 숫자를 고려하지 않겠다는 의미와 같다.
