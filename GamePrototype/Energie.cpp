#include "pch.h"
#include "Energie.h"
#include "utils.h"
#include <iostream>

Energie::Energie(const Rectf viewPort)
	:m_EnergieMax{100.f},
	m_Viewport{ viewPort },
	m_Energie{ 0.f },
	m_IsDood{false}
{
	m_Energie = m_EnergieMax;
}

Energie::~Energie()
{
}

void Energie::AddEnergie(float energie)
{
	m_Energie += energie;
	std::cout << "energie added : " << energie << std::endl;
	std::cout << "energie : " << m_Energie << std::endl;
	if (m_Energie > m_EnergieMax)
	{
		m_Energie = m_EnergieMax;
	}
}

void Energie::RessetEnergie()
{
	m_Energie = m_EnergieMax;
}

void Energie::DecreaseEnergie(float energie)
{
	m_Energie -= energie;
	if (m_Energie < 0)
	{
		m_IsDood = true;
		m_Energie = 0;
	}
}

void Energie::IsDood()
{
	if (m_IsDood)
	{
		std::cout << "You are dead\n";
	}
}

void Energie::Draw()
{
	utils::SetColor(Color4f{ 1,1,0,1 });
	utils::DrawRect(m_Viewport.width - m_Viewport.width / 16, m_Viewport.height / 4, m_Viewport.width / 32, m_Viewport.height / 2);
	utils::FillRect(m_Viewport.width - m_Viewport.width / 16, m_Viewport.height / 4, m_Viewport.width / 32, m_Viewport.height / 2 * m_Energie/ m_EnergieMax);
	utils::SetColor(Color4f{ 1,1,1,1 });
	std::cout << "energie : " << m_Energie << std::endl;
}

void Energie::Update(float elapsedSec)
{
	DecreaseEnergie(0.05f);
	IsDood();
}
