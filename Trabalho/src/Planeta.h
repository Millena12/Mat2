#pragma once
#include "ofMain.h"


class Planeta

{

protected:

	ofImage m_image;
	ofImage ponto;
	float m_Width;
	float m_Height;


private: ofVec2f position2;

		 ofVec2f momentum;
		 float angle; //orientation float mass;
		 float velocity;
		 float dist;

public:
	ofVec2f position;
	float massa;

	Planeta()
	{
		massa = 100;
		ponto.load("ponto.png");
		dist = 300;
		angle = 0;
		velocity = (2 * PI ) / 5.0f;
		m_image.load("Planeta.png");
		position2.x = 100;
		position2.y = 300;
		position.x = -5000;
		position.y = 100;
	}

	void draw() {
		ponto.draw(position2.x - ponto.getWidth() / 2, position2.y - ponto.getHeight() / 2);
		m_image.draw(position.x - m_image.getWidth()  /2 , position.y- m_image.getHeight() / 2);
	}

	void update(float frametime, ofVec2f sunPos) {
		position2 = sunPos;
		angle += velocity;
		position.x = cos(angle * PI / 180) * dist;
		position.y = sin(angle * PI / 180) * dist;

		position += sunPos;
	}
};
