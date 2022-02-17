#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Set background colour to black
	ofSetBackgroundColor(0);

	// Set variable values
	myPlaneRangeX = 100.0;
	myPlaneRangeY = 50.0;
	mySphereRadius = 40.0;
	mySphereMode = true;

	// Setup GUI
	myGui.setup();
	myGui.add(myFpsLabel.setup("FPS", ofToString(ofGetFrameRate(), 2)));
	myGui.add(paramAmplitude.set("Amplitude", 5.0, 0.0, 20.0));
	myGui.add(paramTimeStep.set("Time Step", 0.1, 0.0, 1.0));
    myGui.add(paramRestoreForce.set("Restore force", 0.1, 0.0, 1.0));
    myGui.add(paramDamping.set("Damping", 0.1, 0.0, 1.0));
    myGui.add(paramNoiseScale.set("Noise scale", 10, 0, 100));
    myGui.add(paramNoiseRate.set("Noise rate", 0.1, 0.0, 1.0));
    myGui.add(paramNoiseOctaves.set("Noise octaves", 1, 1.0, 10.0));
	myGui.add(paramGridSizeX.set("Grid size X", 200, 0, 500));
	myGui.add(paramGridSizeY.set("Grid size Y", 100, 0, 500));
	myGui.add(paramShowLines.set("Show lines", false));
	myGui.add(paramShowTriangles.set("Show triangles", false));
	myGui.add(buttonRestart.setup("Restart"));

	// Setup listeners for parameters
	paramGridSizeX.addListener(this, &ofApp::gridSizeChanged);
	paramGridSizeY.addListener(this, &ofApp::gridSizeChanged);
	paramShowLines.addListener(this, &ofApp::displayModeChanged);
	paramShowTriangles.addListener(this, &ofApp::displayModeChanged);
	buttonRestart.addListener(this, &ofApp::setupParticleSystem);

	// Setup the particle system
	setupParticleSystem();

	// Setup EasyCam
	myCamera.setAutoDistance(false);
	myCamera.setPosition(vec3(0.0, 10.0, 100.0));
	myCamera.setTarget(vec3(0.0, 0.0, 0.0));

	// Setup material to use on the particle mesh
	myMeshMaterial.setDiffuseColor(ofFloatColor(0.2, 0.5, 0.7));
	myMeshMaterial.setSpecularColor(ofFloatColor(0.7, 0.7, 0.7));
	myMeshMaterial.setAmbientColor(ofFloatColor(0.1, 0.1, 0.2));
	myMeshMaterial.setShininess(50.0);

	// Setup lights (settings for discrete GPU)
	myLight1.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	myLight1.setSpecularColor(myLight1.getDiffuseColor());
	myLight1.setPosition(vec3(120.0, 50.0, 120.0));

	myLight2.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	myLight2.setSpecularColor(myLight2.getDiffuseColor());
	myLight2.setPosition(vec3(-120.0, 50.0, -120.0));
}

//--------------------------------------------------------------
void ofApp::update(){
	// Update the particles
	myParticleSystem.update(paramAmplitude, paramTimeStep, paramRestoreForce, paramDamping, paramNoiseScale, paramNoiseRate, paramNoiseOctaves);

	// Update the frames per second label in the GUI
	myFpsLabel = ofToString(ofGetFrameRate(), 2);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// Start drawing objects in 3D space
	ofEnableDepthTest();
	myCamera.begin();

	// Switch on the lights
	ofEnableLighting();
	myLight1.enable();
	myLight2.enable();

	// Draw the particles
	myMeshMaterial.begin();
	myParticleSystem.draw();
	myMeshMaterial.end();

	// Switch off lighting
	ofDisableLighting();

	// Finish drawing objects in 3D space
	myCamera.end();
	ofDisableDepthTest();

	// Draw the GUI elements
	myGui.draw();
}

//--------------------------------------------------------------
void ofApp::setupParticleSystem() {
	ofPrimitiveMode curDisplayMode;
	if (paramShowTriangles) {
		curDisplayMode = OF_PRIMITIVE_TRIANGLES;
	}
	else if (paramShowLines) {
		curDisplayMode = OF_PRIMITIVE_LINES;
	}
	else {
		curDisplayMode = OF_PRIMITIVE_POINTS;
	}

	// Call the appropriate setup function depending whether we're
	// displaying as a plane or a sphere
	if (mySphereMode) {
		myParticleSystem.setupSphere(paramGridSizeX, paramGridSizeY, mySphereRadius, curDisplayMode);
	}
	else {
		myParticleSystem.setupPlane(paramGridSizeX, paramGridSizeY, myPlaneRangeX, myPlaneRangeY, curDisplayMode);
	}
}

//--------------------------------------------------------------
void ofApp::gridSizeChanged(int &v) {
	// Simply call setupParticleSystem
	setupParticleSystem();
}

//--------------------------------------------------------------
void ofApp::displayModeChanged(bool &v) {
	// Simply call setupParticleSystem
	setupParticleSystem();
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
