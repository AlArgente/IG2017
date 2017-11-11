#ifndef _PENDULO_
#define _PENDULO_

#include "galeon.h"
#include "object3d.h"
#include "objectperfil.h"

using namespace std;

class Pendulo : public Object3d {
private:
  Galeon galeon;
  ObjectPerfil enlace;
  float angulo;

public:
  Pendulo();
  void dibujar(char mode);
  void animar(char mode, float angle);
  void setAngle(float a);
};

#endif
