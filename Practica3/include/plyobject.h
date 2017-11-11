#ifndef _PLYOBJECT_
#define _PLYOBJECT_

#include "file_ply_stl.h"
#include "object3d.h"
#include <iostream>

class PlyObject : public Object3d {
public:
  PlyObject();
  PlyObject(const string filename);
};

#endif
