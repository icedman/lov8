/*
* LOVE: Totally Awesome 2D Gaming.
* Website: http://love.sourceforge.net
* Licence: ZLIB/libpng
* Copyright (c) 2006-2008 LOVE Development Team
* 
* @author Anders Ruud
* @date 2008-08-12
*/
#ifndef LOVE_BOX2D_MOUSE_JOINT_H
#define LOVE_BOX2D_MOUSE_JOINT_H

// Module
#include "Joint.h"

namespace love_box2d
{
	/**
	* The MouseJoint is a joint type that 
	* is suitable for controlling objects with the mouse.
	*
	* One end is anchored in the dynamic body, and the other id
	* anchor to a static ground body. The anchor offset can then be
	* moved to the current mouse position.
	**/
	class MouseJoint : public Joint
	{
	private:
		// The Box2D MouseJoint object.
		b2MouseJoint * joint;
	public:

		/**
		* Creates a MouseJoint which connects body1 to the target point.
		**/
		MouseJoint(boost::shared_ptr<Body> body1, b2MouseJointDef * def);

		virtual ~MouseJoint();

		/**
		* Sets the target of anchor2. (You usually want
		* to set this to the current mouse.)
		**/
		void setTarget(float x, float y);

		/**
		* Gets the current anchor2 target.
		**/
		int getTarget(lua_State * L);

		Vec2df getTarget();

		/**
		* Sets the maximum constraint force that can be exerted
		* to move the candidate body.
		**/
		void setMaxForce(float force);

		/**
		* Gets the maximum constraint force that can be exerted
		* to move the candidate body.
		**/
		float getMaxForce() const;
	};

	typedef boost::shared_ptr<MouseJoint> pMouseJoint;

} // love_box2d

#endif // LOVE_BOX2D_MOUSE_JOINT_H
