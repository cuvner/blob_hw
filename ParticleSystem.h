#pragma once

#include "ofMain.h"
#include "Particle.h"

using namespace glm;

class ParticleSystem {
public:
	void setupPlane(int gridSizeX, int gridSizeY, float planeRangeX, float planeRangeY, ofPrimitiveMode displayMode);
	void setupSphere(int gridSizeX, int gridSizeY, float sphereRadius, ofPrimitiveMode displayMode);
	void update(float amplitude, float timeStep, float restoreForce, float damping, float noiseScale, float noiseRate,
                int noiseOctaves);
	void draw();

private:
	int getParticleIndex(int x, int y);

	vector<Particle> myParticles;
	ofMesh myMesh;
	ofPrimitiveMode myDisplayMode;
	int myGridSizeX;
	int myGridSizeY;
};
