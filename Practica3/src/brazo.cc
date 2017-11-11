#include "brazo.h"

Brazo::Brazo() {
  pendulo = Pendulo();
  brazo1.initialice2(100);
  brazo2.initialice2(100);
  angulo = 0;
}

void Brazo::dibujar(char mode) {
  glPushMatrix();
  glRotatef(angulo, 0.0, 0.0, 1.0);
  glPushMatrix();
  glPushMatrix();
  glTranslatef(-4.8, -4.0, 0.0);
  glRotatef(-70, 0.0, 0.0, 1.0);
  glScalef(0.4, 2.0, 0.4);
  brazo2.dibujar('A');
  glPopMatrix();
  glPushMatrix();
  glTranslatef(213.0, 0.0, 0.0);
  glPushMatrix();
  glTranslatef(4.8, -4.0, 0.0);
  glRotatef(70, 0.0, 0.0, 1.0);
  glScalef(0.4, 2.0, 0.4);
  brazo1.dibujar('A');
  glPopMatrix();
  // glRotatef(x, 0.0, 0.0, 0.0);
  pendulo.dibujar(mode);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
}

void Brazo::animar(char mode, float angle) {
  glLoadIdentity();
  glPushMatrix();
  glRotatef(angle, 0.0, 1.0, 0.0);
  // pendulo.dibujar(mode);
  dibujar(mode);
  glPopMatrix();
}

void Brazo::setAngulo(float angle) { angulo += angle; }

void Brazo::anglePendulo(float a) { pendulo.setAngle(a); }
