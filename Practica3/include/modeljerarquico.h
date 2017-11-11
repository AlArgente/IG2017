#ifndef _MODELOJERARQUICO_
#define _MODELOJERARQUICO_

#include "base.h"
#include "brazo.h"
#include "object3d.h"
#include "spin.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

class ModeloJerarquico : public Object3d {
private:
  Brazo brazo;
  Base base;
  Spin spinner;
  float angulo_brazo;               // Ángulo de los brazos del spinner
  float angulo_limite_brazo_arriba; // Limitar giro del brazo hacia arriba
  float angulo_limite_brazo_abajo;  // Limitar giro del brazo hacia abajo
  float altura_spinner;             // Altura del spinner
  float altura_limite_spinner;      // Limitar la bajada del spinner
  float altura_maxima_spinner;      // Limitar la subida del spinner
  float angulo_pendulo;             // Ángulo del péndulo del spinner
  float angulo_minimo_pendulo;      // Limite del ángulo del péndulo (Mínimo)
  float angulo_maximo_pendulo; // Límite del ángulo del péndulo (Máximo)
  bool parado; // Para controlar si está o no parada la atracción.
  bool subir = false, bajar = true;
  bool brazo_subido = false, brazo_bajado = true;
  bool pendulo_arriba = false, pendulo_abajo = true;

public:
  ModeloJerarquico();
  void dibujar(char mode);
  void animar(char mode, float longi);
  void giroSpin(float giro);
  void subirSpin(float top);
  void bajarSpin(float bot);
  void giroBrazo(float angle);
  void subirBrazosSpin(float a);
  void bajarBrazosSpin(float a);
  void moverPenduloAlante(float a);
  void moverPenduloAtras(float a);
  void idle(float a);
  void pasaje(float a);
  void changeParado();
};

#endif
