#include "Board.hpp"

#define CELL_SIZE 4
#define TRACK_LIFESPAN 130

//--------------------------------------------------------------
void Board::setup(int width, int height)
{
  cols = width / CELL_SIZE;
  rows = height / CELL_SIZE;

  initCells();
  setRandom();
  // addAcorn(cols / 2, rows / 2);
}

//--------------------------------------------------------------
void Board::tick()
{
  // save status of previous iteration
  for (auto &cell : cells)
    cell.wasAlive = cell.isAlive;

  for (auto &cell : cells)
  {
    // cell.aliveNeighbours = getAliveNeighboursNeumann(cell.x, cell.y);
    cell.aliveNeighbours = getAliveNeighboursMoore(cell.x, cell.y);

    // RULES
    if (cell.isAlive)
    {
      if (cell.aliveNeighbours < 2 || cell.aliveNeighbours > 3)
      {
        cell.isAlive = false;
      }
    }
    else
    {
      // if (cell.aliveNeighbours == 3 || cell.aliveNeighbours == 7)
      if (cell.aliveNeighbours == 3)
      {
        cell.isAlive = true;
      }
    }

    if (cell.isAlive)
      cell.trackLifespan = TRACK_LIFESPAN;
    else
      cell.trackLifespan--;
  }
}

//--------------------------------------------------------------
void Board::draw()
{
  ofColor near = ofColor(255, 0, 0);
  ofColor far = ofColor(30, 100, 205);

  for (auto const &cell : cells)
  {
    if (cell.isAlive)
    {
      ofSetColor(255);
      ofFill();
      ofDrawRectangle(cell.x * CELL_SIZE, cell.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
    }
    else if (cell.trackLifespan > 0)
    {

      float perc = ((float)cell.trackLifespan) / TRACK_LIFESPAN * 255;
      ofSetColor(near.lerp(far, perc), perc);

      // float perc = ((float)cell.trackLifespan) / TRACK_LIFESPAN;
      // ofSetColor(near.lerp(far, perc), perc * 255);
      ofFill();
      ofDrawRectangle(cell.x * CELL_SIZE, cell.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
    }
  }
}
//--------------------------------------------------------------
Cell &Board::getCell(int x, int y)
{
  x = (x + cols) % cols;
  y = (y + rows) % rows;

  return cells.at(x + y * cols);
}

//--------------------------------------------------------------
int Board::getAliveNeighboursMoore(int x, int y)
{
  int alive = 0;

  alive += getCell(x - 1, y - 1).wasAlive;
  alive += getCell(x - 1, y).wasAlive;
  alive += getCell(x - 1, y + 1).wasAlive;

  alive += getCell(x, y - 1).wasAlive;
  alive += getCell(x, y + 1).wasAlive;

  alive += getCell(x + 1, y - 1).wasAlive;
  alive += getCell(x + 1, y).wasAlive;
  alive += getCell(x + 1, y + 1).wasAlive;

  return alive;
}

//--------------------------------------------------------------
int Board::getAliveNeighboursNeumann(int x, int y)
{
  int alive = 0;

  alive += getCell(x - 1, y - 1).wasAlive;
  alive += getCell(x - 2, y).wasAlive;
  alive += getCell(x - 1, y).wasAlive;
  alive += getCell(x - 1, y + 1).wasAlive;

  alive += getCell(x, y - 2).wasAlive;
  alive += getCell(x, y - 1).wasAlive;
  alive += getCell(x, y + 2).wasAlive;
  alive += getCell(x, y + 1).wasAlive;

  alive += getCell(x + 1, y - 1).wasAlive;
  alive += getCell(x + 2, y).wasAlive;
  alive += getCell(x + 1, y).wasAlive;
  alive += getCell(x + 1, y + 1).wasAlive;

  return alive;
}

//--------------------------------------------------------------
void Board::addAcorn(int x, int y)
{
  getCell(x + 1, y).isAlive = true;
  getCell(x + 3, y + 1).isAlive = true;
  getCell(x, y + 2).isAlive = true;
  getCell(x + 1, y + 2).isAlive = true;
  getCell(x + 4, y + 2).isAlive = true;
  getCell(x + 5, y + 2).isAlive = true;
  getCell(x + 6, y + 2).isAlive = true;
}

void Board::addJaydot(int x, int y)
{
  getCell(x + 1, y).isAlive = true;
  getCell(x + 2, y).isAlive = true;
  getCell(x, y + 1).isAlive = true;
  getCell(x + 1, y + 1).isAlive = true;
  getCell(x + 2, y + 1).isAlive = true;
  getCell(x + 1, y + 3).isAlive = true;
  getCell(x + 1, y + 4).isAlive = true;
  getCell(x + 2, y + 4).isAlive = true;
  getCell(x, y + 5).isAlive = true;
}

void Board::setRandom()
{
  for (auto &cell : cells)
    cell.isAlive = rand() % 2;
}

void Board::initCells()
{
  for (int y = 0; y < rows; y++)
  {
    for (int x = 0; x < cols; x++)
    {
      Cell c = {x, y};
      cells.push_back(c);
    }
  }
}
