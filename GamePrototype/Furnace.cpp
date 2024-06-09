#include "pch.h"
#include "Furnace.h"
#include "utils.h"
#include "Player.h"
#include <iostream>

Furnace::Furnace(const Rectf viewPort, Energie energie)
	: m_Energie{ energie },
	m_Viewport{viewPort}
{
}

Furnace::~Furnace()
{
}

void Furnace::Draw()
{
	utils::SetColor(Color4f{ 0.1,0.1,0.1,1 });
	utils::DrawRect(m_Viewport.width / 4, m_Viewport.height / 3*2, m_Viewport.width / 16, m_Viewport.width / 16);
	utils::SetColor(Color4f{ 1,1,1,1 });
}

void Furnace::Update()
{
	Circlef circle{ Point2f((m_Viewport.width / 4 + m_Viewport.width / 32),(m_Viewport.height / 3 * 2 + m_Viewport.width / 32)),  m_Viewport.width / 8};
	if (utils::IsPointInCircle(Player::m_PlayerLocation, circle))
	{
		Interact();
	}
}

void Furnace::Interact()
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_E])
	{
		m_Energie.AddEnergie(15);
		std::cout << "enegie added\n";

	}
}
