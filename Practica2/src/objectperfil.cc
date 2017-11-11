#include "objectperfil.h"
#include <cmath>
#include <iostream>

using namespace std;

ObjectPerfil::ObjectPerfil() {}

ObjectPerfil::ObjectPerfil(const string filename, int N, char eje,
                           char _drawtapas)
    : PlyObject(filename) {
  switch (eje) {
  case 'y':
    objetoRevolucionEjeY(N, _drawtapas);
    break;
  case 'x':
    objetoRevolucionEjeX(N, _drawtapas);
    break;
  case 'z':
    objetoRevolucionEjeZ(N, _drawtapas);
    break;
  default:
    objetoRevolucionEjeY(N, _drawtapas);
    break;
  }
}

void ObjectPerfil::initialice2(int N, char eje, char _drawtapas) {
  switch (eje) {
  case 'y':
    points.push_back(InsertPoint3d(20.0, 0.0, 0.0));
    points.push_back(InsertPoint3d(20.0, 20.0, 0.0));
    points.push_back(InsertPoint3d(20.0, 40.0, 0.0));
    points.push_back(InsertPoint3d(20.0, 60.0, 0.0));
    objetoRevolucionEjeY(N, _drawtapas);
    break;
  case 'x':
    points.push_back(InsertPoint3d(0.0, 20.0, 0.0));
    points.push_back(InsertPoint3d(20.0, 20.0, 0.0));
    points.push_back(InsertPoint3d(40.0, 20.0, 0.0));
    points.push_back(InsertPoint3d(60.0, 20.0, 0.0));
    objetoRevolucionEjeX(N, _drawtapas);
    break;
  case 'z':
    points.push_back(InsertPoint3d(20.0, 0.0, 0.0));
    points.push_back(InsertPoint3d(20.0, 0.0, 20.0));
    points.push_back(InsertPoint3d(20.0, 0.0, 40.0));
    points.push_back(InsertPoint3d(20.0, 0.0, 60.0));
    objetoRevolucionEjeZ(N, _drawtapas);
    break;
  default:
    points.push_back(InsertPoint3d(0.0, 0.0, 0.0));
    points.push_back(InsertPoint3d(0.0, 20.0, 20.0));
    points.push_back(InsertPoint3d(0.0, 20.0, 40.0));
    points.push_back(InsertPoint3d(0.0, 20.0, 60.0));
    objetoRevolucionEjeY(N, _drawtapas);
    break;
  }
}
void ObjectPerfil::initialice3(float tl, int N) {
  // Para hacer barrido el 1ºer y el último punto deben ser el mismo.
  // Añadimos los puntos a mano
  points.push_back(InsertPoint3d(-tl, -tl, tl));
  points.push_back(InsertPoint3d(tl, -tl, tl));
  points.push_back(InsertPoint3d(tl, -tl, -tl));
  // points.push_back(InsertPoint3d(-tl, -tl, -tl));
  // points.push_back(InsertPoint3d(-tl, -tl, tl));

  if (points[0].x == points[points.size() - 1].x &&
      points[0].y == points[points.size() - 1].y &&
      points[0].z == points[points.size() - 1].z) {
    points.pop_back();
  }
  const int TAM1 = points.size();
  objetoBarrido(TAM1, N);
}

// Método revolución para el eje Y
void ObjectPerfil::objetoRevolucionEjeY(int N, char _drawtapas) {
  bool drawtapas = true;
  drawtapas = ((toupper(_drawtapas) == 'S') ? true : false);
  bool p_quitado1 = false;
  bool p_quitado2 = false;
  Point3d p_guardado1, p_guardado2;

  // Borrar el 1ºer elemento en caso de estar en el eje y
  if (points[0].x == 0.0) {
    p_guardado1.x = points[0].x;
    p_guardado1.y = points[0].y;
    p_guardado1.z = points[0].z;
    p_quitado1 = true;
    points.erase(points.begin());
  }

  // Borrar el último elemento en caso de estar en el eje y
  if (points[points.size() - 1].x == 0.0) {
    p_guardado2.x = points[points.size() - 1].x;
    p_guardado2.y = points[points.size() - 1].y;
    p_guardado2.z = points[points.size() - 1].z;
    p_quitado2 = true;
    points.pop_back();
  }

  // Definimos una constante para los grados
  double grade = (2 * PI) / N;
  const int TAM = points.size();
  // Calculamos los nuevos vértices.
  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < TAM; ++i) {
      /*cout << "Puntos: x = "
           << (cos(grade) * points[i].x) + (sin(grade) * points[i].z)
           << " y = " << points[i].y << " z = "
           << (-sin(grade) * points[i].x) + (cos(grade) * points[i].z) <<
         endl;*/
      points.push_back(InsertPoint3d(
          (cos(grade) * points[i].x) + (sin(grade) * points[i].z), points[i].y,
          (-sin(grade) * points[i].x) + (cos(grade) * points[i].z)));
    }
    grade = grade + (2 * PI) / N;
  }

  if (drawtapas)
    // Calculamos las caras con tapas
    calcularCarasTapasY(TAM, p_guardado1, p_quitado1, p_guardado2, p_quitado2);
  else
    // Calculamos las caras sin tapas
    calcularCarasNoTapasY(TAM);
}

// Método revolución para el eje X
void ObjectPerfil::objetoRevolucionEjeX(int N, char _drawtapas) {
  bool drawtapas = true;
  Point3d p_guardado2, p_guardado1;
  bool p_quitado2 = false;
  bool p_quitado1 = false;
  drawtapas = ((toupper(_drawtapas) == 'S') ? true : false);

  // Borrar el 1ºer elemento en caso de estar en el eje y
  if (points[0].y == 0.0) {
    p_guardado1.x = points[0].x;
    p_guardado1.y = points[0].y;
    p_guardado1.z = points[0].z;
    p_quitado1 = true;
    points.erase(points.begin());
  }

  // Borrar el último elemento en caso de estar en el eje y
  if (points[points.size() - 1].y == 0.0) {
    p_guardado2.x = points[points.size() - 1].x;
    p_guardado2.y = points[points.size() - 1].y;
    p_guardado2.z = points[points.size() - 1].z;
    p_quitado2 = true;
    points.pop_back();
  }

  // Definimos una constante para los grados
  double grade = (2 * PI) / N;
  const int TAM = points.size();
  // Calculamos los nuevos vértices.
  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < TAM; ++i) {
      /*cout << "Puntos: x = "
           << (cos(grade) * points[i].x) + (sin(grade) * points[i].z)
           << " y = " << points[i].y << " z = "
           << (-sin(grade) * points[i].x) + (cos(grade) * points[i].z) <<
         endl;*/
      points.push_back(InsertPoint3d(
          points[i].x, (cos(grade) * points[i].y) + (-sin(grade) * points[i].z),
          (sin(grade) * points[i].y) + (cos(grade) * points[i].z)));
    }
    grade = grade + (2 * PI) / N;
  }

  if (drawtapas)
    // Calculamos las caras con tapas
    calcularCarasTapasX(TAM, p_guardado1, p_quitado1, p_guardado2, p_quitado2);
  else
    // Calculamos las caras sin tapas
    calcularCarasNoTapasX(TAM);
}
// Método revolución para el eje z
void ObjectPerfil::objetoRevolucionEjeZ(int N, char _drawtapas) {
  bool drawtapas = true;
  drawtapas = ((toupper(_drawtapas) == 'S') ? true : false);
  Point3d p_guardado2, p_guardado1;
  bool p_quitado2 = false;
  bool p_quitado1 = false;

  // Borrar el 1ºer elemento en caso de estar en el eje y
  if (points[0].y == 0.0) {
    p_guardado1.x = points[0].x;
    p_guardado1.y = points[0].y;
    p_guardado1.z = points[0].z;
    p_quitado1 = true;
    points.erase(points.begin());
  }

  // Borrar el último elemento en caso de estar en el eje y
  if (points[points.size() - 1].y == 0.0) {
    p_guardado2.x = points[points.size() - 1].x;
    p_guardado2.y = points[points.size() - 1].y;
    p_guardado2.z = points[points.size() - 1].z;
    p_quitado2 = true;
    points.pop_back();
  }

  // Definimos una constante para los grados
  double grade = (2 * PI) / N;
  const int TAM = points.size();
  // Calculamos los nuevos vértices.
  for (int j = 1; j < N; ++j) {
    for (int i = 0; i < TAM; ++i) {
      /*cout << "Puntos: x = "
           << (cos(grade) * points[i].x) + (sin(grade) * points[i].z)
           << " y = " << points[i].y << " z = "
           << (-sin(grade) * points[i].x) + (cos(grade) * points[i].z) <<
         endl;*/
      points.push_back(InsertPoint3d(
          (cos(grade) * points[i].x) + (-sin(grade) * points[i].y),
          (cos(grade) * points[i].y) + (sin(grade) * points[i].x),
          points[i].z));
    }
    grade = grade + (2 * PI) / N;
  }

  if (drawtapas)
    // Calculamos las caras con tapas
    calcularCarasTapasZ(TAM);
  else
    // Calculamos las caras sin tapas
    calcularCarasNoTapasZ(TAM);
}

// Método para calcular las caras con tapas
void ObjectPerfil::calcularCarasTapasY(int TAM, Point3d p_guardado1,
                                       bool p_quitado1, Point3d p_guardado2,
                                       bool p_quitado2) {
  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil
  // inicial para calcular las tapas superiores

  // Primero calulamos la proyección del punto inicial dado
  if (p_quitado1) {
    points.push_back(p_guardado1);
  } else {
    points.push_back(InsertPoint3d(0.0, points[0].y, points[0].z));
  }

  // Ahora calculamos la tapa inferior
  for (int i = 0; i < points.size() - TAM - 1; i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  // Añadimos la última cara
  faces.push_back(InsertFace(points.size() - TAM - 1, 0, points.size() - 1));

  // Calculamos la proyección del punto final dado
  if (p_quitado2) {
    points.push_back(p_guardado2);
  } else {
    points.push_back(InsertPoint3d(0.0, points[TAM - 1].y, points[TAM - 1].z));
  }

  // Ahora calculamos la tapa superior
  for (int i = TAM - 1; i < points.size() - (TAM - 1); i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  faces.push_back(
      InsertFace(points.size() - (TAM - 1), TAM - 1, points.size() - 1));
}

// Método para calcular las caras sin tapas
void ObjectPerfil::calcularCarasNoTapasY(int TAM) {
  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil

  // Primero calulamos la proyección del punto inicial dado
  points.push_back(InsertPoint3d(0.0, points[0].y, points[0].z));

  // Calculamos la proyección del punto final dado
  points.push_back(InsertPoint3d(0.0, points[TAM - 1].y, points[TAM - 1].z));
}

void ObjectPerfil::calcularCarasTapasX(int TAM, Point3d p_guardado1,
                                       bool p_quitado1, Point3d p_guardado2,
                                       bool p_quitado2) {
  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil
  // inicial para calcular las tapas superiores

  // Primero calulamos la proyección del punto inicial dado
  if (p_quitado1) {
    points.push_back(p_guardado1);
  } else {
    points.push_back(InsertPoint3d(points[0].x, 0.0, points[0].z));
  }
  // points.push_back(InsertPoint3d(points[0].x, points[0].y, 0.0));

  // Ahora calculamos la tapa inferior
  for (int i = 0; i < points.size() - TAM - 1; i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  // Añadimos la última cara
  faces.push_back(InsertFace(points.size() - TAM - 1, 0, points.size() - 1));

  // Calculamos la proyección del punto final dado
  if (p_quitado2) {
    points.push_back(p_guardado2);
  } else {
    points.push_back(InsertPoint3d(points[TAM - 1].x, 0.0, points[TAM - 1].z));
  }

  // Ahora calculamos la tapa superior
  for (int i = TAM - 1; i < points.size() - (TAM - 1); i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  faces.push_back(
      InsertFace(points.size() - (TAM - 1), TAM - 1, points.size() - 1));
}
void ObjectPerfil::calcularCarasNoTapasX(int TAM) {
  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil

  // Primero calulamos la proyección del punto inicial dado
  points.push_back(InsertPoint3d(points[0].x, points[0].y, 0.0));

  // Calculamos la proyección del punto final dado
  points.push_back(InsertPoint3d(points[TAM - 1].x, points[TAM - 1].y, 0.0));
}

void ObjectPerfil::calcularCarasTapasZ(int TAM) {

  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil
  // inicial para calcular las tapas superiores

  // Primero calulamos la proyección del punto inicial dado
  points.push_back(InsertPoint3d(points[0].x, 0.0, points[0].z));

  // Ahora calculamos la tapa inferior
  for (int i = 0; i < points.size() - TAM - 1; i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  // Añadimos la última cara
  faces.push_back(InsertFace(points.size() - TAM - 1, 0, points.size() - 1));

  // Calculamos la proyección del punto final dado
  points.push_back(InsertPoint3d(points[TAM - 1].x, 0.0, points[TAM - 1].z));

  // Ahora calculamos la tapa superior
  for (int i = TAM - 1; i < points.size() - (TAM - 1); i += TAM)
    faces.push_back(InsertFace(i, i + TAM, points.size() - 1));

  faces.push_back(
      InsertFace(points.size() - (TAM - 1), TAM - 1, points.size() - 1));
}
void ObjectPerfil::calcularCarasNoTapasZ(int TAM) {
  // Calculamos las caras/
  for (int i = 0; i < points.size() - TAM; i += TAM) {
    for (int j = i; j < (TAM - 1) + i; ++j) {
      faces.push_back(InsertFace(j, (TAM + j), (TAM + 1 + j)));
      faces.push_back(InsertFace((TAM + 1 + j), (1 + j), j));
    }
  }
  // Metemos la última cara

  for (int i = 0; i < (TAM - 1); ++i) {
    faces.push_back(InsertFace((points.size() - TAM + i), i, i + 1));
    faces.push_back(InsertFace((i + 1), (points.size() - TAM + i + 1),
                               (points.size() - TAM + i)));
  }

  // Ahora calculamos las proyecciones del 1ºer y último punto, del perfil

  // Primero calulamos la proyección del punto inicial dado
  points.push_back(InsertPoint3d(points[0].x, 0.0, points[0].z));

  // Calculamos la proyección del punto final dado
  points.push_back(InsertPoint3d(points[TAM - 1].x, 0.0, points[TAM - 1].z));
}

// Método que realiza el barrido de los puntos en el eje y.
void ObjectPerfil::objetoBarrido(int TAM1, int N) {
  // Calculamos los puntos
  for (int i = 0; i < TAM1; ++i)
    points.push_back(InsertPoint3d(points[i].x, points[i].y + N, points[i].z));

  // Calculamos las caras
  for (int i = 0; i < points.size() - TAM1 - 1; ++i) {
    faces.push_back(InsertFace(i, i + 1, i + 1 + TAM1));
    faces.push_back(InsertFace(i + 1 + TAM1, i + TAM1, i));
  }
  // Añadimos la última cara
  /*faces.push_back(InsertFace(TAM1 - 1, 0, TAM1));
  faces.push_back(InsertFace(TAM1, (TAM1 * 2 - 1), TAM1 - 1));*/
}
