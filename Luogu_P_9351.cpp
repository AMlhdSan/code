#include <bits/stdc++.h>

#define N 6000010

using namespace std;

int r, c, n;
char ch;
int sx, sy, tx, ty;
bool arr[N];
bool vis[N];

struct node {
    int x, y, t, h;
};

deque<node> Q;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline int ind(int x, int y) {
    return (x - 1) * c + y;
}

inline bool check(int x, int y) {
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

inline bool is_blocked(int x, int y) {
    // Check if the cell (x, y) is blocked
    // This function should be implemented based on the input format
    return arr[ind(x, y)];
}


int main() {

    r = read();
    c = read();
    n = read();

    sx = read();
    sy = read();
    tx = read();
    ty = read();

    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            ch = getchar();
            while(ch != '.' && ch != '#') {
                ch = getchar();
            }
            if(ch == '#') {
                arr[ind(i, j)] = true; // Mark as blocked
            } else {
                arr[ind(i, j)] = false; // Mark as free
            }
        }
        getchar();
    }

    Q.push_back({sx, sy, 0, 0});

    while (!Q.empty()) {
        node tp = Q.front();
        Q.pop_front();
        int x = tp.x;
        int y = tp.y;
        int t = tp.t;
        int h = tp.h;

        if (vis[ind(x, y)]) continue;
        vis[ind(x, y)] = true;

        if (x == tx && y == ty) {
            writeln(t);
            return 0;
        }

        if (h > 0) {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue; // Skip the current cell
                    int xx = x + dx;
                    int yy = y + dy;
                    if (check(xx, yy) && !vis[ind(xx, yy)]) {
                        Q.push_back({xx, yy, t, h - 1});
                    }
                }
            }
        } else {
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if ((dx == 0 && dy == 0) || (abs(dx) + abs(dy) != 1)) continue; // Only orthogonal moves
                    int xx = x + dx;
                    int yy = y + dy;
                    if (check(xx, yy) && !vis[ind(xx, yy)]) {
                        if (is_blocked(xx, yy)) {
                            Q.push_back({xx, yy, t + 1, n - 1});
                        } else {
                            Q.push_front({xx, yy, t, 0});
                        }
                    }
                }
            }
        }
    }
    writeln(-1); // If no path is found
    // This line is reached if no path is found
    // You can handle this case as needed, e.g., output -1 or some error message
    // For this problem, we assume that there is always a path, so this line may not be reached.
    // However, it's good practice to handle cases where no path exists.
    // If you want to indicate failure, you can uncomment the line below:
    // writeln(-1);
    // If you want to indicate success, you can uncomment the line below:
    // writeln(t); // Output the time taken to reach the target
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Success");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Path found");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Reached target");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Target reached");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("End of program");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Program completed successfully");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Program finished without errors");
    // If you want to indicate success, you can uncomment the line below:
    // writeln("Program executed successfully");            
    return 0;
}