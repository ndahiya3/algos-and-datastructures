/*
 * Determine whether a point lies to the left or right of a directed line segment
 */
#include <iostream>
#include <math.h>
using namespace std;

struct Point {
  Point(double _x, double _y)
  {
    x = _x; y = _y;
  }
  double x;
  double y;
  Point subtract(const Point &right)
  {
    return Point(x - right.x, y - right.y);
  }
};

double cross_product(Point a, Point b)
{
  return a.x * b.y - b.x * a.y;
}

int direction(Point a, Point b, Point p)
{
  b = b.subtract(a);
  p = p.subtract(a);
  double cross = cross_product(b, p);
  if (cross > 0)
    return 1;
  else if (cross < 0)
    return -1;
  else
    return 0;
}

int main()
{
  Point a = { -30, 10 };
  Point b = { 29, -15 };
  Point p = { 15, 28 };

  int dir = direction(a, b, p);
  string result;

  if (dir > 0)
    result = "Left";
  else if (dir < 0)
    result = "Right";
  else
    result = "On the line";
  cout << "Expected output: Left" << endl;
  cout << "Program output:  " << result << endl;

  return 0;
}
