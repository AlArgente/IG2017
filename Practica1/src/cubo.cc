#include "cubo.h"
#include <cstdio>
#include <iostream>

Cubo::Cubo(float tl = 1) {
  numpoints = 8;
  numedges = 12;

  Point3d punto;
  Face cara;
  // Añadimos los puntos(vértices).
  points.push_back(Object3d::InsertPoint3d(-tl, -tl, tl));  // P0
  points.push_back(Object3d::InsertPoint3d(tl, -tl, tl));   // P1
  points.push_back(Object3d::InsertPoint3d(tl, tl, tl));    // P2
  points.push_back(Object3d::InsertPoint3d(-tl, tl, tl));   // P3
  points.push_back(Object3d::InsertPoint3d(-tl, -tl, -tl)); // P4
  points.push_back(Object3d::InsertPoint3d(tl, -tl, -tl));  // P5
  points.push_back(Object3d::InsertPoint3d(tl, tl, -tl));   // P6
  points.push_back(Object3d::InsertPoint3d(-tl, tl, -tl));  // P7

  // Añadimos las caras(aristas) por triángulos.
  faces.push_back(Object3d::InsertFace(0, 1, 2)); // C0
  faces.push_back(Object3d::InsertFace(0, 2, 3)); // C1
  faces.push_back(Object3d::InsertFace(1, 5, 6)); // C2
  faces.push_back(Object3d::InsertFace(1, 6, 2)); // C3
  faces.push_back(Object3d::InsertFace(5, 4, 7)); // C4
  faces.push_back(Object3d::InsertFace(5, 7, 6)); // C5
  faces.push_back(Object3d::InsertFace(4, 0, 3)); // C6
  faces.push_back(Object3d::InsertFace(3, 7, 4)); // C7
  faces.push_back(Object3d::InsertFace(3, 2, 6)); // C8
  faces.push_back(Object3d::InsertFace(3, 6, 7)); // C9
  faces.push_back(Object3d::InsertFace(4, 5, 1)); // C10
  faces.push_back(Object3d::InsertFace(4, 1, 0)); // C11
}

/*// P0
punto.x = -tl;
punto.y = -tl;
punto.z = tl;
points.push_back(punto);
// P1
punto.x = tl;
punto.y = -tl;
punto.z = tl;
points.push_back(punto);
// P2
punto.x = tl;
punto.y = tl;
punto.z = tl;
points.push_back(punto);
// P3
punto.x = -tl;
punto.y = tl;
punto.z = tl;
points.push_back(punto);
// P4
punto.x = -tl;
punto.y = -tl;
punto.z = -tl;
points.push_back(punto);
// P5
punto.x = tl;
punto.y = -tl;
punto.z = -tl;
points.push_back(punto);
// P6
punto.x = tl;
punto.y = tl;
punto.z = -tl;
points.push_back(punto);
// P7
punto.x = -tl;
punto.y = tl;
punto.z = -tl;
points.push_back(punto);
*/
/*// C0
cara.v1 = 0;
cara.v2 = 1;
cara.v3 = 2;
faces.push_back(cara);
// C1
cara.v1 = 0;
cara.v2 = 2;
cara.v3 = 3;
faces.push_back(cara);
// C2
cara.v1 = 1;
cara.v2 = 5;
cara.v3 = 6;
faces.push_back(cara);
// C3
cara.v1 = 1;
cara.v2 = 6;
cara.v3 = 2;
faces.push_back(cara);
// C4
cara.v1 = 5;
cara.v2 = 4;
cara.v3 = 7;
faces.push_back(cara);
// C5
cara.v1 = 5;
cara.v2 = 7;
cara.v3 = 6;
faces.push_back(cara);
// C6
cara.v1 = 4;
cara.v2 = 0;
cara.v3 = 3;
faces.push_back(cara);
// C7
cara.v1 = 3;
cara.v2 = 7;
cara.v3 = 4;
faces.push_back(cara);
// C8
cara.v1 = 3;
cara.v2 = 2;
cara.v3 = 6;
faces.push_back(cara);
// C9
cara.v1 = 3;
cara.v2 = 6;
cara.v3 = 7;
faces.push_back(cara);
// C10
cara.v1 = 4;
cara.v2 = 5;
cara.v3 = 1;
faces.push_back(cara);
// C11
cara.v1 = 4;
cara.v2 = 1;
cara.v3 = 0;
faces.push_back(cara);*/
