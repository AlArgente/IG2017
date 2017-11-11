#include "modeljerarquico.h"

ModeloJerarquico::ModeloJerarquico() {
  base = Base();
  spinner = Spin();
  brazo = Brazo();
  angulo_brazo = 0;
  angulo_limite_brazo_arriba = 10;
  angulo_limite_brazo_abajo = -4;
  altura_spinner = 0;
  altura_maxima_spinner = 12;
  altura_limite_spinner = -12;
  angulo_pendulo = 0;
  angulo_minimo_pendulo = -20;
  angulo_maximo_pendulo = 20;
  parado = true;
}

void ModeloJerarquico::dibujar(char mode) {
  glPushMatrix();
  glTranslatef(0.0, 36.0, 0.0);
  spinner.dibujar(mode);
  glPopMatrix();

  glPushMatrix();
  glScalef(1.3, 1.3, 1.3);
  base.dibujar('A');
  glPopMatrix();
}

void ModeloJerarquico::animar(char mode, float longi) {
  glPushMatrix();
  glTranslatef(longi, 0.0, 0.0);
  dibujar(mode);
  glPopMatrix();
}

void ModeloJerarquico::giroSpin(float giro) { spinner.setGiro(giro); }

void ModeloJerarquico::giroBrazo(float angle) {
  if (angle < angulo_limite_brazo_arriba) {
    angle++;
  }
}

void ModeloJerarquico::subirSpin(float top) {
  if (altura_spinner <= altura_maxima_spinner) {
    altura_spinner += top;
    spinner.setAltura(top);
  }
}

void ModeloJerarquico::bajarSpin(float bot) {
  if (altura_spinner >= altura_limite_spinner) {
    altura_spinner += bot;
    spinner.setAltura(bot);
  }
}

void ModeloJerarquico::subirBrazosSpin(float a) {
  if (angulo_brazo < angulo_limite_brazo_arriba) {
    angulo_brazo += a;
    spinner.anguloBrazo(a);
  }
}

void ModeloJerarquico::bajarBrazosSpin(float a) {
  if (angulo_brazo > angulo_limite_brazo_abajo) {
    angulo_brazo += a;
    spinner.anguloBrazo(a);
  }
}

void ModeloJerarquico::moverPenduloAlante(float a) {
  if (angulo_pendulo < angulo_maximo_pendulo) {
    angulo_pendulo += a;
    spinner.anguloPendulo(a);
  }
}

void ModeloJerarquico::moverPenduloAtras(float a) {
  if (angulo_pendulo > angulo_minimo_pendulo) {
    angulo_pendulo += a;
    spinner.anguloPendulo(a);
  }
}

void ModeloJerarquico::idle(float a) {
  giroSpin(-a);
  // Subimos y bajamos la atracción

  if (altura_spinner >= altura_limite_spinner && !subir) {
    bajarSpin(-a);
    if (altura_spinner == altura_limite_spinner) {
      subir = true;
      bajar = false;
    }
  } else if (altura_spinner < altura_maxima_spinner && !bajar) {
    subirSpin(a);
    if (altura_spinner == altura_maxima_spinner) {
      subir = false;
      bajar = true;
    }
  }

  if (angulo_brazo >= angulo_limite_brazo_abajo && !brazo_bajado) {
    bajarBrazosSpin(-a);
    if (angulo_brazo == angulo_limite_brazo_abajo) {
      brazo_bajado = true;
      brazo_subido = false;
    }
  } else if (angulo_brazo < angulo_limite_brazo_arriba && !brazo_subido) {
    subirBrazosSpin(a);
    if (angulo_brazo == angulo_limite_brazo_arriba) {
      brazo_subido = true;
      brazo_bajado = false;
    }
  }

  if (angulo_pendulo < angulo_maximo_pendulo && !pendulo_arriba) {
    moverPenduloAlante(a);
    if (angulo_pendulo == angulo_maximo_pendulo) {
      pendulo_arriba = true;
      pendulo_abajo = false;
    }
  } else if (angulo_pendulo > angulo_minimo_pendulo && !pendulo_abajo) {
    moverPenduloAtras(-a);
    if (angulo_pendulo == angulo_minimo_pendulo) {
      pendulo_abajo = true;
      pendulo_arriba = false;
    }
  }
}

void ModeloJerarquico::pasaje(float a) {
  if (!parado) {
    if (altura_spinner >= altura_limite_spinner) {
      while (altura_spinner > altura_limite_spinner) {
        bajarSpin(-0.0001);
      }
    }
    if (angulo_pendulo > 0) {
      while (angulo_pendulo > 0) {
        moverPenduloAtras(-0.0001);
      }
    } else {
      while (angulo_pendulo < 0) {
        moverPenduloAlante(0.0001);
      }
    }
    if (angulo_brazo > angulo_limite_brazo_abajo) {
      while (angulo_brazo > angulo_limite_brazo_abajo) {
        bajarBrazosSpin(-0.0001);
      }
    }
  }
  idle(a);
}

void ModeloJerarquico::changeParado() {
  if (parado)
    parado = false;
}
