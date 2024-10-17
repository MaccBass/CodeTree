# [자주 등장한 top k 숫자 ](https://www.codetree.ai/missions/8/problems/top-k-frequent-elements)

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
1. unordered_map은 기본적으로 순서를 따지지 않고, 해시 테이블 내에 key-value가 저장되는 방식이다. 즉, algorithm 라이브러리를 써서 sort(um.begin(), um.end()) 식으로 정렬이 불가능하다.
unordered_map의 key와 value는 pair를 이용해 저장하므로, vector<pair<T, T>>를 만들고 iterator를 이용해 할당해준 뒤 sort()를 돌리면 된다.

2. algorithm 라이브러리의 sort()는 sorting 방법을 지정해줄 수 있다. 코드 내의 compare()은 pair의 second값(value)을 기준으로 정렬, 만약 같은 경우 first값(key)을 기준으로 내림차순 정렬하게 했다.

3. const 키워드는 값을 상수로 사용하겠다는 의미이다. 즉, const pair<> a와 같이 지정한 경우 a의 값을 함수 내에서 수정할 수 없다.
이와 맞물려 const pair<>&와 같이 참조를 사용했는데, 참조를 사용했을 때 값을 함부로 변경하면 원본 값에도 영향을 줄 위험성이 있지만, const를 사용하였기에 이 문제가 해결된다. pair 객체를 복사하지도 않았기 때문에 메모리 공간 사용도 적어진다. 
