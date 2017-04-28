#pragma once
#include "ofMain.h"

class Asteroide

{

protected:

	ofImage m_image;
	float m_Width;
	float m_Height;


private:
	ofVec2f momentum;
	float angle; //orientation float mass;
public:
	ofVec2f position;
	float massa;



	Asteroide()
	{
		massa = 20;
		momentum.x = 0;
		momentum.y = 0;
		m_image.load("Asteroide.png");
		position.x = 50;
		position.y = 100;
	}

	void draw() {
		m_image.draw(position.x - m_image.getWidth() / 2, position.y - m_image.getHeight() / 2);
	}

	void addForce(ofVec2f direction, float force) {
		momentum += direction*force;
	}

	void update(float time) {
		position += momentum;
	}
};