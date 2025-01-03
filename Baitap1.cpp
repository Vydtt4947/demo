#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Point.h"
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<Point<int>> points;
    points.reserve(20);
    for (int i = 0; i < 20; ++i) {
        points.emplace_back(std::rand() % 100, rand() % 100);
    }
    Point<int> origin(0, 0);
    sort(points.begin(), points.end(), [&origin](const Point<int>& a, const Point<int>& b) {
        return a.distance(origin) < b.distance(origin);
        });
    for (const auto& point : points) {
        point.print();
        cout << " Distance: " << point.distance(origin) << "\n";
    }
    return 0;
}