#include "tetraedro.h"
#include <cstdio>
#include <iostream>

Tetraedro::Tetraedro() {}

Tetraedro::Tetraedro(float tl = 1) {

  numpoints = 4;
  numedges = 4;

  Point3d punto;
  Face cara;

  // Añadimos los puntos(vértices)
  points.push_back(InsertPoint3d(0.0, 0.0, -tl)); // P0
  points.push_back(InsertPoint3d(tl * (sin(45) / sin(90)), 0.0,
                                 tl * (sin(45) / sin(90)))); // P1
  points.push_back(InsertPoint3d(-tl * (sin(45) / sin(90)), 0.0,
                                 tl * (sin(45) / sin(90)))); // P2
  points.push_back(InsertPoint3d(0.0, sqrt(3) * tl, 0.0));   // P3

  // Añadimos las caras(aristas).
  faces.push_back(InsertFace(0, 1, 2)); // C0
  faces.push_back(InsertFace(1, 3, 2)); // C1
  faces.push_back(InsertFace(3, 0, 2)); // C2
  faces.push_back(InsertFace(0, 3, 1)); // C3
}
