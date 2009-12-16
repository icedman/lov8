// Example: Avalanche of LOVE

// Contains all the balls.
balls = Array();

// Contains all the boxes. (Terrain)
boxes = Array();

dragBall = 0;

//print = love.system.print;

function onContact(c)
{
    print(c);
}

function load()
{
    // Fat lines.
    love.graphics.setLineWidth(2)

    // Load images.
    images = {
        green: love.graphics.newImage("green_ball.png"),
        big_love: love.graphics.newImage("big_love_ball.png"),
    love: love.graphics.newImage("love_ball.png"),
    }
    
    // Image / radius pairs.
    balldefs = {
    1:{ i: images.green, 	r: 32 },
    2:{ i: images.big_love, r: 46 },
    3:{ i: images.love, 	r: 28 },
    }
    
    // Create the world.
    world = love.physics.newWorld(2000, 2000)
    world.setGravity(0, 50)
    world.callback = onContact;
 
    // Create ground body.
    ground = love.physics.newBody(world, 0, 0, 0)
    
    // Add all the balls.
    addball(balldefs[1], 50)	// Add 50 green.
    addball(balldefs[2], 5)		// Add 5 big.
    addball(balldefs[3], 25)	// Add 25 pink.

    // This generates the terrain.
    for(var i = 0; i<10; i++)
    {
        addbox(i*50, i*50+100)
    }
    
    love.graphics.setColor(love.graphics.newColor(255, 255, 255, 255));
}

function update(dt)
{
    if (dragBall != 0)
    {
        dragBall.b.setPosition(love.mouse.getX(), love.mouse.getY());
        dragBall.b.setVelocity(0, 0);
    }
    
    // Update the world.
    world.update(dt)
	
    // Check whether we need to reset some balls.
    // When they move out of the screen, they
    // respawn above the screen.
    for(var i in balls)
    {
        var pos = balls[i].b.getPosition()
        if (pos.x > 850 || pos.y > 650 || pos.x < -5)
            balls[i].b.setPosition(0 + (Math.random() * 400), (-Math.random() * 1500))
    }
}

function draw()
{
    // Draw all the balls.
    for(var i in balls)
    {
	   if (balls[i] == dragBall)
		  continue;
       love.graphics.drawImage(balls[i].i, balls[i].b.getX(), balls[i].b.getY(), balls[i].b.getAngle())
    }
    
    // Draw all the boxes.
    for(var i in boxes)
    {
        love.graphics.polygon(love.draw_line, boxes[i].s.getPoints())
    }
	
	if (dragBall != 0)
		love.graphics.drawImage(dragBall.i, dragBall.b.getX(), dragBall.b.getY(), dragBall.b.getAngle())
}

// Adds a static box.
function addbox(x, y)
{
    var t = {}
    t.b = ground
    t.s = love.physics.newRectangleShape(t.b, x, y, 50, 50)
    boxes.push(t);
}

// Adds X balls.
function addball(def, num)
{
    for(var i = 0; i<num; i++)
    {
		var x = 0 + (Math.random() * 400);
		var y = 100 + (-Math.random() * 1500);

		var t = {}
		t.b = love.physics.newBody(world, x, y)
		t.s = love.physics.newCircleShape(t.b, def.r)
		t.i = def.i
		t.b.setMassFromShapes()
		balls.push(t);
    }
}

function keypressed(key)
{
	if (key == love.key_escape)
		love.system.exit();
}

function mousepressed(x, y, button)
{
    for(var i in balls)
    {
		if (balls[i].s.testPoint(x, y))
		{
			dragBall = balls[i];
			return;
		}
    }
    dragBall = 0;
}

function mousereleased(x, y, button)
{
	dragBall = 0;
}
