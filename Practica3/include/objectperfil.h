#ifndef _OBJECTPERFIL_
#define _OBJECTPERFIL_

#include "ejes.h"
#include "plyobject.h"

#define PI 3.1415926535897

class ObjectPerfil : public PlyObject {
public:
  // Constructor por defecto
  ObjectPerfil();
  // Constructor por revolución para un fichero PLY
  ObjectPerfil(const string filename, int N = 12, char eje = 'y',
               char _drawtapas = 'S');
  // Constructor por revolución para unos puntos fijos
  void initialice2(int N = 12, char eje = 'y', char _drawtapas = 'S');
  // Constructor para cargar el método revolucion
  void initialice3(float tl = 40.0, int N = 80);
  // Método revolución para el eje y
  void objetoRevolucionEjeY(int N = 12, char _drawtapas = 'S');
  // Método revolución para el eje x
  void objetoRevolucionEjeX(int N = 12, char _drawtapas = 'S');
  // Método revolución para el eje z
  void objetoRevolucionEjeZ(int N = 12, char _drawtapas = 'S');
  // Método para calcular las caras con tapas, eje Y
  void calcularCarasTapasY(int TAM, Point3d p_guardado1, bool p_quitado1,
                           Point3d p_guardado2, bool p_quitado2);
  // Método para calcular las caras sin tapas, eje Y
  void calcularCarasNoTapasY(int TAM);
  // Método para calcular las caras con tapas, eje X
  // void calcularCarasTapasX(int TAM);
  void calcularCarasTapasX(int TAM, Point3d p_guardado1, bool p_quitado1,
                           Point3d p_guardado2, bool p_quitado2);
  // Método para calcular las caras sin tapas, eje X
  void calcularCarasNoTapasX(int TAM);
  // Método para calcular las caras con tapas, eje Z
  void calcularCarasTapasZ(int TAM);
  // Método para calcular las caras sin tapas, eje Z
  void calcularCarasNoTapasZ(int TAM);
  // Método que realiza el barrido de los puntos en el eje y.
  void objetoBarrido(int TAM1, int N = 80);
};
#endif
