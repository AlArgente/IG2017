#include "pendulo.h"

Pendulo::Pendulo() {
  galeon = Galeon();
  enlace.initialice2(25);
  angulo = 0;
}

void Pendulo::dibujar(char mode) {
  glPushMatrix();
  glRotatef(angulo, 1.0, 0.0, 0.0);
  // glRotatef(-30, 1.0, 0.0, 0.0);
  glPushMatrix();
  glTranslatef(0.0, -48.0, 0.0);
  glPushMatrix();
  glScalef(0.8, 0.8, 0.8);
  glScalef(0.3, 0.8, 0.3);
  enlace.dibujar('A');
  glPopMatrix();
  galeon.dibujar('S');
  glPopMatrix();
  glPopMatrix();
}

void Pendulo::animar(char mode, float angle) {
  // if(g>)
  glLoadIdentity();
  glPushMatrix();
  glRotatef(angle, 0.0, 1.0, 0.0);
  enlace.dibujar(mode);
  galeon.dibujar(mode);
  glPopMatrix();
}

void Pendulo::setAngle(float a) { angulo += a; }
