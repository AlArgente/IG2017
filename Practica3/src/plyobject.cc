#include "plyobject.h"

using namespace std;

PlyObject::PlyObject() {}

PlyObject::PlyObject(const string filename) {

  _file_ply File_ply;

  if (File_ply.open(filename)) {
    File_ply.read(points, faces);
    cout << "Se ha leído correctamente el fichero " << filename << endl;
  } else {
    cout << "No se ha podido abrir el fichero ply " << filename << endl;
  }
}
