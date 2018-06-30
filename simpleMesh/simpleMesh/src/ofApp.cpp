#include "ofApp.h"

bool test;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	//mesh.setMode(OF_PRIMITIVE_POINTS);
	//mesh.setMode(OF_PRIMITIVE_LINES);
	//mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
	//mesh.setMode(OF_PRIMITIVE_LINE_LOOP);
	//mesh.setMode(OF_PRIMITIVE_TRIANGLES);
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY);
	meshLines.setMode(OF_PRIMITIVE_LINE_STRIP);

	cam.setPosition(ofGetWindowWidth() / 2, 50, 500);

	float rango = ofGetWindowHeight() / nV*.5;

	for (int i = 0; i < nV; i++) {

		/*ofVec3f vertice(
			ofMap(i, 0, nV, 0, ofGetWindowWidth()) + ofRandom(-5, 5),
			ofGetWindowHeight() / 2 + ofRandom(-5 * i + 1, 5 * i + 1),
			0.0);*/
		ofVec3f vertice;
		if (i % 2 == 0) {
			ofVec3f vertice(
				sin(ofMap(i, 0, nV, 0, 360))*ofGetWindowWidth() / 2,
				ofGetWindowHeight() / 2 + ofRandom(-rango * i + 1, rango * i + 1),
				//350,
				cos(ofMap(i, 0, nV, 0, 360))*ofGetWindowWidth() / 2
			);
		}
		else {
			ofVec3f vertice(
				sin(ofMap(i, 0, nV, 0, 360))*ofGetWindowWidth() / 2,
				ofGetWindowHeight() / 2 + ofRandom(-rango * i + 1, rango * i + 1),
				//-350,
				cos(ofMap(i, 0, nV, 0, 360))*ofGetWindowWidth() / 2
			);
		}

		mesh.addVertex(vertice);
		meshLines.addVertex(vertice);
		float val = ofRandom(1);
		mesh.addColor(ofFloatColor(val, val, val, ofRandom(1)));
		offsets.push_back(ofVec3f(ofRandom(0, 100000), ofRandom(0, 100000), ofRandom(0, 100000)));

	}
	for (int i = 0; i < nV-2; i+=3) {
		mesh.addIndex(i);
		mesh.addIndex(i + 1);
		mesh.addIndex(i + 2);
		meshLines.addIndex(i);
		meshLines.addIndex(i + 1);
		meshLines.addIndex(i + 2);
	}

}

//--------------------------------------------------------------
void ofApp::update(){
	if(test){
		int numVerts = mesh.getNumVertices();
		for (int i = 0; i < numVerts; ++i) {
			ofVec3f vert = mesh.getVertex(i);

			float time = ofGetElapsedTimef();
			float timeScale = 1;
			float displacementScale =  1.05;
			ofVec3f timeOffsets = offsets[i];

			vert.x += (ofSignedNoise(time*timeScale + timeOffsets.x)) * displacementScale;
			vert.y += (ofSignedNoise(time*timeScale + timeOffsets.y)) * displacementScale;
			vert.z += (ofSignedNoise(time*timeScale + timeOffsets.z)) * displacementScale;
			mesh.setVertex(i, vert);
			meshLines.setVertex(i, vert);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);
	cam.begin();
	cam.setDrag(0.1);

	if (test)
		drawTestMesh();

	cam.end();

}

//--------------------------------------------------------------
void ofApp::drawTestMesh() {
	mesh.draw();
	ofSetColor(0);
	ofNoFill();
	meshLines.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		float rango = ofGetWindowHeight() / nV*.5;
		for (int i = 0; i < nV; i++) {
			/*
			ofVec3f newVertice(
				ofMap(i, 0, nV, 0, ofGetWindowWidth()) +	ofRandom(-5,5 ),
				ofGetWindowHeight()/2 + ofRandom(-rango * i + 1, rango * i+1),
				cos(ofMap(i,0,nV,0,360))*ofGetWindowWidth());
				*/		
			ofVec3f newVertice(
				sin(ofDegToRad(ofMap(i, 0, nV, 0, 360)))*ofGetWindowWidth() / 2,
				ofGetWindowHeight() / 2 + ofRandom(-rango * i + 1, rango * i + 1),
				cos(ofDegToRad(ofMap(i, 0, nV, 0, 360)))*ofGetWindowWidth() / 2
			);

			mesh.setVertex(i, newVertice);
			mesh.addColor(ofFloatColor(ofRandom(1), ofRandom(1), ofRandom(1), ofRandom(1)));
		}
	}
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
