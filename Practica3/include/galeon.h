#ifndef _GALEON_
#define _GALEON_

#include "file_ply_stl.h"
#include "object3d.h"
#include <iostream>

class Galeon : public Object3d {
public:
  Galeon();
  void resize(float n = 0.4);
  void dibujar(char mode);
};

#endif
