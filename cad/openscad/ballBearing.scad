/*
	freiBot ball bearing
	inline skate ball bearing for freiBot
	2015 by stochri
*/

// bb: ball bearing

bbHole=8;
bbDiameter=22;
bbThickness=7;


ring(bbThickness,bbHole,bbDiameter);

module ring(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(thickness,outerDiameter/2,outerDiameter/2);
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}