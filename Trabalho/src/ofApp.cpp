#include "ofApp.h"
#include <Math.h>

//--------------------------------------------------------------
void ofApp::setup() {
	sol = new Sol();
	asteroide = new Asteroide();
	lua = new Lua();
	planeta = new Planeta();
	asteroide->addForce(ofVec2f(1,0.5f),3);
}

//--------------------------------------------------------------
void ofApp::update(){
	//float time = ofGetElapsedTime();
	planeta->update(1,ofVec2f(sol->position.x,sol->position.y));
	lua->update(1, ofVec2f(planeta->position.x, planeta->position.y));
	
	ofVec2f dir = (sol->position, asteroide->position);
	dir.normalize();

	float force = attract(sol->massa, asteroide->massa, asteroide->position.distance( sol->position));
	
	asteroide->addForce(dir, force);

	 dir = (lua->position, asteroide->position);
	dir.normalize();

	 force = attract(lua->massa, asteroide->massa, asteroide->position.distance(lua->position));

		asteroide->addForce(dir, force);

	 dir = (planeta->position, asteroide->position);
	dir.normalize();

	 force = attract(planeta->massa, asteroide->massa, asteroide->position.distance(planeta->position));

	asteroide->addForce(dir, force);

	asteroide->update(1);
}

//--------------------------------------------------------------
void ofApp::draw(){
	sol->draw();
	asteroide->draw();
	lua->draw();
	planeta->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

float ofApp::attract(float m1, float m2, float d) {
	float G = 0.03;


	return m1*m2 * G / pow(d,2);
}
