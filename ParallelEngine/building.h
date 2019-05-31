#ifndef BUILDING_H
#define BUILDING_H
#include "tilemap.h"
#include <iostream>

/* Base class for special tiles (buildings) */
class Building {
public:
	Building(std::shared_ptr<TileMap> tm_) : tm(tm_) {}
	int getx() const { return x; }
	int gety() const { return y; }
	int getrow() const { return row; }
	int getcol() const { return col; }

	virtual void render() = 0;
	virtual void update(ALLEGRO_KEYBOARD_STATE & ks, float mouseX, float mouseY) = 0;

	bool isPlaced() { return placed; }
	bool isPlacing() { return placing; }

	void enablePlacing() { placed = false; placing = true; }
	void setPlaced() { placed = true; placing = false; }

protected:
	ALLEGRO_BITMAP * img;
	std::shared_ptr<TileMap> tm;
	int x, y;
	int row, col;
	bool placed, placing;
};

#endif