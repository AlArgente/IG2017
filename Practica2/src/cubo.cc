#include "cubo.h"
#include <cstdio>
#include <iostream>

Cubo::Cubo() {}

Cubo::Cubo(float tl = 1) {
  numpoints = 8;
  numedges = 12;

  // Añadimos los puntos(vértices).
  points.push_back(InsertPoint3d(-tl, -tl, tl));  // P0
  points.push_back(InsertPoint3d(tl, -tl, tl));   // P1
  points.push_back(InsertPoint3d(tl, tl, tl));    // P2
  points.push_back(InsertPoint3d(-tl, tl, tl));   // P3
  points.push_back(InsertPoint3d(-tl, -tl, -tl)); // P4
  points.push_back(InsertPoint3d(tl, -tl, -tl));  // P5
  points.push_back(InsertPoint3d(tl, tl, -tl));   // P6
  points.push_back(InsertPoint3d(-tl, tl, -tl));  // P7

  // Añadimos las caras(aristas) por triángulos.
  faces.push_back(InsertFace(0, 1, 2)); // C0
  faces.push_back(InsertFace(0, 2, 3)); // C1
  faces.push_back(InsertFace(1, 5, 6)); // C2
  faces.push_back(InsertFace(1, 6, 2)); // C3
  faces.push_back(InsertFace(5, 4, 7)); // C4
  faces.push_back(InsertFace(5, 7, 6)); // C5
  faces.push_back(InsertFace(4, 0, 3)); // C6
  faces.push_back(InsertFace(3, 7, 4)); // C7
  faces.push_back(InsertFace(3, 2, 6)); // C8
  faces.push_back(InsertFace(3, 6, 7)); // C9
  faces.push_back(InsertFace(4, 5, 1)); // C10
  faces.push_back(InsertFace(4, 1, 0)); // C11
}
