#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

int manhattan_distance(const Point &p1, const Point &p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
    int m, q, k, t;
    cin >> m >> q >> k >> t;

    vector<Point> fixed_points(t), optional_points;
    
    // Read fixed points
    for (int i = 0; i < t; i++) {
        if (k == 1) {
            cin >> fixed_points[i].x;
            fixed_points[i].y = 0;
        } else {
            cin >> fixed_points[i].x >> fixed_points[i].y;
        }
    }

    // Read initial optional points
    for (int i = 0; i < m; i++) {
        Point p;
        if (k == 1) {
            cin >> p.x;
            p.y = 0;
        } else {
            cin >> p.x >> p.y;
        }
        optional_points.push_back(p);
    }

    // Process q updates
    for (int i = 0; i < q; i++) {
        Point p;
        if (k == 1) {
            cin >> p.x;
            p.y = 0;
        } else {
            cin >> p.x >> p.y;
        }
        optional_points.push_back(p);
    }

    // Combine fixed points and optional points
    vector<Point> all_points = fixed_points;
    all_points.insert(all_points.end(), optional_points.begin(), optional_points.end());

    // Sort points based on the coordinates' contributions to the distance
    // We will use the idea of sorting points based on the coordinates x and y
    // to maximize the distance between them.
    
    // Sort by x coordinate, then by y coordinate
    sort(all_points.begin(), all_points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    // To maximize the sum of distances, we take points with extreme coordinates
    // both positive and negative directions.
    vector<Point> selected_points;
    
    // Take the first m+t points with extreme coordinates
    selected_points.insert(selected_points.end(), all_points.begin(), all_points.begin() + m + t);

    // Calculate the sum of all pairwise Manhattan distances
    long long total_distance = 0;
    for (int i = 0; i < selected_points.size(); i++) {
        for (int j = i + 1; j < selected_points.size(); j++) {
            total_distance += manhattan_distance(selected_points[i], selected_points[j]);
        }
    }

    cout << total_distance << endl;

    return 0;
}
