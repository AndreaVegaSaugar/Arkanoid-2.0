#include "MenuGameState.h"

MenuGameState::MenuGameState(Game* game, string _menuID, Texture* t, Vector2D p, int w, int h) : GameState(game), menuID(_menuID), textureB(t), posB(p), widthB(w), heightB(h)
{
	rectB.x = 0; rectB.y = 0; rectB.w = w; rectB.h = h; // rectB.x = p.getX(); rectB.y = p.getY(); ??
}