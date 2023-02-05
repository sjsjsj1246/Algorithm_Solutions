---
layout: post
type: algorithms
title: "백준 16236번: 알고리즘"
date: 2023-02-5
excerpt: "https://www.acmicpc.net/problem/16236"
tag: ["Algorithms", "BFS"]
comments: true
rating: gold3
---

BFS를 이용하여 먹을 수 있는 물고기를 찾습니다.
다만 단순히 BFS의 큐 방식을 이용하여 탐색하면 문제의 `가장 가까운 물고기` 조건을 만족할 수 없습니다.

따라서 BFS로 모든 먹을 수 있는 물고기를 저장한 다음 문제의 조건에 맞는 가까운 물고기를 반환하는 방식으로 풀었습니다.

```C++
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int board_size;
int shark_size = 2;
vector<vector<int>> board;
vector<vector<int>> visited;

struct Point {
  int x, y;
};

pair<Point, int> search_fish(Point start) {
  queue<Point> q;
  visited = vector<vector<int>>(board_size, vector<int>(board_size, -1));
  q.push(start);
  visited[start.x][start.y] = 0;
  vector<pair<Point, int>> candidate;
  while (!q.empty()) {
    Point cur = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];
      if (nx < 0 || nx >= board_size || ny < 0 || ny >= board_size) continue;
      if (visited[nx][ny] == -1) {
        int next = board[nx][ny];
        if (next > shark_size) continue;                                                                 // 물고기가 자신보다 크면 지나갈 수 없다.
        if (next != 0 && next < shark_size) candidate.push_back({{nx, ny}, visited[cur.x][cur.y] + 1});  // 먹을 수 있는 물고기를 찾았다.
        q.push({nx, ny});
        visited[nx][ny] = visited[cur.x][cur.y] + 1;
      }
    }
  }
  if (candidate.empty()) return {{-1, -1}, -1};  // 먹을 수 있는 물고기가 없다.
  sort(candidate.begin(), candidate.end(), [](pair<Point, int> a, pair<Point, int> b) -> bool {
    if (a.second == b.second) {
      if (a.first.x == b.first.x)
        return a.first.y < b.first.y;
      else
        return a.first.x < b.first.x;
    } else
      return a.second < b.second;
  });
  return candidate[0];
}

int main() {
  cin >> board_size;
  board = vector<vector<int>>(board_size, vector<int>(board_size, 0));

  Point start;
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        start = {i, j};
        board[i][j] = 0;
      }
    }
  }

  int ret = 0;
  int cnt = 0;
  while (true) {
    pair<Point, int> fish = search_fish(start);
    if (fish.second == -1) break;
    ret += fish.second;
    start = fish.first;
    cnt++;
    board[fish.first.x][fish.first.y] = 0;

    if (cnt >= shark_size) {
      cnt -= shark_size;
      shark_size++;
    }
  }

  cout << ret << endl;
}
```
