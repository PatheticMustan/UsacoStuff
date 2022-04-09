#include <bits/stdc++.h>
using namespace std;

enum Direction { up, left, down, right };

int main() {
    // r, c, n (/), m (\) 
    int r, c, n, m;
    cin >> r >> c >> n >> m;
    int grid[r][c];

    // arbitrary numbers, they're just constants
    // hitting an nSign
    const int nSign = 6, mSign = 7;

    for (int x=0; x<r; x++) {
        for (int y=0; y<c; y++) {
            grid[x][y] = 0;
        }
    }

    int ri, ci;
    for (int i=0; i<n; i++) {
        cin >> ri >> ci;
        grid[ri-1][ci-1] = nSign;
    }
    for (int i=0; i<m; i++) {
        cin >> ri >> ci;
        grid[ri-1][ci-1] = mSign;
    }
    


    // dir
    Direction d = Direction::right;
    int x = 0, y = 0;
    bool hasTouchedStartBefore = false;
    // while we're in bounds
    while ((min(max(0, x), r-1) == x) && (min(max(0, y), c-1) == y)) {
        if (x == 0 && y == 0 && d != Direction::right) {
            // escape reality, you're in a neverending loop
            break;
        }
        if (x == r-1 && y == c-1 && d == Direction::right) {
            cout << "Moo";
            return 0;
        }
        switch (grid[x][y]) {
            // n 6 (/), m 7 (\) 
            // up, left, down, right
            case nSign:
                // up --> right
                // right --> up
                // down --> left
                // left --> down
                switch (d) {
                    case Direction::up: d = Direction::right; break;
                    case Direction::right: d = Direction::up; break;
                    case Direction::down: d = Direction::left; break;
                    case Direction::left: d = Direction::down; break;
                }
                break;
            case mSign:
                // up --> left
                // left --> up
                // down --> right
                // right --> down
                switch (d) {
                    case Direction::up: d = Direction::left; break;
                    case Direction::left: d = Direction::up; break;
                    case Direction::down: d = Direction::right; break;
                    case Direction::right: d = Direction::down; break;
                }
                break;

            default:
                grid[x][y]++;
        }

        switch (d) {
            case Direction::up:
                x--; break;
            case Direction::down:
                x++; break;
            case Direction::left:
                y--; break;
            case Direction::right:
                y++; break;
        }
    }





    // dir
    d = Direction::left;
    x = r-1, y = c-1;
    // while we're in bounds
    while ((min(max(0, x), r-1) == x) && (min(max(0, y), c-1) == y)) {
        switch (grid[x][y]) {
            // n (/), m (\) 
            // up, left, down, right
            case nSign:
                // up --> right
                // right --> up
                // down --> left
                // left --> down
                switch (d) {
                    case Direction::up: d = Direction::right; break;
                    case Direction::right: d = Direction::up; break;
                    case Direction::down: d = Direction::left; break;
                    case Direction::left: d = Direction::down; break;
                }
                break;
            case mSign:
                // up --> left
                // left --> up
                // down --> right
                // right --> down
                switch (d) {
                    case Direction::up: d = Direction::left; break;
                    case Direction::left: d = Direction::up; break;
                    case Direction::down: d = Direction::right; break;
                    case Direction::right: d = Direction::down; break;
                }
                break;

            default:
                grid[x][y]++;
        }

        switch (d) {
            case Direction::up:
                x--; break;
            case Direction::down:
                x++; break;
            case Direction::left:
                y--; break;
            case Direction::right:
                y++; break;
        }
    }



    vector<string> v {};
    for (int i=0; i<r; i++) {
        for (int o=0; o<c; o++) {
            //cout << grid[i][o];
            if (grid[i][o] == 2) {
                v.push_back(to_string(i+1) + " " + to_string(o+1));
            }
        }
        //cout << endl;
    }

    if (v.size() == 0) {
        cout << "Impossible";
        return 0;
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (const auto& s : v) cout << s << endl;

    // remember to add 1 to x and y when you're finished

    return 0;
}