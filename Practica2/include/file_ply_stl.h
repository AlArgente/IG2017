//******************************************************************************
// class to read ply files of triangles
//
// Domingo Martín Perandres (c) 2003-2013
//
// Gnu Public Licence
//******************************************************************************

#ifndef _READ_PLY
#define _READ_PLY

#include "object3d.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class _file_ply {
public:
  _file_ply(){};
  int open(const string &File_name);
  void read(vector<Point3d> &points, vector<Face> &faces);
  void close();

private:
  void get_token(std::istringstream &Line_stream1, std::string &Token1);
  bool get_new_line(std::ifstream &File, std::istringstream &Line_stream);

  std::ifstream File;
};

#endif
