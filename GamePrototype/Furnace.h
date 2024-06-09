#pragma once
#include "Energie.h"
class Furnace
{
public:
	Furnace(const Rectf viewPort, Energie energie);
	~Furnace();
	Furnace(const Furnace& other) = delete;
	Furnace& operator=(const Furnace& rhs) = delete;

	void Draw();
	void Update();
	void Interact();
private:
	
	Energie m_Energie;
	Rectf m_Viewport;


};

