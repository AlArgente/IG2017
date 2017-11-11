#include "base.h"

Base::Base() {
  base1.initialice2(150);
  base2.initialice2(150);
}

void Base::dibujar(char mode) {
  glPushMatrix();
  glTranslatef(0.0, 12.0, 0.0);
  glScalef(1.2, 0.6, 1.2);
  base2.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glScalef(3.0, 0.2, 3.0);
  base1.dibujar(mode);
  glPopMatrix();
}
