#pragma once
#include "ofMain.h"

class Sol

{

protected:


	float m_Width;
	float m_Height;


private: 
		 ofVec2f momentum;
		 float angle; //orientation float mass;
public:
	void update(float time);
	ofImage m_image;
	ofVec2f position;
	float massa;


	Sol()
	{
		massa = 200;
		m_image.load("Sol.png");
		position.x =500;
		position.y = 400;
	}

	void draw() {

		m_image.draw(position.x - m_image.getWidth()/2, position.y-m_image.getHeight()/2);
	}
};
