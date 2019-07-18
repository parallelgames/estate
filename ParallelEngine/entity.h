#ifndef ENTITY_H
#define ENTITY_H
#include "tilemap.h"
class Entity {
public:
	Entity(TileMap* tm_, int tileCost_, int food, int gold, int stone, int wood);
	~Entity();
	
	virtual void update() = 0;
	virtual void render() = 0;

	int getx() const { return x; }
	int gety() const { return y; }

	int getTileType() {
		return tm->getType(getrow(), getcol());
	}

	int getTileID() {
		return tm->getTile(getrow(), getcol());
	}

	void renderRadius();

	int getcol() const { return tm->screenToIso(x, y).x; }
	int getrow() const { return tm->screenToIso(x, y).y; }

	int getFoodCost() const { return food; }
	int getGoldCost() const { return gold; }
	int getStoneCost() const { return stone; }
	int getWoodCost() const { return wood; }

	bool operator==(Entity* rhs) { return (this->getrow() == rhs->getrow() && this->getcol() == rhs->getcol()); }
protected:
	TileMap* tm;
	int x, y;
	int xdest, ydest;
	int tileCost; // amount of tiles that unit can move per turn
	int food, gold, stone, wood;

	int getTileCost() { return tileCost; }
};

#endif