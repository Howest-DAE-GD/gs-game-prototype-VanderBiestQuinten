#pragma once
class Energie
{
public:
	Energie(const Rectf viewPort);
	~Energie();
	Energie(const Energie& other) = default;
	Energie& operator=(const Energie& rhs) = default;

	void AddEnergie(float energie);
	void RessetEnergie();
	void DecreaseEnergie(float energie);
	void IsDood();

	void Draw();
	void Update(float elapsedSec);
private:
	float m_Energie;
	float m_EnergieMax;
	bool m_IsDood;

	Rectf m_Viewport;

};

