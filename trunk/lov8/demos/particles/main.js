/*
-------------------------------------------------
-- LOVE: ParticleSystem demo.
-- Website: http.//love.sourceforge.net
-- Licence: ZLIB/libpng
-- Copyright (c) 2006-2008 LOVE Development Team
-------------------------------------------------
*/


systems = new Array();
current = 1;

function load()
{
    var part1 = love.graphics.newImage("part1.png");
    var cloud = love.graphics.newImage("cloud.png");
    var square = love.graphics.newImage("square.png");
    //var font = love.graphics.newFont(love.default_font)

    love.graphics.setFont(love.default_font);
    love.graphics.setColor(200, 200, 200);
		
    var clr = function(r, g, b, a)
    {
		return love.graphics.newColor(r, g, b, a);
    };

    var p = love.graphics.newParticleSystem(part1, 1000);
    p.setEmissionRate(100)
    p.setSpeed(300, 400)
    p.setGravity(0)
    p.setSize(2, 1)
    p.setColor(clr(255, 255, 255, 255), clr(58, 128, 255, 0))
    p.setPosition(400, 300)
    p.setLifetime(1)
    p.setParticleLife(1)
    p.setDirection(0)
    p.setSpread(360)
    p.setRadialAcceleration(-2000)
    p.setTangentialAcceleration(1000)
    p.stop()
    systems.push(p);

    p = love.graphics.newParticleSystem(cloud, 1000);
    p.setEmissionRate(100)
    p.setSpeed(200, 250)
    p.setGravity(100, 200)
    p.setSize(1, 1)
    p.setColor(clr(16, 81, 229, 255), clr(176, 16, 229, 0))
    p.setPosition(400, 300)
    p.setLifetime(1)
    p.setParticleLife(1)
    p.setDirection(180)
    p.setSpread(20)
    // --p.setRadialAcceleration(-200, -300)
    p.stop()
    systems.push(p);

    p = love.graphics.newParticleSystem(square, 1000);
    p.setEmissionRate(60)
    p.setSpeed(200, 250)
    p.setGravity(100, 200)
    p.setSize(1, 2)
    p.setColor(clr(240, 3, 176, 255), clr(204, 240, 3, 0))
    p.setPosition(400, 300)
    p.setLifetime(1)
    p.setParticleLife(2)
    p.setDirection(90)
    p.setSpread(0)
    p.setSpin(300, 800)
    p.stop()
    systems.push(p);

    p = love.graphics.newParticleSystem(part1, 1000);
    p.setEmissionRate(1000)
    p.setSpeed(300, 400)
    p.setSize(2, 1)
    p.setColor(clr(220, 105, 20, 255), clr(194, 30, 18, 0))
    p.setPosition(400, 300)
    p.setLifetime(0.1)
    p.setParticleLife(0.2)
    p.setDirection(0)
    p.setSpread(360)
    p.setTangentialAcceleration(1000)
    p.setRadialAcceleration(-2000)
    p.stop()
    systems.push(p);

    p = love.graphics.newParticleSystem(part1, 1000);
    p.setEmissionRate(200)
    p.setSpeed(300, 400)
    p.setSize(1, 2)
    p.setColor(clr(255, 255, 255, 255), clr(255, 128, 128, 0))
    p.setPosition(400, 300)
    p.setLifetime(1)
    p.setParticleLife(2)
    p.setDirection(0)
    p.setSpread(360)
    p.setTangentialAcceleration(2000)
    p.setRadialAcceleration(-8000)
    p.stop()
    systems.push(p);

}

direction = 0;

function update(dt)
{
	
    if (love.mouse.isDown(love.mouse_left))
    {
        systems[current].setPosition(love.mouse.getX(), love.mouse.getY())
        systems[current].start()
    }

    if (love.keyboard.isDown(love.key_d))
    {
        systems[current].setDirection(direction)
        //direction = math.mod(direction + 90 * dt, 360)
    }

    if (love.keyboard.isDown(love.key_r))
    {
        love.system.restart()
    }

    systems[current].update(dt)
}

function draw()
{
    love.graphics.setColorMode(love.color_modulate)
    love.graphics.setBlendMode(love.blend_additive)
    love.graphics.drawParticleSystem(systems[current], 0, 0)
    love.graphics.drawText("System: [" + current + "/"+systems.length+"] - " + systems[current].count() + " particles.", 30, 570);
    love.graphics.drawText("Click: spawn particles. Mousewheel: change system.", 30, 530);
    love.graphics.drawText("Press escape to exit.", 30, 550);
    
    love.graphics.drawText(">" + love.timer.getFPS(), 30, 30);
}

function mousepressed(x, y, button)
{
    if (button == love.mouse_wheelup)
    {
        current++;
        if (current >= systems.length)
            current = 0;
    }

    if (button == love.mouse_wheeldown)
    {
        current--;
        if (current < 0)
            current = systems.length - 1;
    }
}

function keypressed(key)
{
    if (key == love.key_escape)
    {
        love.system.exit()
    }
    
    if (key == love.key_backspace)
    {
		love.system.print("restart");
		love.system.restart()
    }
}
