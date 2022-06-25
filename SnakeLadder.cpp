    #include<bits/stdc++.h>

    using namespace std;

    int snakeLadder(vector < vector < int > > & ladder, vector < vector < int > > & snake) {
    unordered_map < int, int > m;
    for (vector < int > & i: ladder)
        m[i[0]] = i[1];

    for (vector < int > & i: snake)
        m[i[0]] = i[1];

    queue < int > a;
    a.push(1);
    int level = 1;
    vector < bool > vis(101, 0);
    while (!a.empty()) {
        int size = a.size();
        while (size--) {
        int x = a.front();
        a.pop();
        for (int i = 1; i < 7; i++) {
            int finalpos = x + i;
            if (m.count(x + i))
            finalpos = m[x + i];

            if (finalpos == 100)
            return level;

            if (!vis[finalpos]) {
            vis[finalpos] = 1;
            a.push(finalpos);
            }

        }
        }
        ++level;
    }
    return -1;
    }

    int main() {
    int s, l;
    cin >> l;
    vector < vector < int >> snake, ladder;

    int st, en;
    for (int i = 0; i < l; i++) {
        cin >> st >> en;
        ladder.push_back({
        st,
        en
        });
    }

    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> st >> en;
        snake.push_back({
        st,
        en
        });
    }

    cout << snakeLadder(snake, ladder);
    }