#ifndef _SHARK_
#define _SHARK_

#include "file_ply_stl.h"
#include "object3d.h"

using namespace std;

class Shark : public Object3d {
public:
  Shark();
  void dibujar(char mode);
};

#endif
