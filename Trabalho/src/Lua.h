#pragma once
#include "ofMain.h"

class Lua

{

protected:

	ofImage m_image;
	float m_Width;
	float m_Height;



private:
		 ofVec2f momentum;
		 float angle; //orientation float mass;
		 float velocity;
public:
	void update(float time);
	float dist;
	float massa;
	ofVec2f position;



	Lua()
	{
		massa = 25;
		dist = 120;
		angle = 0;
		velocity = (2 * PI);
		m_image.load("Lua.png");
		position.x = 300;
		position.y = 100;
	}

	void draw() {
		m_image.draw(position.x - m_image.getWidth() / 2, position.y - m_image.getHeight() / 2);
	}

	void update(float frametime, ofVec2f sunPos) {
		angle += velocity;
		position.x = cos(angle * PI / 180) * dist;
		position.y = sin(angle * PI / 180) * dist;

		position += sunPos;
	}
};

