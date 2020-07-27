#pragma once

#include "ofMain.h"

struct Cell
{
  int x;
  int y;
  bool isAlive;
  bool wasAlive;
  int aliveNeighbours;
  int trackLifespan;
};

class Board
{
public:
  int cols;
  int rows;
  std::vector<Cell> cells;

  void setup(int width, int height);
  void tick();
  void draw();

  void setRandom();

private:
  void initCells();

  Cell &getCell(int x, int y);
  int getAliveNeighboursMoore(int x, int y);
  int getAliveNeighboursNeumann(int x, int y);

  void addAcorn(int x, int y);
  void addJaydot(int x, int y);
};