#ifndef _OBJECT3D_
#define _OBJECT3D_

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 200

struct Point3d {
  float x, y, z;
};

struct Face {
  int v1, v2, v3;
};

class Object3d {

protected:
  int numpoints, numedges;
  vector<Point3d> points;
  vector<Face> faces;

public:
  Object3d();
  Point3d InsertPoint3d(float _x, float _y, float _z);
  Face InsertFace(int _v1, int _v2, int _v3);
  void draw_solid();
  void draw_lines();
  void draw_points();
  void draw_chess();
  void draw_full();
  void dibujar(char mode);
  void clear();
};

#endif
