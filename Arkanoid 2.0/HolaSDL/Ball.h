#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "MovingObject.h"
using namespace std;

class Game;
class Ball : public MovingObject
{
private:
	Game* game;

public:
	Ball(Vector2D p, int size, Vector2D d, Texture* t, Game* g) : MovingObject(p, size, size, t, d), game(g) {};
	void render() const override;
    void update() override;
	Vector2D getDir() { return dir; }

};
