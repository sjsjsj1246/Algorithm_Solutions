10828 스택

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string op;
    int num;
    stack<int> st;
    while(cin >> op) {
        if(op == "push") {
            cin >> num;
            st.push(num);
        } else if (op == "pop") {
            if(st.empty()) cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        } else if (op == "size") {
            cout << st.size() << "\n";
        } else if (op == "empty") {
            cout << (st.empty() ? 1 : 0) << "\n";
        } else if (op == "top") {
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }
}

```

9012 괄호

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;
        int cnt = 0;
        for(char x: s) {
            if(x == '(') cnt++;
            else {
                if(cnt < 1) {
                    cnt = -1;
                    break;
                } else {
                    cnt--;
                }
            }
        }
        cout << (cnt == 0 ? "YES\n" : "NO\n");
    }
}
```

18258 큐

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    string op;
    int num;
    queue<int> q;
    while(cin >> op) {
        if(op == "push") {
            cin >> num;
            q.push(num);
        } else if (op == "pop") {
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << "\n";
        } else if (op == "back") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        } else if (op == "front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
    }
}
```

1158 요세푸스 문제
linked list

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for(int i = 0; i<n; i++) arr.push_back(i+1);

    int cnt = 0;
    vector<int> ans;
    while (!arr.empty()) {
        cnt += (k - 1);
        if(cnt >= arr.size()) cnt %= arr.size();
        ans.push_back(arr[cnt]);
        arr.erase(arr.begin() + cnt);
    }

    cout << "<";
    for(int i=0; i<ans.size(); i++) {
        if(i==0) cout << ans[i];
        else cout << ", " << ans[i];
    }
    cout << ">";
}
```

2164 카드 2
deque

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    deque<int> dq;
    for(int i=0; i<n; i++) dq.push_back(i+1);

    while(dq.size() > 1) {
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }

    cout << dq.front();
}
```

1935 후위 표기식2
stack

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> values;

double pop_stack(stack<char> &st) {
    char op = st.top();
    st.pop();

    double ret;
    switch (op) {
        case '/':{
            double right = pop_stack(st);
            double left = pop_stack(st);
            ret = left / right;
            break;}
        case '*':{
            ret = pop_stack(st) * pop_stack(st);
            break;}
        case '+':{
            ret = pop_stack(st) + pop_stack(st);
            break;}
        case '-':{
            double right = pop_stack(st);
            double left = pop_stack(st);
            ret = left - right;
            break;}
        default:
            ret = values[op - 'A'];
            break;
    }

    return ret;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string s;
    stack<char> st;
    cin >> s;
    for(auto x: s) st.push(x);

    values = vector<int>(n, 0);
    for(int i=0; i<n; i++) cin >> values[i];

    cout << fixed;
    cout.precision(2);
    cout << pop_stack(st);
}
```

1966 프린터 큐
queue

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000009
using namespace std;

struct Print {
    int index;
    int p;
};

int main() {
    FAST;

    CASES(t) {
        queue<Print> q;
        vector<int> arr;
        int n, m;
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
            q.push({i, temp});
        }

        sort(arr.begin(), arr.end(), [](int a, int b) -> bool {return a > b;});
        int cnt = 0;
        while (true) {
            if(q.front().p == arr[cnt]) {
                cnt++;
                if(q.front().index == m) {
                    cout << cnt << "\n";
                    break;
                }
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }
    }
}
```

2346 풍선 터뜨리기
deque

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    int n;
    cin >> n;

    deque<pair<int,int>> dq;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        dq.push_back({i+1, temp});
    }

    while (!dq.empty()) {
        int index = dq.front().first;
        int dif = dq.front().second ;
        if(dif > 0) dif--;
        dq.pop_front();
        cout << index << " ";

        while(dif != 0) {
            if(dif > 0) {
                dq.push_back(dq.front());
                dq.pop_front();
                dif--;
            } else {
                dq.push_front(dq.back());
                dq.pop_back();
                dif++;
            }
        }
    }
}
```

1874 스택 수열

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    stack<int> st;
    int cnt = 1;

    vector<char> op;
    for(int i=0; i<n; i++) {
        while(st.empty() || st.top() != arr[i]) {
            if(cnt > n) {
                cout << "NO";
                return 0;
            }
            st.push(cnt);
            op.push_back('+');
            cnt++;
        }
        st.pop();
        op.push_back('-');
    }

    for(auto x: op) cout << x << "\n";
}
```

10799 쇠막대기

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    string s;
    cin >> s;

    int cnt = 0, ret = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(') {
            cnt++;
        }
        else {
            cnt--;

            if(s[i-1] == '(') ret+=cnt;
            else ret++;
        }
    }
    cout << ret;
}
```

2504 괄호의 값

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(),(a).end()
#define CASES(t) int t; cin >> t; while(t--)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0, temp = 1;
    for(int i=0; i<s.length(); i++) {
        switch (s[i]) {
            case '(':
                temp *= 2;
                st.push(s[i]);
                break;
            case '[':
                temp *= 3;
                st.push(s[i]);
                break;
            case ')':
                if(st.empty() || st.top() != '(') return !(cout << 0);
                st.pop();
                if(s[i-1] == '(') ans += temp;
                temp /= 2;
                break;
            case ']':
                if(st.empty() || st.top() != '[') return !(cout << 0);
                st.pop();
                if(s[i-1] == '[') ans += temp;
                temp /= 3;
                break;
        }
    }

    cout << (st.empty() ? ans : 0);
}
```

2800 괄호 제거

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(), (a).end()
#define CASES(t) \
  int t;         \
  cin >> t;      \
  while (t--)
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define MOD 1000000009
using namespace std;

string input;
set<string> ans;
vector<pair<int, int>> pair_bracket;

void make_substring(int index, vector<bool> pick) {
  if (index == pair_bracket.size()) {
    string temp = "";
    for (int i = 0; i < input.length(); i++) {
      if (pick[i]) temp += input[i];
    }
      ans.insert(temp);
    return;
  }

  make_substring(index + 1, pick);
  pair<int, int> here = pair_bracket[index];
  pick[here.first] = pick[here.second] = false;
  make_substring(index + 1, pick);
}

int main() {
  FAST;

  cin >> input;

  stack<int> st;
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == '(') {
      st.push(i);
    } else if (input[i] == ')') {
      pair_bracket.push_back({st.top(), i});
      st.pop();
    }
  }

  make_substring(0, vector<bool>(input.length(), true));
  ans.erase(ans.begin());
  for (auto x : ans) cout << x << "\n";
}
```

2493 탑
스택에 탑의 높이와 인덱스를 넣는다.
순회하면서 자신의 높이보다 스택 꼭대기 인스턴스의 높이가 작으면 스택에 빼주었다.
그 후 자신을 스택에 넣는다.
이러면 스택에는 가장 최근에 높았던 탑의 높이가 저장된다.

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(), (a).end()
#define CASES(t) \
  int t;         \
  cin >> t;      \
  while (t--)
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    int n;
    cin >> n;

    stack<pair<int, int>> st;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;

        while(!st.empty() && st.top().first < num) st.pop();

        if(st.empty()) ans.push_back(0);
        else ans.push_back(st.top().second);
        st.push({num, i + 1});
    }

    for(auto x: ans) cout << x << " ";
}
```

22942 데이터 체커
좌표를 기준으로 원의 끝점을 정렬하고
원을 구분지어 스택에 넣어야 한다.

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(), (a).end()
#define CASES(t) \
  int t;         \
  cin >> t;      \
  while (t--)
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        arr.push_back({a-b, -(i+1)});
        arr.push_back({a+b, i+1});
    }

    sort(arr.begin(), arr.end(), [](pair<int,int> a, pair<int, int> b) -> bool {
        return a.first < b.first;
    });

    stack<int> st;
    for(auto x: arr) {
        if(x.second < 0) {
            st.push(x.second);
        } else {
            if(st.top() != -x.second) {
                cout << "NO";
                return 0;
            } else {
                st.pop();
            }
        }
    }
    cout << "YES";
}
```

1918 후위 표기식
알파벳은 바로 출력하고 연산자는 스택에 넣는다.
연산자의 우선순위에 따라서 연산자를 출력한다.

```cpp
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ALL(a) (a).begin(), (a).end()
#define CASES(t) \
  int t;         \
  cin >> t;      \
  while (t--)
#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
#define MOD 1000000009
using namespace std;

int main() {
    FAST;

    map<char, int> cost;
    cost['('] = cost[')'] = 0;
    cost['+'] = cost['-'] = 1;
    cost['*'] = cost['/'] = 2;

    stack<char> stk;
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == '(') stk.push(c);
        else if (c == ')')
        {
            while (stk.top() != '(')
            {
                cout << stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if (c >= 'A' && c <= 'Z')
        {
            cout << c;
        }
        else
        {
            while (!stk.empty() && cost[c] <= cost[stk.top()])
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}
```
