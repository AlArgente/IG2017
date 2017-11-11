#ifndef _BASE_
#define _BASE_

#include "object3d.h"
#include "objectperfil.h"

using namespace std;

class Base : public Object3d {
private:
  ObjectPerfil base1;
  ObjectPerfil base2;

public:
  Base();
  void dibujar(char mode);
};

#endif
