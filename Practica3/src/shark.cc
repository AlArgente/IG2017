#include "shark.h"

Shark::Shark() {
  _file_ply File_ply;

  // string filename = "ply/pawn.ply"; Para el shark
  string filename = "ply/shark.ply";
  if (File_ply.open(filename)) {
    File_ply.read(points, faces);
    cout << "Se ha leído correctamente el fichero " << filename << endl;
  } else {
    cout << "No se ha podido abrir el fichero ply " << filename << endl;
  }
}

void Shark::dibujar(char mode) {
  glPushMatrix();
  glTranslatef(3.0, 5.0, 21.0); // para el shark
  glScalef(33.0, 33.0, 33.0);   // Para el shark
  Object3d::dibujar('C');
  glPopMatrix();
}
