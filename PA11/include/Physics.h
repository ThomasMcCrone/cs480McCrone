#ifndef TUTORIAL_PHYSICS_H
#define TUTORIAL_PHYSICS_H
#include "graphics_headers.h"
#include "object.h"

class Object;
class Sun;
class PhysicsEngine
{
    friend class Engine;
    friend class Graphics;
    
public:
	PhysicsEngine();
	~PhysicsEngine();
	// bullet things
	btBroadphaseInterface *m_broadphase;
	btDefaultCollisionConfiguration *m_configuration;
	btCollisionDispatcher *m_dispatcher;
	btSequentialImpulseConstraintSolver *m_solver;
	btDiscreteDynamicsWorld *m_dynamicsWorld;

	// functions
	void createObjects();
	void Update(unsigned int dt);
	void applyForce(int obj,int direction);
	void reset();
	int isOver();
	void shrink();

	void Render();
	void Launch();

	// objects
	Object *player1;
	Object *player2;
	Object *Snowball1;
	Object *Snowball2;
	Object *Snowball3;
	Object *Snowball4;
	Object *Snowball5;
	Object *Snowball6;
	Object *plane;
	std::vector<Object*> field;
	std::vector<bool> fieldCollapse;
};

#endif //TUTORIAL_PHYSICS_H


