#include "object3d.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdio>
#include <iostream>
#include <vector>

Point3d Object3d::InsertPoint3d(float _x, float _y, float _z) {
  Point3d point;
  point.x = _x;
  point.y = _y;
  point.z = _z;
  return point;
}

Face Object3d::InsertFace(int _v1, int _v2, int _v3) {
  Face face;
  face.v1 = _v1;
  face.v2 = _v2;
  face.v3 = _v3;
  return face;
}

void Object3d::draw_solid() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &(points[0]));
  glColor3f(0.0, 0.0, 1.0);
  glDrawElements(GL_TRIANGLES, 3 * faces.size(), GL_UNSIGNED_INT, &(faces[0]));
}

void Object3d::draw_lines() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &(points[0]));
  glColor3f(0.0, 0.0, 0.0);
  glDrawElements(GL_TRIANGLES, 3 * faces.size(), GL_UNSIGNED_INT, &(faces[0]));
}

void Object3d::draw_points() {
  glPointSize(10.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &(points[0]));
  glColor3f(1.0, 0.0, 0.0);
  glDrawElements(GL_TRIANGLES, 3 * faces.size(), GL_UNSIGNED_INT, &(faces[0]));
}

void Object3d::draw_chess() {
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnableClientState(GL_VERTEX_ARRAY);
  int paridad = 0;
  for (int i = 0; i < faces.size(); ++i) {
    if (paridad == 0) {
      glColor3f(1.0, 0.0, 1.0);
      paridad = 1;
    } else {
      glColor3f(0.5, 0.0, 0.5);
      paridad = 0;
    }
    glVertexPointer(3, GL_FLOAT, 0, &(points[0]));
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &(faces[i]));
  }
}

/*
void Object3d::draw_chess() {

  vector<Face> pares;
  vector<Face> impares;

  for (int i = 0; i < faces.size(); i += 2)
    pares.push_back(faces[i]);

  for (int i = 1; i < faces.size(); i += 2)
    impares.push_back(faces[i]);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3, GL_FLOAT, 0, &(points[0]));
  // glVertexPointer(3, GL_FLOAT, 0, points.data());
  glColor3f(1.0, 0.0, 1.0);
  glDrawElements(GL_TRIANGLES, 3 * pares.size(), GL_UNSIGNED_INT, &(pares[0]));
  glColor3f(0.0, 0.0, 0.0);
  glDrawElements(GL_TRIANGLES, 3 * impares.size(), GL_UNSIGNED_INT,
                 &(impares[0]));
}*/

void Object3d::draw_full() {
  draw_points();
  draw_lines();
  draw_solid();
}

void Object3d::dibujar(char mode) {
  if (toupper(mode) == 'P') {
    draw_points();
  }
  if (toupper(mode) == 'L') {
    draw_lines();
  }
  if (toupper(mode) == 'F') {
    draw_solid();
  }
  if (toupper(mode) == 'C') {
    draw_chess();
  }
  if (toupper(mode) == 'A') {
    draw_full();
  }
}
