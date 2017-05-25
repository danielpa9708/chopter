#ifndef UTILS_HPP
#define UTILS_HPP

struct Point {
  int x, y;
  Point(int x = 0, int y = 0);
  Point operator + (const Point &b) const;
};

struct Rect {
  Point position, size;
};

bool collision(const Rect &a, const Rect &b);

bool collision(const int x1, const int x2, const int y1, const int y2);

#endif
