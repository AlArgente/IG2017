#include "spin.h"

Spin::Spin() {
  shark = Shark();
  spinner.initialice2(150);
  brazo1 = Brazo();
  brazo2 = Brazo();
  giro = 0;
  altura = 0;
}

void Spin::dibujar(char mode) {
  glPushMatrix();
  // Rotación y traslación del spinner
  glTranslatef(0.0, altura, 0.0);
  glRotatef(giro, 0.0, 1.0, 0.0);
  // Colocalción de los brazos
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  glRotatef(300.0, 0.0, 1.0, 0.0);
  brazo2.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  glRotatef(240.0, 0.0, 1.0, 0.0);
  brazo1.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  glRotatef(180.0, 0.0, 1.0, 0.0);
  brazo2.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  glRotatef(120.0, 0.0, 1.0, 0.0);
  brazo1.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  glRotatef(60.0, 0.0, 1.0, 0.0);
  brazo2.dibujar(mode);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.0, 110.0, 0.0);
  brazo1.dibujar(mode);
  glPopMatrix();
  // Colocación del tiburón
  glPushMatrix();
  glScalef(1.3, 2.0, 1.3);
  glTranslatef(6.0, 72.0, 0.0);
  glRotatef(30, 0.0, 0.0, 1.0);
  shark.dibujar(mode);
  glPopMatrix();
  // Colocación del spinner
  glPushMatrix();
  glScalef(1.3, 2.0, 1.3);
  glScalef(0.8, 1.2, 0.8);
  spinner.dibujar('A');
  glPopMatrix();

  glPopMatrix();
}

void Spin::setGiro(float giror) { giro += giror; }
void Spin::setAltura(float h) { altura += h; }
void Spin::anguloBrazo(float a) {
  brazo1.setAngulo(a);
  brazo2.setAngulo(-a);
}
void Spin::anguloPendulo(float a) {
  brazo1.anglePendulo(a);
  brazo2.anglePendulo(a);
}
