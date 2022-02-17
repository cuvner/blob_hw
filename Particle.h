#pragma once

#include "ofMain.h"

using namespace glm;

class Particle {
public:
	void setup(vec3 pos, vec3 dir);
    void update(float amplitude, float _timeStep, float restoreForce, float damping, float noiseScale, float noiseRate,
                int noiseOctaves);
	void draw();
	vec3 getPos();

private:
	vec3 myPos;
	vec3 myOrigPos;
	//vec3 myDir;
	float mySize;
    
    vec3 myVel;
    float timeStep;
};
