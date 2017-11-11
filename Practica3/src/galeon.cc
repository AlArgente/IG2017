#include "galeon.h"

Galeon::Galeon() {
  _file_ply File_ply;

  // string filename = "ply/pawn.ply"; Para el shark
  string filename = "ply/galeon.ply";
  if (File_ply.open(filename)) {
    File_ply.read(points, faces);
    cout << "Se ha leído correctamente el fichero " << filename << endl;
    resize(0.1);
  } else {
    cout << "No se ha podido abrir el fichero ply " << filename << endl;
  }
}

void Galeon::resize(float n) {
  for (int i = 0; i < points.size(); ++i) {
    points[i].x = points[i].x * n;
    points[i].y = points[i].y * n;
    points[i].z = points[i].z * n;
  }
}

void Galeon::dibujar(char mode) {
  glPushMatrix();
  glRotatef(270, 1, 0, 0);
  glTranslatef(0.0, 32.0, -40.0);
  Object3d::dibujar(mode);
  glPopMatrix();
}
