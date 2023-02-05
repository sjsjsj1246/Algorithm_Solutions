---
layout: post
type: algorithms
title: "백준 2800번: 괄호제거"
date: 2021-06-10
excerpt: "https://www.acmicpc.net/problem/2800"
tag: ["Algorithms", "Stack"]
comments: true
rating: gold5
---

괄호의 쌍을 찾는 문제는 대부분 스택으로 풉니다. 다만 이 문제는 괄호를 제거할 수 있는 만큼 제거하고 출력해야 합니다.

괄호의 쌍을 배열에 넣어서 저장해놓고 만들 수 있는 모든 부분 집합(Power set)을 탐색하며 결과를 저장합니다.

탐색은 dfs 방식으로 원소를 선택하는 경우와 선택하지 않는 경우로 탐색합니다.

결과를 정렬하여 출력합니다.

```C++
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

string s;
vector<string> result;
vector<pair<int, int>> arr;

void search(int index, vector<bool> visit) {
    if(index == arr.size()) {
        string temp = "";
        for(int i=0; i<s.length(); i++) {
            if(visit[i]) temp += s[i];
        }
        result.push_back(temp);
        return;
    }

    search(index+1, visit);
    pair<int, int> here = arr[index];
    visit[here.first] = visit[here.second] = false;
    search(index+1, visit);
}

int main() {
    FAST;
    cin >> s;

    stack<pair<char, int>> st;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            st.push({s[i], i});
        }
        if(s[i] == ')') {
            arr.push_back({st.top().second, i});
            st.pop();
        }
    }



    search(0, vector<bool>(s.length(), true));

    sort(result.begin(), result.end());
    for(int i=1; i<result.size(); i++) {
        if(result[i] == result[i-1]) continue;
        cout << result[i] << "\n";
    }
}
```
