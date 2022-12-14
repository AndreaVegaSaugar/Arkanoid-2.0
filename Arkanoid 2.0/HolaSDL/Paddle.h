#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include "Ball.h"
#include "MovingObject.h"

using namespace std;

// Clase PADDLE que hereda de MOVINGOBJECT
class PlayState;
class Paddle : public MovingObject
{
private:
	int rightLimit = 0;
	int leftLimit = 0;
	PlayState* game = nullptr;

public:
	// Constructora de la clase
	Paddle(Vector2D p, int h, int w, Texture* t, PlayState* g, Vector2D d, int rL, int lL, double s) : MovingObject(p, h, w, t, d, s), game(g), rightLimit(rL), leftLimit(lL) {};
	
	// Getter
	int getWidth() { return w; };
	
	// Metodos publicos de la clase
	virtual void update();
	virtual void loadFromFile(ifstream& loadFile);
	virtual void saveToFile(ofstream& saveFile);
	void handleEvent(SDL_Event event);
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector, const Vector2D& dir);
	void setPos(Vector2D p) { pos = p; };
	void setWidth(int width) { w = width; };
	void restartPaddle() { pos = Vector2D((double)((WIN_WIDTH / 2) - 50), (double)WIN_HEIGHT - 100); w = PADDLE_WIDTH; h = PADDLE_HEIGHT; };

protected:
	Vector2D collision(const SDL_Rect& ballRect, const SDL_Rect& collision, const Vector2D& dir);
};

