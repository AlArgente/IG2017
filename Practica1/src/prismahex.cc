#include "prismahex.h"
#include <cstdio>
#include <iostream>

PrismaHex::PrismaHex(float tl = 1) {
  numpoints = 6;
  numedges = 7;

  // Añadimos los puntos(vértices)
  points.push_back(Object3d::InsertPoint3d(2 * tl, 0.0, 0.0));        // P0
  points.push_back(Object3d::InsertPoint3d(tl, 0.0, sqrt(3) * tl));   // P1
  points.push_back(Object3d::InsertPoint3d(-tl, 0.0, sqrt(3) * tl));  // P2
  points.push_back(Object3d::InsertPoint3d(-2 * tl, 0.0, 0.0));       // P3
  points.push_back(Object3d::InsertPoint3d(-tl, 0.0, sqrt(3) * -tl)); // P4
  points.push_back(Object3d::InsertPoint3d(tl, 0.0, sqrt(3) * -tl));  // P5
  points.push_back(Object3d::InsertPoint3d(0.0, 0.0, 0.0));           // P6

  points.push_back(Object3d::InsertPoint3d(2 * tl, 5 * tl, 0.0));        // P7
  points.push_back(Object3d::InsertPoint3d(tl, 5 * tl, sqrt(3) * tl));   // P8
  points.push_back(Object3d::InsertPoint3d(-tl, 5 * tl, sqrt(3) * tl));  // P9
  points.push_back(Object3d::InsertPoint3d(-2 * tl, 5 * tl, 0.0));       // P10
  points.push_back(Object3d::InsertPoint3d(-tl, 5 * tl, sqrt(3) * -tl)); // P11
  points.push_back(Object3d::InsertPoint3d(tl, 5 * tl, sqrt(3) * -tl));  // P12
  points.push_back(Object3d::InsertPoint3d(0.0, 5 * tl, 0.0));           // P13

  // Añadimos las caras(aristas)
  faces.push_back(Object3d::InsertFace(0, 1, 6)); // C0
  faces.push_back(Object3d::InsertFace(1, 2, 6)); // C1
  faces.push_back(Object3d::InsertFace(2, 3, 6)); // C2
  faces.push_back(Object3d::InsertFace(3, 4, 6)); // C3
  faces.push_back(Object3d::InsertFace(4, 5, 6)); // C4
  faces.push_back(Object3d::InsertFace(5, 0, 6)); // C5

  faces.push_back(Object3d::InsertFace(7, 8, 13));   // C6
  faces.push_back(Object3d::InsertFace(8, 9, 13));   // C7
  faces.push_back(Object3d::InsertFace(9, 10, 13));  // C8
  faces.push_back(Object3d::InsertFace(10, 11, 13)); // C9
  faces.push_back(Object3d::InsertFace(11, 12, 13)); // C10
  faces.push_back(Object3d::InsertFace(12, 7, 13));  // C11

  faces.push_back(Object3d::InsertFace(0, 1, 8));   // C10
  faces.push_back(Object3d::InsertFace(8, 7, 0));   // C11
  faces.push_back(Object3d::InsertFace(1, 2, 9));   // C12
  faces.push_back(Object3d::InsertFace(9, 8, 1));   // C13
  faces.push_back(Object3d::InsertFace(2, 3, 10));  // C14
  faces.push_back(Object3d::InsertFace(10, 9, 2));  // C15
  faces.push_back(Object3d::InsertFace(3, 4, 11));  // C16
  faces.push_back(Object3d::InsertFace(11, 10, 3)); // C17
  faces.push_back(Object3d::InsertFace(4, 5, 12));  // C17
  faces.push_back(Object3d::InsertFace(12, 11, 4)); // C18
  faces.push_back(Object3d::InsertFace(5, 0, 7));   // C19
  faces.push_back(Object3d::InsertFace(7, 12, 5));  // C20
}
