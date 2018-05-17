/*
 * Find area of a simple polygon i.e. one that whose edges don't cross each other
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
};

double cross_product(Point a, Point b)
{
  return a.x * b.y - b.x * a.y;
}

double area_of_polygon(Point vertices[], int n)
{
  double sum = 0.0;

  for (int i = 0; i < n; i++)
    {
      sum += cross_product(vertices[i], vertices[(i + 1) % n]); // Modulo has higher precedence than summation
    }
  return abs(sum) / 2.0;
}

int main()
{
  Point vertices[4] = { { 0, 0 }, { 4, 0 }, { 4, 4 }, { 0, 4 } };

  cout << "Expected output: 16 " << endl;
  cout << "Program output:  " << area_of_polygon(vertices, 4) << endl;

  Point vertices1[4] = { { 1, 1 }, { 5, 1 }, { 5, 5 }, { 1, 5 } };
  cout << "Expected output: 16 " << endl;
  cout << "Program output:  " << area_of_polygon(vertices1, 4) << endl;
  return 0;
}
