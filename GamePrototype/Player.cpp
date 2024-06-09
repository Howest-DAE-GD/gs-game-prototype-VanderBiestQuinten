#include "pch.h"
#include "Player.h"
#include "utils.h"
#include <iostream>


Point2f Player::m_PlayerLocation;

Player::Player(const Rectf viewPort)
	:m_Width{ 20.f },
	m_Viewport{ viewPort },
	m_PlayerSpeed{ Point2f{ 100,100 } }
{
	m_PlayerLocation = Point2f{ viewPort.width / 2, viewPort.height / 2 };
}

Player::~Player()
{
}


void Player::Draw()
{
	utils::DrawRect(m_PlayerLocation.x- m_Width/2, m_PlayerLocation.y - m_Width / 2, m_Width, m_Width);
}

void Player::UpdatePlayer(float elapsedSec)
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_PlayerLocation.x += m_PlayerSpeed.x * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_PlayerLocation.x -= m_PlayerSpeed.x * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		m_PlayerLocation.y += m_PlayerSpeed.y * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		m_PlayerLocation.y -= m_PlayerSpeed.y * elapsedSec;
	}

}



