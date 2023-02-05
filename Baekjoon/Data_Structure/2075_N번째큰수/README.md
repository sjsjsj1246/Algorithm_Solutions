---
layout: post
type: algorithms
title: "백준 2075번: N번째 큰 수"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/2075"
tag: ["Algorithms", "Priority_Queue"]
comments: true
rating: gold5
---

문제 의도는 PQ로 푸는 문제인 것 같으나 일반적인 sort로도 풀 수 있는 것 같습니다.

PQ에 값을 넣다가 큐의 크기가 n보다 커지면 PQ에서 원소를 하나 빼줍니다. 그렇게 되면 n번째로 큰 원소가 PQ 상위에 남게 됩니다.

```C++
#include <iostream>
#include <vector>
#include <queue>
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    FAST;
    int n;
    cin >> n;
    priority_queue<int> pq;

    for(int i=0; i<n*n; i++) {
        int temp;
        cin >> temp;
        pq.push(-temp);
        if(pq.size() > n) {
            pq.pop();
        }
    }
    cout << -pq.top();
}
```
