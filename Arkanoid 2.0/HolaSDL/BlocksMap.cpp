#include "checkML.h"
#include "BlocksMap.h"
#include "PlayState.h"
#include <iostream>

using namespace std;

// Destructora de la clase
BlocksMap::~BlocksMap()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (gameMap[i][j] != nullptr) delete gameMap[i][j];
		}
		delete gameMap[i];
	}
	delete[] gameMap;
}

// Carga el mapa desde un archivo
void BlocksMap::loadMap(const string& file)
{
	ifstream map;
	map.open(file);
	if (map.is_open())
	{
		int r, c;
		map >> r >> c;

		rows = r;
		cols = c;

		cellW = w / cols;
		cellH = h / rows;
		
		createMap(map);
	}
	else throw (FileNotFoundError("Error trying to open file: " + file));
	map.close();
}

// Crea el mapa
void BlocksMap::createMap(ifstream& map) {
	int color;
	gameMap = new Block * *[rows];
	for (int i = 0; i < rows; ++i)
	{
		gameMap[i] = new Block * [cols];

		for (int j = 0; j < cols; ++j)
		{
			map >> color;
			if(map.fail() || color < 0 || color > 6) throw (FileFormatError("Error in reading map from level/save file"));
			if (color != 0) gameMap[i][j] = new Block(Vector2D(j, i), cellW, cellH, color, texture, game);
			else gameMap[i][j] = nullptr;
		}
	}
	if(getNumBlocks() == 0) throw (FileFormatError("Incorrect map in level/save file"));
}

// Renderiza el mapa
void BlocksMap::render()const
{
	for (int n = 0; n < rows; ++n)
	{
		for (int m = 0; m < cols; ++m)
		{
			if (gameMap[n][m] != nullptr) gameMap[n][m]->render();
		}
	}
}

// Devuelve el numero de bloques sin destruir del mapa
int BlocksMap::getNumBlocks()
{
	int cont = 0;
	for (int n = 0; n < rows; ++n)
	{
		for (int m = 0; m < cols; ++m)
		{
			if (gameMap[n][m] != nullptr) ++cont;
		}
	}

	return cont;
}

// Controla las colisiones del mapa
bool BlocksMap::collides(SDL_Rect ballRect, Vector2D& collisionVector, const Vector2D dir, Vector2D& pos)
{
	bool collide = false; // Booleano auxiliar que detiene la busqueda al encontrar el bloque colisionado
	int n = 0;
	SDL_Rect result; // SDL_Rect de colision entre la bola y el bloque
	while (n < rows && !collide) {
		int m = 0;
		while (m < cols && !collide) {
			if ((gameMap[n][m] != nullptr) && SDL_IntersectRect(&gameMap[n][m]->getRect(), &ballRect, &result))
			{				
				pos = Vector2D(gameMap[n][m]->getRect().x, gameMap[n][m]->getRect().y); // Posicion en la que se podra generar un reward
				collisionVector = collision(result, ballRect, gameMap[n][m], dir); // Nuevo vector de colision que se enviara a la bola
				collide = true;
				delete gameMap[n][m]; 
				gameMap[n][m] = nullptr; // Borramos el bloque
			}
			++m;
		}
		++n;
	}

	return collide;
}

// Metodo auxiliar para controlar colisiones
Vector2D BlocksMap::collision(const SDL_Rect& result, const SDL_Rect& ballRect, Block* b, const Vector2D dir)
{
	Vector2D colVect = Vector2D(0, 0);

	if (result.h < result.w) {
		if (dir.getY() < 0) { colVect = Vector2D(0, 1); }
		if (dir.getY() > 0) { colVect = Vector2D(0, -1); }
	}
	else {
		if (dir.getX() < 0) { colVect = Vector2D(1, 0); }
		if (dir.getX() > 0) { colVect = Vector2D(-1, 0); }
	}

	return colVect;
}

// Lee de archivo los datos relevantes del objeto y los modifica
void BlocksMap::loadFromFile(ifstream& loadFile)
{
	int info1, info2;
	loadFile >> info1 >> info2;
	rows = info1; cols = info2;
	if (loadFile.fail() || info1 <= 0 || info2 <= 0) throw (FileFormatError("Error in reading map from save file"));
	cellH = h/ info1; cellW = w /info2;
	createMap(loadFile);
}

// Guarda los datos relevantes del objeto
void BlocksMap::saveToFile(ofstream& saveFile)
{
	saveFile << "BlocksMap " << rows << " " << cols <<  endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if(gameMap[i][j] == nullptr) saveFile << "0" << " ";
			else saveFile << gameMap[i][j]->getColor() << " ";
		}
		saveFile << endl;
	}

}