#ifndef _BRAZO_
#define _BRAZO_

#include "object3d.h"
#include "objectperfil.h"
#include "pendulo.h"
#include <iostream>

class Brazo : public Object3d {
private:
  Pendulo pendulo;
  ObjectPerfil brazo1;
  ObjectPerfil brazo2;
  float angulo;

public:
  Brazo();
  void dibujar(char mode);
  void animar(char mode, float angle);
  void setAngulo(float angle);
  void anglePendulo(float a);
};

#endif
