#include "piramide.h"
#include <cstdio>
#include <iostream>

Piramide::Piramide(float tl = 1) {
  numpoints = 5;
  numedges = 7;

  // Añadimos los puntos(vértices)
  points.push_back(Object3d::InsertPoint3d(-tl, 0.0, tl));           // P0
  points.push_back(Object3d::InsertPoint3d(tl, 0.0, tl));            // P1
  points.push_back(Object3d::InsertPoint3d(tl, 0.0, -tl));           // P2
  points.push_back(Object3d::InsertPoint3d(-tl, 0.0, -tl));          // P3
  points.push_back(Object3d::InsertPoint3d(0.0, sqrt(3) * tl, 0.0)); // P4

  // Añadimos las caras(aristas)
  faces.push_back(Object3d::InsertFace(0, 1, 4)); // C0
  faces.push_back(Object3d::InsertFace(1, 2, 4)); // C1
  faces.push_back(Object3d::InsertFace(2, 3, 4)); // C2
  faces.push_back(Object3d::InsertFace(3, 0, 4)); // C3
  faces.push_back(Object3d::InsertFace(0, 1, 2)); // C5
  faces.push_back(Object3d::InsertFace(2, 3, 0)); // C6
}
