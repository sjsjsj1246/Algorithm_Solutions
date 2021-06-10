---
layout: post
type: algorithms
title: "백준 5525번: IOIOI"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/5525"
tag: ["Algorithms", "DP", "String"]
comments: true
---

이 문제의 핵심은 중복되는 연산이 매우 많다는 것이다.

IOIOIOI에서 IOI를 찾는다고 하자.
이중 반복문으로 문자열을 한칸한칸 비교하면서 이 문제를 풀려고 하면 n의 크기가 최대 1000000이므로 O(n^2)에 의해 시간초과가 나게 된다.
따라서 이 문제는 어떻게든 O(n)으로 풀 생각을 해봐야 한다. 반복문을 한번만 돌아서 풀겠다는 뜻이다.

P(n)을 잘 보자. 이 문자열은 구조가 반복적이다. 따라서 이중 반복문을 썼을때 값들끼리 비교되는 것을 보면 이미 비교했던 값을 계속 비교하고 있음을 알 수 있다.

따라서 핵심은 이미 비교한 것들을 잘 저장해뒀다가 계속 써먹으면 된다. 개념은 DP와 비슷하다.(메모이제이션)

또한 찾고자 하는 값이 길이 2를 주기로 반복되므로 탐색할 때도 2씩 이동하면 된다.

```C++
#include <iostream>
using namespace std;

int main()
{
  int n, length;
  string s;
  cin >> n >> length >> s;

  int result = 0;
  for(int i=0;i<s.length(); i++) {
    int o = 0; //메모이제이션 할 값, O가 나타나는 개수를 저장해둔다

    while (s[i] == 'I' && s[i+1] == 'O') {
      // I와 O가 교차로 나타나는지 체크, 나타난다면 비교 시작
      if(i + 2 >= s.length()) break;

      o++;
      // O의 개수를 메모해준다.
      if(s[i+2] == 'I' && o == n) {
        // 문자열의 끝이 I라면 이 문자열은 P(n)임, 이때 o의 개수가 a일때 이 문자열은 P(a)이다
          result++;
          o--;
          // 찾고자 하는 문자열을 찾았을 경우 o의 개수를 줄여주는데 이것은 문자열의 머리부분을 두칸 날리는 과정이라고 보면 된다.
      }
      i += 2;
      // 2칸씩 탐색하는 과정
    }
  }
  cout << result;
}

```
