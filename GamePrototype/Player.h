#include "Texture.h"
#include "Transform.h"
class TextureManager;

class Player
{
public:
	Player(const Rectf viewPort);
	~Player();
	Player(const Player& other) = delete;
	Player& operator=(const Player& rhs) = delete;

	void Draw();
	void UpdatePlayer(float elapsedSec);
	static Point2f m_PlayerLocation;

private:
	float m_Width;
	Rectf m_Viewport;
	Point2f m_PlayerSpeed;
	

};