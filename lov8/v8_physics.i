#include "../../src/box2d/love_box2d.h"

namespace love_box2d

class Vec2df { [struct=1]
	double x;
	double y;
}

class Vec2dfList { [struct=1,array=1]
	Vec2df items;
	int count;
}

class pWorld { [className=World]
	void update( double dt )   	 Updates the state of the objects in the World.
		
	void setGravity( double x, double y ) 	Sets the gravity.
	Vec2df getGravity( ) 	Gets the gravity.
		
	//setCallback( f ) 	Sets the collision callback.
	//getCallback( ) 	Gets the collision callback.
		
	int getBodyCount( ) 	Gets the number of Bodies in the World.
	int getJointCount( ) 	Gets the number of joints in the World. 
}

class pContact { [className=Contact]
	double getFriction( )   	 Gets the mixed friction between the two shapes.
	double getRestitution( ) 	Gets the mixed restitution between the two shapes.
		
	double getSeparation( ) 	Gets the separation of the two shapes.
	Vec2df getPosition( ) 	Gets the position of the Contact point.
	Vec2df getVelocity( ) 	Gets the velocity at the Contact point.
	Vec2df getNormal( ) 	Gets the Contact normal. 
}

class pBody { [className=Body]
	double getX( )   	 Gets the x-component of the position.
	double getY( ) 	Gets the y-component of the position.
	Vec2df getPosition( ) 	Gets the position of the Body.
	Vec2df getVelocity( ) 	Gets the velocity of the Body.
		
	double getAngle( ) 	Gets the current angle of the Body.
	double getSpin( ) 	Gets the current spin of the Body.
		
	double getMass( ) 	Gets the mass of Body.
	double getInertia( ) 	Gets the inertia of Body.
		
	double getDamping( ) 	Gets linear damping.
	double getAngularDamping( ) 	Gets angular damping.
		
	Vec2df getWorldCenter( ) 	Gets the center of mass in world coordinates.
	Vec2df getLocalCenter( ) 	Gets the center of mass in local coordinates.
	Vec2df getWorldPoint( double x, double y ) 	Transforms a point from local coordinates to world coordinates.
	Vec2df getWorldVector( double x, double y ) 	Transforms a vector from local coordinates to world coordinates.
	Vec2df getLocalPoint( double x, double y ) 	Transforms a point from world coordinates to local coordinates.
	Vec2df getLocalVector( double x, double y ) 	Transforms a vector from world coordinates to local coordinates.
	Vec2df getVelocityWorldPoint( double x, double y ) 	Gets the velocity on the Body for the given world point.
	Vec2df getVelocityLocalPoint( double x, double y ) 	Gets the velocity on the Body for the given local point.
		
	void applyImpulse( double jx, double jy ) 	Applies an impulse to the Body.
	void applyImpulse( double jx, double jy, double rx, double ry ) 	Applies an impulse to the Body with an offset.
	void applyForce( double fx, double fy ) 	Applies force to the Body.
	void applyForce( double x, double y, double rx, double ry ) 	Applies force to the Body with an offset.
	void applyTorque( double t ) 	Applies torque to the Body.
		
	void setX( double x ) 	Sets the x-component of the position.
	void setY( double y ) 	Sets the y-component of the position.
	void setPosition( double x, double y ) 	Sets the position of the Body.
	void setVelocity( double x, double y ) 	Sets the velocity of the Body.
		
	void setAngle( double angle ) 	Sets the angle of the Body.
	void setSpin( double spin ) 	Sets the spin of the Body.
		
	void setMassFromShapes( ) 	Sets mass properties from attatched shapes.
	void setMass( double x, double y, double m, double i ) 	Sets mass properies directly.
		
	void setDamping( double damping ) 	Sets the linear damping of the Body.
	void setAngularDamping( double amping ) 	Sets the angular damping of the Body.
		
	bool isBullet( ) 	Checks whether this Body should be treated as a bullet.
	void setBullet( bool bullet ) 	Sets whether this Body should be treated as a Bullet.
		
	bool isStatic( ) 	Checks whether this Body is static.
	bool isDynamic( ) 	Checks whether this Body is dynamic.
	bool isFrozen( ) 	Checks whether this Body is frozen.
	bool isSleeping( ) 	Checks whether this Body is sleeping
		
	void setAllowSleep( bool allow ) 	Allows or disallows sleeping for this Body.
	void setSleep( bool  sleep ) 	Puts a Body to sleep or wakes it up.
		
	// void destroy( ) 	Explicitly destroys the Body. 
}

class pCircleShape { [className=CircleShape]
	int getType( )   	 Gets an integer representing the shape type.
		
	double getFriction( ) 	Gets the friction of this shape.
	double getRestitution( ) 	Gets the restitution of this shape. [function=getRestituion]
		
	int getCategoryBits( ) 	Gets the category bits of the shape.
	//int getCategory( ) 	Gets the categories this shape is a member of.
	int getMaskBits( ) 	Gets the mask bits of the shape.
	//int getMask( ) 	Gets which categories this shape should collide with.
		
	//getData( ) 	Gets the data set with setData.
	bool isSensor( ) 	Checks whether this shape acts as a sensor or not
		
	void setFriction( double friction ) 	Sets the friction of the shape.
	void setRestitution( double restitution ) 	Sets the restitution of the shape.
		
	void setCategoryBits( int bits ) 	Sets the category bits of the shape.
	//setCategory( ... ) 	Sets the categories this shape is a member of.
	void setMaskBits( int bits ) 	Sets the mask bits of the shape.
	//setMask( ... ) 	Sets which categories this shape should collide with.
		
	//setData( any ) 	Sets data to be passed to the collision callback.
	void setSensor( bool sensor ) 	Sets whether this shape should act as a sensor.
		
	//getBoundingBox( ) 	Gets the bounding box of the shape.
	bool testPoint( double x, double y ) 	Checks whether a point lies inside the shape.
	//bool testSegment( double x1, double y1, double x2, double y2 ) 	Checks whether a line segment intersects a shape.
		
	double getRadius( ) 	Gets the radius of the CircleShape.
		
	//destroy( ) 	Explicitly destroys the CircleShape. 
}

class pPolygonShape { [className=PolygonShape]
	int getType( )   	 Gets an integer representing the shape type.
		
	double getFriction( ) 	Gets the friction of this shape.
	double getRestitution( ) 	Gets the restitution of this shape. [function=getRestituion]
		
	//getCategoryBits( ) 	Gets the category bits of the shape.
	//getCategory( ) 	Gets the categories this shape is a member of.
	//getMaskBits( ) 	Gets the mask bits of the shape.
	//getMask( ) 	Gets which categories this shape should collide with.
		
	//getData( ) 	Gets the data set with setData.
	bool isSensor( ) 	Checks whether this shape acts as a sensor or not
		
	void setFriction( double friction ) 	Sets the friction of the shape.
	void setRestitution( double restitution ) 	Sets the restitution of the shape.
		
	//setCategoryBits( bits ) 	Sets the category bits of the shape.
	//setCategory( ... ) 	Sets the categories this shape is a member of.
	//setMaskBits( bits ) 	Sets the mask bits of the shape.
	//setMask( ... ) 	Sets which categories this shape should collide with.
		
	//setData( any ) 	Sets data to be passed to the collision callback.
	void setSensor( bool sensor ) 	Sets whether this shape should act as a sensor.
		
	//getBoundingBox( ) 	Gets the bounding box of the shape.
	bool testPoint( double x, double y ) 	Checks whether a point lies inside the shape.
	//testSegment( x1, y1, x2, y2 ) 	Checks whether a line segment intersects a shape.
		
	Vec2dfList getPoints( ) 	Gets the transformed points of the PolygonShape. [list=1]
		
	//destroy( ) 	Explicitly destroys the PolygonShape. 
}

class pDistanceJoint { [className=DistanceJoint]
	double getLength( )   	 Gets the equilibrium distance between the two Bodies.
	double getFrequency( ) 	Gets the response speed.
	double getDamping( ) 	Gets the damping ratio.
		
	void setLength( double length ) 	Sets the equilibrium distance between the two Bodies.
	void setFrequency( double hz ) 	Sets the response speed.
	void setDamping( double d ) 	Sets the damping ratio.
		
	//destroy( ) 	Explicitly destroys the DistanceJoint. 
}

class pRevoluteJoint { [className=RevoluteJoint]
	double getAngle( )   	 Get the current joint angle.
	double getSpeed( ) 	Get the current joint angle speed.
		
	bool isMotorEnabled( ) 	Checks whether the motor is enabled.
	double getMaxMotorTorque( ) 	Gets the maximum motor torque.
	double getMotorSpeed( ) 	Gets the motor speed.
	double getMotorTorque( ) 	Get the current motor torque.
		
	bool isLimitsEnabled( ) 	Checks whether limits are enabled.
	double getLowerLimit( ) 	Gets the lower limit.
	double getUpperLimit( ) 	Gets the upper limit.
	//getLimits( ) 	Gets the joint limits.
		
	void setMotorEnabled( bool motor ) 	Enables/disables the joint motor.
	void setMaxMotorTorque( double torque ) 	Set the maximum motor torque.
	void setMotorSpeed( double speed ) 	Sets the motor speed.
		
	void setLimitsEnabled( bool limit ) 	Enables/disables the joint limit.
	void setUpperLimit( double upper ) 	Sets the upper limit.
	void setLowerLimit( double lower ) 	Sets the lower limit.
	void setLimits( double lower, double upper ) 	Sets the limits.
		
	//destroy( ) 	Explicitly destroys the RevoluteJoint. 
}

class pPrismaticJoint { [className=PrismaticJoint]
	double getTranslation( )   	 Get the current joint translation.
	double getSpeed( ) 	Get the current joint angle speed.
		
	bool isMotorEnabled( ) 	Checks whether the motor is enabled.
	double getMaxMotorForce( ) 	Gets the maximum motor force.
	double getMotorSpeed( ) 	Gets the motor speed.
	double getMotorForce( ) 	Get the current motor force.
		
	bool isLimitsEnabled( ) 	Checks whether limits are enabled.
	double getLowerLimit( ) 	Gets the lower limit.
	double getUpperLimit( ) 	Gets the upper limit.
	//getLimits( ) 	Gets the joint limits.
		
	void setMotorEnabled( bool motor ) 	Enables/disables the joint motor.
	void setMaxMotorForce( double force ) 	Set the maximum motor force.
	void setMotorSpeed( double speed ) 	Sets the motor speed.
		
	void setLimitsEnabled( bool limit ) 	Enables/disables the joint limit.
	void setUpperLimit( double upper ) 	Sets the upper limit.
	void setLowerLimit( double lower ) 	Sets the lower limit.
	void setLimits( double lower, double upper ) 	Sets the limits.
		
	//destroy( ) 	Explicitly destroys the PrismaticJoint. 
}

class pMouseJoint { [className=MouseJoint]
	Vec2df getTarget( )   	 Gets the target point.
	double getMaxForce( ) 	Gets the max allowed force on the Body.
		
	void setTarget( double x, double y ) 	Sets the target point.
	void setMaxForce( double force ) 	Gets the max allowed force on the Body.
		
	// destroy( ) 	Explicitly destroys the MouseJoint. 
}

static class love_box2d { [className=physics]
	pWorld newWorld( double w, double h )   	 Creates a new World.
	pWorld newWorld( double lx, double ly, double ux, double uy, double gx, double gy, bool sleep ) 	Creates a new World.
		
	pBody newBody( pWorld world ) 	Creates a new Body.
	pBody newBody( pWorld world, double x, double y ) 	Creates a new Body with some position.
	pBody newBody( pWorld world, double x, double y, double m ) 	Creates a new Body with some position and mass.
		
	pCircleShape newCircleShape( pBody body, double radius ) 	Creates a new CircleShape.
	pCircleShape newCircleShape( pBody body, double x, double y, double radius ) 	Creates a new CircleShape with an offset.
		
	pPolygonShape newRectangleShape( pBody body, double w, double h ) 	Creates a rectangle.
	pPolygonShape newRectangleShape( pBody body, double x, double y, double w, double h ) 	Creates a new rectangle with an offset.
	pPolygonShape newRectangleShape( pBody body, double x, double y, double w, double h, double angle ) 	Creates a new rectangle with offset and orientation.
		
	//newPolygonShape( body, ... ) 	Creates a new PolygonShape.
		
	pDistanceJoint newDistanceJoint( pBody body1, pBody body2, double x1, double y1, double x2, double y2 ) 	Creates a new DistanceJoint.
	pRevoluteJoint newRevoluteJoint( pBody body1, pBody body2, double x, double y ) 	Creates a new RevoluteJoint.
	pPrismaticJoint newPrismaticJoint( pBody body1, pBody body2, double x, double y, double ax, double ay ) 	Creates a new PrismaticJoint.
	pMouseJoint newMouseJoint( pBody body, double x, double y ) 	Creates a new MouseJoint
}