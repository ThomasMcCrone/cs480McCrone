#include "Physics.h"

PhysicsEngine::PhysicsEngine() {
	m_broadphase = new btDbvtBroadphase();
	m_configuration = new btDefaultCollisionConfiguration();
	m_dispatcher = new btCollisionDispatcher(m_configuration);
	m_solver = new btSequentialImpulseConstraintSolver();
	m_dynamicsWorld = new btDiscreteDynamicsWorld(m_dispatcher, m_broadphase, m_solver, m_configuration);
	m_dynamicsWorld->setGravity(btVector3(0, -1, 0));
	field.resize(36);
	for(int x = 0; x<36; x++)
	{
		fieldCollapse.push_back(true);
	}
}

PhysicsEngine::~PhysicsEngine()
{
	delete m_broadphase;
	delete m_configuration;
	delete m_dispatcher;
	delete m_solver;
	delete m_dynamicsWorld;
	
}

void PhysicsEngine::Update(unsigned int dt)
{
	player1->Update(dt);
	player2->Update(dt);
	for(int x = 0; x<36; x++) field[x]->Update(dt);
	plane->Update(dt);
	Snowball1->Update(dt);
	Snowball2->Update(dt);
	Snowball3->Update(dt);
	Snowball4->Update(dt);
	Snowball5->Update(dt);
	Snowball6->Update(dt);

}
void PhysicsEngine::applyForce(int obj, int direction)
{
	float force = 10.0f;
	player1->m_rigidbody->activate(true);
	player2->m_rigidbody->activate(true);
	if(obj == 1)
	{
		switch(direction)
		{
			case 1:
				player1->m_rigidbody->applyForce(btVector3(0,0,-force),btVector3(0,0,0));
			break;
			
			case 2:
				player1->m_rigidbody->applyForce(btVector3(0,0,force),btVector3(0,0,0));
			break;
			
			case 3:
				player1->m_rigidbody->applyForce(btVector3(-force,0,0),btVector3(0,0,0));
			break;
			
			case 4:
				player1->m_rigidbody->applyForce(btVector3(force,0,0),btVector3(0,0,0));
			break;
		}
	}
	else
	{
		switch(direction)
		{
			case 1:
				player2->m_rigidbody->applyForce(btVector3(0,0,force),btVector3(0,0,0));
			break;
			
			case 2:
				player2->m_rigidbody->applyForce(btVector3(0,0,-force),btVector3(0,0,0));
			break;
			
			case 3:
				player2->m_rigidbody->applyForce(btVector3(force,0,0),btVector3(0,0,0));
			break;
			
			case 4:
				player2->m_rigidbody->applyForce(btVector3(-force,0,0),btVector3(0,0,0));
			break;
		}
	}
}
void PhysicsEngine::reset()
{
	btDefaultMotionState *shapeMotionState = NULL;
	btScalar mass(6);
	btVector3 inertia(1, 1, 1);
	
	m_dynamicsWorld->removeRigidBody(player1->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(player2->m_rigidbody);
	for(int q = 0; q < 36 ; q++)
	{
		if(fieldCollapse[q]) m_dynamicsWorld->removeRigidBody(field[q]->m_rigidbody);
		fieldCollapse[q] = true;
	}
	m_dynamicsWorld->removeRigidBody(Snowball1->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(Snowball2->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(Snowball3->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(Snowball4->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(Snowball5->m_rigidbody);
	m_dynamicsWorld->removeRigidBody(Snowball6->m_rigidbody);
	
	float posX = -12.5;
	float posZ = -12.5;
	for(int x = 0; x<36; x++)
	{
		shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(posX,-2,posZ)));
		mass = 0;
		field[x]->m_shape->calculateLocalInertia(mass,inertia);
		btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI3(mass, shapeMotionState, field[x]->m_shape, inertia);
		field[x]->m_rigidbody = new btRigidBody(shapeRigidBodyCI3);
		m_dynamicsWorld->addRigidBody(field[x]->m_rigidbody,1,1);
		
		posX+=5;
		if(posX == 17.5)
		{
			posX = -12.5;
			posZ+=5;
		}
	}
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),btVector3(10, 1, 0)));
	mass = 1;
	player1->m_shape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI(mass, shapeMotionState, player1->m_shape, inertia);
	player1->m_rigidbody = new btRigidBody(shapeRigidBodyCI);
	m_dynamicsWorld->addRigidBody(player1->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),btVector3(-10, 1, 0)));
	mass = 1;
	player2->m_shape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI2(mass, shapeMotionState, player2->m_shape, inertia);
	player2->m_rigidbody = new btRigidBody(shapeRigidBodyCI2);
	m_dynamicsWorld->addRigidBody(player2->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,10)));
	mass = 10;
	Snowball1->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI5(mass, shapeMotionState, Snowball1->m_shape, inertia);
	Snowball1->m_rigidbody = new btRigidBody(shapeRigidBodyCI5);
	m_dynamicsWorld->addRigidBody(Snowball1->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,-10)));
	mass = 10;
	Snowball2->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI6(mass, shapeMotionState, Snowball2->m_shape, inertia);
	Snowball2->m_rigidbody = new btRigidBody(shapeRigidBodyCI6);
	m_dynamicsWorld->addRigidBody(Snowball2->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,5)));
	mass = 10;
	Snowball3->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI7(mass, shapeMotionState, Snowball3->m_shape, inertia);
	Snowball3->m_rigidbody = new btRigidBody(shapeRigidBodyCI7);
	m_dynamicsWorld->addRigidBody(Snowball3->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,-5)));
	mass = 10;
	Snowball4->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI8(mass, shapeMotionState, Snowball4->m_shape, inertia);
	Snowball4->m_rigidbody = new btRigidBody(shapeRigidBodyCI8);
	m_dynamicsWorld->addRigidBody(Snowball4->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(5,1,0)));
	mass = 10;
	Snowball5->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI9(mass, shapeMotionState, Snowball5->m_shape, inertia);
	Snowball5->m_rigidbody = new btRigidBody(shapeRigidBodyCI9);
	m_dynamicsWorld->addRigidBody(Snowball5->m_rigidbody,1,1);
	
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(-5,1,0)));
	mass = 10;
	Snowball6->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI10(mass, shapeMotionState, Snowball6->m_shape, inertia);
	Snowball6->m_rigidbody = new btRigidBody(shapeRigidBodyCI10);
	m_dynamicsWorld->addRigidBody(Snowball6->m_rigidbody,1,1);
	
}
int PhysicsEngine::isOver()
{
	if(player1->m_rigidbody->getCenterOfMassPosition().getY() < -5)
	{
		reset();
		return 1;
	}
	else if(player2->m_rigidbody->getCenterOfMassPosition().getY() < -5)
	{
		reset();
		return 2;
	}
	return 0;
}
void PhysicsEngine::shrink()
{
	int q = rand() % 36;
	if(fieldCollapse[q])
	{
		fieldCollapse[q] = false;
		m_dynamicsWorld->removeRigidBody(field[q]->m_rigidbody);
	}
}
void PhysicsEngine::Render()
{
}

void PhysicsEngine::Launch()
{

}

void PhysicsEngine::createObjects()
{
	//Board ------------------------------------------------------------------------------------
	btDefaultMotionState *shapeMotionState = NULL;
	btScalar mass(0);
	btVector3 inertia(1, 1, 1);
	float posX = -12.5;
	float posZ = -12.5;
	for(int x = 0; x< 36; x++)
	{
		field[x] = new Object("../assets/plane.obj","../assets/cold-snow-white-60561.jpg",.35f);
		field[x]->m_physics = this;
		field[x]->m_shape = new btBoxShape(btVector3(2.5,1,2.5));
		shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(posX,-2,posZ)));
		mass = 0;
		field[x]->m_shape->calculateLocalInertia(mass,inertia);
		btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI3(mass, shapeMotionState, field[x]->m_shape, inertia);
		field[x]->m_rigidbody = new btRigidBody(shapeRigidBodyCI3);
		m_dynamicsWorld->addRigidBody(field[x]->m_rigidbody,1,1);
		posX+=5;
		
		if(posX == 17.5)
		{
			posX = -12.5;
			posZ+=5;
		}
		//std::cout<<posX<<"+"<<posZ<<std::endl;
	}
	
	//player 1
	player1 = new Object("../assets/snowman.obj" , "../assets/person.png",1.0f);
	player1->m_physics = this;
	player1->m_shape = new btBoxShape(btVector3(1,1,1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),btVector3(10, 1, 0)));
	mass = 1;
	player1->m_shape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI(mass, shapeMotionState, player1->m_shape, inertia);
	player1->m_rigidbody = new btRigidBody(shapeRigidBodyCI);
	m_dynamicsWorld->addRigidBody(player1->m_rigidbody, 1 , 1);
	
	//player 2
	player2 = new Object("../assets/snowman.obj" , "../assets/player2.jpg",1.0f);
	player2->m_physics = this;
	player2->m_shape = new btBoxShape(btVector3(1,1,1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1),btVector3(-10, 1, 0)));
	mass = 1;
	player2->m_shape->calculateLocalInertia(mass, inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI2(mass, shapeMotionState, player2->m_shape, inertia);
	player2->m_rigidbody = new btRigidBody(shapeRigidBodyCI2);
	m_dynamicsWorld->addRigidBody(player2->m_rigidbody, 1 , 1);
	
	//plane
	plane = new Object("../assets/plane.obj","../assets/ice_texture2999.jpg",10.0f);
	plane->m_physics = this;
	plane->m_shape = new btBoxShape(btVector3(100,1,100));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,-10,0)));
	
	mass = 0;
	plane->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI4(mass, shapeMotionState, plane->m_shape, inertia);
	plane->m_rigidbody = new btRigidBody(shapeRigidBodyCI4);
	m_dynamicsWorld->addRigidBody(plane->m_rigidbody,1,1);
	
	//snowballs
	Snowball1 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball1->m_physics = this;
	Snowball1->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,10)));
	mass = 10;
	Snowball1->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI5(mass, shapeMotionState, Snowball1->m_shape, inertia);
	Snowball1->m_rigidbody = new btRigidBody(shapeRigidBodyCI5);
	m_dynamicsWorld->addRigidBody(Snowball1->m_rigidbody,1,1);
	
	
	Snowball2 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball2->m_physics = this;
	Snowball2->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,-10)));
	mass = 10;
	Snowball2->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI6(mass, shapeMotionState, Snowball2->m_shape, inertia);
	Snowball2->m_rigidbody = new btRigidBody(shapeRigidBodyCI6);
	m_dynamicsWorld->addRigidBody(Snowball2->m_rigidbody,1,1);
	

	Snowball3 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball3->m_physics = this;
	Snowball3->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,5)));
	mass = 10;
	Snowball3->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI7(mass, shapeMotionState, Snowball3->m_shape, inertia);
	Snowball3->m_rigidbody = new btRigidBody(shapeRigidBodyCI7);
	m_dynamicsWorld->addRigidBody(Snowball3->m_rigidbody,1,1);
	

	Snowball4 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball4->m_physics = this;
	Snowball4->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,1,-5)));
	mass = 10;
	Snowball4->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI8(mass, shapeMotionState, Snowball4->m_shape, inertia);
	Snowball4->m_rigidbody = new btRigidBody(shapeRigidBodyCI8);
	m_dynamicsWorld->addRigidBody(Snowball4->m_rigidbody,1,1);
	

	Snowball5 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball5->m_physics = this;
	Snowball5->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(5,1,0)));
	mass = 10;
	Snowball5->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI9(mass, shapeMotionState, Snowball5->m_shape, inertia);
	Snowball5->m_rigidbody = new btRigidBody(shapeRigidBodyCI9);
	m_dynamicsWorld->addRigidBody(Snowball5->m_rigidbody,1,1);
	

	Snowball6 = new Object("../assets/sphere.obj","../assets/snowball.jpg",.8f);
	Snowball6->m_physics = this;
	Snowball6->m_shape = new btSphereShape(btScalar(1));
	shapeMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(-5,1,0)));
	mass = 10;
	Snowball6->m_shape->calculateLocalInertia(mass,inertia);
	btRigidBody::btRigidBodyConstructionInfo shapeRigidBodyCI10(mass, shapeMotionState, Snowball6->m_shape, inertia);
	Snowball6->m_rigidbody = new btRigidBody(shapeRigidBodyCI10);
	m_dynamicsWorld->addRigidBody(Snowball6->m_rigidbody,1,1);
	
}


