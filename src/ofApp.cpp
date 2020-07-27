#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
  board.setup(ofGetWidth(), ofGetHeight());
  // ofSetFrameRate(15);
  ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
  board.tick();
}

//--------------------------------------------------------------
void ofApp::draw()
{
  board.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
  board.setRandom();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
