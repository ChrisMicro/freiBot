/*
	freiBot washer

	2015 by stochri
*/


$fn = 50;

axLength=1;
axDiameter=8;
axHole=6;

ring(axLength,axHole,axDiameter);

module ring(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(thickness,outerDiameter/2,outerDiameter/2);
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}