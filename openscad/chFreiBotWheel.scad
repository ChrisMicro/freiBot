/*
	freiBot Pneu
	robot wheel for freiBot
	2015 by stochri
*/

$fn = 50;

ballBearingDiameter=22;
wheelDiameter=32;
nutBreite=1.5;
nutTiefe=2;
nutEntfernung=2;

schlauchdicke=wheelDiameter-ballBearingDiameter;

d1=1;
d2=1;

// reifen 
translate([0,0,schlauchdicke/4])
	torus(ballBearingDiameter,wheelDiameter);

// auffüllung rad reifen
translate([0,0,0])
	ring(schlauchdicke/4+d1,ballBearingDiameter,wheelDiameter-schlauchdicke/2);

// innenring der nut
translate([0,0,-nutEntfernung])
	ring(schlauchdicke/2+d1,ballBearingDiameter,ballBearingDiameter+d2+nutTiefe);

// nut für gummiantrieb
translate([0,0,-nutEntfernung-nutBreite])
	ring(nutBreite,ballBearingDiameter,ballBearingDiameter+d2);

// aussenring der nut
translate([0,0,-nutEntfernung-nutBreite-d1])
	ring(d1,ballBearingDiameter,ballBearingDiameter+d2+nutTiefe);


module ring(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(thickness,outerDiameter/2,outerDiameter/2);
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}

module torus(inner,outer)
{
	rotate_extrude(convexity = 10)
	translate([outer/2-(outer/2-inner/2)/2, 0, 0])
		circle(r = (outer/2-inner/2)/2); 
}