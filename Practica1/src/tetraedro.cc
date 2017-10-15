#include "tetraedro.h"
#include <cstdio>
#include <iostream>

Tetraedro::Tetraedro(float tl = 1) {

  numpoints = 4;
  numedges = 4;

  Point3d punto;
  Face cara;

  // Añadimos los puntos(vértices)
  points.push_back(Object3d::InsertPoint3d(0.0, 0.0, -tl)); // P0
  points.push_back(Object3d::InsertPoint3d(tl * (sin(45) / sin(90)), 0.0,
                                           tl * (sin(45) / sin(90)))); // P1
  points.push_back(Object3d::InsertPoint3d(-tl * (sin(45) / sin(90)), 0.0,
                                           tl * (sin(45) / sin(90)))); // P2
  points.push_back(Object3d::InsertPoint3d(0.0, sqrt(3) * tl, 0.0));   // P3

  // Añadimos las caras(aristas).
  faces.push_back(Object3d::InsertFace(0, 1, 2)); // C0
  faces.push_back(Object3d::InsertFace(1, 3, 2)); // C1
  faces.push_back(Object3d::InsertFace(3, 0, 2)); // C2
  faces.push_back(Object3d::InsertFace(0, 3, 1)); // C3
}

/*// P0
punto.x = 0.0;
punto.y = 0.0;
punto.z = -tl;
points.push_back(punto);
// P1
punto.x = tl * (sin(45) / sin(90));
punto.y = 0;
punto.z = tl * (sin(45) / sin(90));
points.push_back(punto);
// P2
punto.x = -tl * (sin(45) / sin(90));
punto.y = 0.0;
punto.z = tl * (sin(45) / sin(90));
points.push_back(punto);
// P3
punto.x = 0.0;
punto.y = sqrt(3) * tl;
punto.z = 0.0;
points.push_back(punto);*/

/*// C0
cara.v1 = 0;
cara.v2 = 1;
cara.v3 = 2;
faces.push_back(cara);
// C1
cara.v1 = 1;
cara.v2 = 3;
cara.v3 = 2;
faces.push_back(cara);
// C2
cara.v1 = 3;
cara.v2 = 0;
cara.v3 = 2;
faces.push_back(cara);
// C3
cara.v1 = 0;
cara.v2 = 3;
cara.v3 = 1;
faces.push_back(cara);*/
