#include "iostream"
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "algorithm"
#include "climits"



class Point {

    public:
    int x, y, f, g, h;
    Point() : x(0), y(0), f(0), g(0), h(0) {}
    Point(int x, int y) : x(x), y(y) {
        Point();
    }
    
};

class ComparePoints {
    public:
    bool operator()(const Point& p1, const Point& p2) {
        return p1.f > p2.f;
    }
};
class AStarSearch {

    private:
    std::vector<std::vector<int>> givenMatrix;
    int rows, cols;
    Point src, dest;
    std::vector<std::vector<int>> g;
    std::vector<std::vector<int>> h;
    std::vector<std::vector<int>> f;
    std::priority_queue<Point, std::vector<Point>, ComparePoints> open, closed;

    public:
    AStarSearch(int rows, int cols, std::vector<std::vector<int>> givenMatrix) : rows(rows), cols(cols), givenMatrix(givenMatrix), src(src), dest(dest) {
        g.resize(rows, std::vector<int>(cols, INT_MAX));
        h.resize(rows, std::vector<int>(cols, INT_MAX));
        f.resize(rows, std::vector<int>(cols, INT_MAX));
    }

    int heuristic(Point p1, Point p2) { return abs(p1.x - p2.x) + abs(p1.y - p2.y); }
    bool isValid(int x, int y) { return (x >= 0 && x < rows && y >= 0 && y < cols); }
    bool isUnBlocked(int x, int y) { return (givenMatrix[x][y] == 0); }
    bool isDestination(int x, int y, Point dest) { return x == dest.x && y == dest.y; }
    void tracePath(std::vector<std::vector<Point>>& parent, Point dest) {
        int row = dest.x, col = dest.y;
        std::stack<Point> path;
        while (!(parent[row][col].x == row && parent[row][col].y == col)) {
            path.push(parent[row][col]);
            int temp_row = parent[row][col].x;
            int temp_col = parent[row][col].y;
            row = temp_row;
            col = temp_col;
        }
        path.push(parent[row][col]);
        while (!path.empty()) {
            Point p = path.top();
            path.pop();
            std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
        }
    }

    void aStarSearch(Point src, Point dest) {

            if (!isValid(src.x, src.y)) {
                std::cout << "Source is invalid" << std::endl;
                return;
            }
            if (!isValid(dest.x, dest.y)) {
                std::cout << "Destination is invalid" << std::endl;
                return;
            }
            if (!isUnBlocked(src.x, src.y) || !isUnBlocked(dest.x, dest.y)) {
                std::cout << "Source or destination is blocked" << std::endl;
                return;
            }
            if (isDestination(src.x, src.y, dest)) {
                std::cout << "We are already at the destination" << std::endl;
                return;
            }
            src.g = 0;
            src.h = heuristic(src, dest);
            src.f = src.g + src.h;
            open.push(src);
            std::vector<std::vector<bool>> closedList(rows, std::vector<bool>(cols, false));
            std::vector<std::vector<Point>> parent(rows, std::vector<Point>(cols));

            while (!open.empty()) {
                Point p = open.top();
                open.pop();
                closed.push(p);
                closedList[p.x][p.y] = true;
                if (isDestination(p.x, p.y, dest)) {
                    std::cout << "Destination found" << std::endl;
                    tracePath(parent, dest);
                    return;
                }
                int x = p.x, y = p.y;
                if (isValid(x - 1, y)) {
                    if (isDestination(x - 1, y, dest)) {
                        parent[x - 1][y] = p;
                        std::cout << "Destination found" << std::endl;
                        tracePath(parent, dest);
                        return;
                    }
                    else if (!closedList[x - 1][y] && isUnBlocked(x - 1, y)) {
                        int gNew = p.g + 1;
                        int hNew = heuristic(Point(x - 1, y), dest);
                        int fNew = gNew + hNew;
                        if (f[x - 1][y] == INT_MAX || f[x - 1][y] > fNew) {
                            open.push(Point(x - 1, y));
                            parent[x - 1][y] = p;
                            f[x - 1][y] = fNew;
                            g[x - 1][y] = gNew;
                            h[x - 1][y] = hNew;
                        }
                    }
                }

                if (isValid(x + 1, y)) {
                    if (isDestination(x + 1, y, dest)) {
                        parent[x + 1][y] = p;
                        std::cout << "Destination found" << std::endl;
                        tracePath(parent, dest);
                        return;
                    }
                    else if (!closedList[x + 1][y] && isUnBlocked(x + 1, y)) {
                        int gNew = p.g + 1;
                        int hNew = heuristic(Point(x + 1, y), dest);
                        int fNew = gNew + hNew;
                        if (f[x + 1][y] == INT_MAX || f[x + 1][y] > fNew) {
                            open.push(Point(x + 1, y));
                            parent[x + 1][y] = p;
                            f[x + 1][y] = fNew;
                            g[x + 1][y] = gNew;
                            h[x + 1][y] = hNew;
                        }
                    }
                }

                if (isValid(x, y - 1)) {
                    if (isDestination(x, y - 1, dest)) {
                        parent[x][y - 1] = p;
                        std::cout << "Destination found" << std::endl;
                        tracePath(parent, dest);
                        return;
                    }
                    else if (!closedList[x][y - 1] && isUnBlocked(x, y - 1)) {
                        int gNew = p.g + 1;
                        int hNew = heuristic(Point(x, y - 1), dest);
                        int fNew = gNew + hNew;
                        if (f[x][y - 1] == INT_MAX || f[x][y - 1] > fNew) {
                            open.push(Point(x, y - 1));
                            parent[x][y - 1] = p;
                            f[x][y - 1] = fNew;
                            g[x][y - 1] = gNew;
                            h[x][y - 1] = hNew;
                        }
                    }
                }

                if (isValid(x, y + 1)) {
                    if (isDestination(x, y + 1, dest)) {
                        parent[x][y + 1] = p;
                        std::cout << "Destination found" << std::endl;
                        tracePath(parent, dest);
                        return;
                    }
                    else if (!closedList[x][y + 1] && isUnBlocked(x, y + 1)) {
                        int gNew = p.g + 1;
                        int hNew = heuristic(Point(x, y + 1), dest);
                        int fNew = gNew + hNew;
                        if (f[x][y + 1] == INT_MAX || f[x][y + 1] > fNew) {
                            open.push(Point(x, y + 1));
                            parent[x][y + 1] = p;
                            f[x][y + 1] = fNew;
                            g[x][y + 1] = gNew;
                            h[x][y + 1] = hNew;
                        }
                    }
                }

            }

            std::cout << "No path found" << std::endl;

    }

};


int main() {


    std::vector<std::vector<int>> givenMatrix = {
        {0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0}
    };
    int rows = givenMatrix.size();
    int cols = givenMatrix[0].size();
    Point src(0, 0);
    Point dest(9, 9);
    AStarSearch* obj = new AStarSearch(rows, cols, givenMatrix);
    obj -> aStarSearch(src, dest);
    delete(obj);
    return 0;
}