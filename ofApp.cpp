#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 15);

	this->image.load("images/gecko.png");
	this->pix = this->image.getPixelsRef();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofColor word_color;
	vector<string> word = { "G", "E", "C", "K", "O" };

	ofTranslate((ofGetWidth() - this->image.getWidth()) * 0.5, (ofGetHeight() - this->image.getHeight()) * 0.5);
	
	for (int x = 0; x < this->image.getWidth(); x += this->font.getSize()) {

		for (int y = 0; y < this->image.getHeight(); y += this->font.getSize()) {

			ofColor pix_color = this->pix.getColor(x, y);
			if (pix_color != ofColor(0)) {

				continue;
			}

			int word_index = ofMap(ofNoise(x * 0.008, y * 0.008 + ofGetFrameNum() * 0.03), 0, 1, 0, word.size());
			word_color.setHsb(ofMap(word_index, 0, word.size(), 0, 239), 200, 255);
			ofSetColor(word_color);
			this->font.drawString(word[word_index], x, y);
		}
	}

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}