#include "Particle.h"
#include "helpers.h"

//--------------------------------------------------------------
void Particle::setup(vec3 pos, vec3 dir) {
	myPos = pos;
	myOrigPos = pos;
	//myDir = dir;
    myVel = vec3(0, 0, 0);
	mySize = 0.1;
  
}

//--------------------------------------------------------------
void Particle::update(float amplitude, float _timeStep, float restoreForce, float damping, float noiseScale, float noiseRate, int noiseOctaves ) {
//    float phase = frequency * ofGetElapsedTimef();
//    float sinVal = sinf(myOrigPos.x / scale + phase) * sinf(myOrigPos.y / scale + phase) * sinf(myOrigPos.z / scale + phase);
//    float noiseVal = ofNoise(myOrigPos / scale);

//    myPos = myOrigPos + amplitude * sinVal * noiseVal * myDir;
   // myVel += amplitude * vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
   // myVel += _timeStep * amplitude * vec3(ofRandom(-1, 1), ofRandom(-1, 1), ofRandom(-1, 1));
    // Random walk using fbm noise functions
    myVel += _timeStep * amplitude * fbm_vec3(vec4(
                                                  myPos.x / noiseScale,
                                                  myPos.y / noiseScale,
                                                  myPos.z / noiseScale,
                                                  noiseRate * ofGetElapsedTimef()),
                                             noiseOctaves);
    
    // Restoring force back towards original position
    myVel += _timeStep * restoreForce * (myOrigPos - myPos);
    
    // Apply damping to the velocity
    myVel -= _timeStep * damping * myVel;
    
    // Increment myPos using the current velocity
    myPos += _timeStep * myVel;
}

//--------------------------------------------------------------
void Particle::draw() {
	ofDrawSphere(myPos, mySize);
}

//--------------------------------------------------------------
vec3 Particle::getPos() {
	return myPos;
}
