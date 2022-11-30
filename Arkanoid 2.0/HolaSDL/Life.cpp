#include "Life.h"

// Constructora de la clase
Life::Life(Vector2D p, int s, Texture* t, Texture* n, int l, Texture* x): ArkanoidObject(p, s, s, t)
{
	lives = l;
	row = 0; col = 0;
	//texturas
	heart = t; number = n; this->x = x;
}

// Renderiza la vida en pantalla
void Life::render() const
{
	SDL_Rect destRectHeart, destRectNumber, destRectX;
	
	destRectHeart.w = w;
	destRectHeart.h = h;
	destRectHeart.x = pos.getX();
	destRectHeart.y = pos.getY();
	heart->render(destRectHeart);

	destRectX = destRectHeart;
	destRectX.x = pos.getX() + w;
	x->render(destRectX);

	destRectNumber = destRectHeart;
	destRectNumber.x = pos.getX() + (w*2);
	number->renderFrame(destRectNumber, row, col);

}

// Resetea el numero de vidas
void Life::resetLife() {
	lives = 3;
}

// Actualiza el numero de vidas en pantalla
void Life::update() {
	switch (lives) {
	case 0: row = 0; col = 0; break;
	case 1: row = 0; col = 1; break;
	case 2: row = 0; col = 2; break;
	case 3: row = 0; col = 3; break;
	case 4: row = 1; col = 0; break;
	case 5: row = 1; col = 1; break;
	case 6: row = 1; col = 2; break;
	case 7: row = 1; col = 3; break;
	case 8: row = 2; col = 0; break;
	case 9: row = 2; col = 1; break;
	}
}

// Guarda los datos relevantes del objeto
void Life::saveToFile(ofstream& saveFile)
{
	saveFile << "Life " << lives << endl;
}

// Lee de archivo los datos relevantes del objeto y los modifica
void Life::loadFromFile(ifstream& loadFile)
{
	int l;
	loadFile >> l;
	lives = l;
	if (loadFile.fail() || lives <= 0) throw (FileFormatError("Error in reading lives from save file"));
}