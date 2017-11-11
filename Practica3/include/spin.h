#ifndef _SPIN_
#define _SPIN_

#include "brazo.h"
#include "object3d.h"
#include "objectperfil.h"
#include "shark.h"

using namespace std;

class Spin : public Object3d {
private:
  Shark shark;
  ObjectPerfil spinner;
  Brazo brazo1;
  Brazo brazo2;
  float giro;
  float altura;

public:
  Spin();
  void dibujar(char mode);
  void setGiro(float giror);
  void setAltura(float h);
  void anguloBrazo(float a);
  void anguloPendulo(float a);
};

#endif
