#ifndef Q_UTIL_H
#define Q_UTIL_H

#include<string.h>

struct Point
{
  double x;
  double y;
  int number;

Point() {}
  
Point(double X, double Y): x(X), y(Y) {}
  
};

struct Node
{
  Point centre;
  double halfwidth;

 Node(double X, double Y, double hw): centre(X, Y), halfwidth(hw) {}
  
};

struct Cell
{
  Point a;
  Point b;
  Point c;
  Point d;

Cell(double ul_x, double ul_y,
     double ll_x, double ll_y,
     double lr_x, double lr_y,
     double ur_x, double ur_y): a(ul_x, ul_y), b(ll_x, ll_y), c(lr_x, lr_y), d(ur_x, ur_y) {}
};

struct Line
{
  std::string name;
};

struct Sides
{
  Line* left;
  Line* right;
  Line* top;
  Line* bottom;
  std::string label;
};

struct Connect
{
  int a;
  int b;
  int c;
};

#endif
