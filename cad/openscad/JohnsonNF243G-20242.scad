/*
	Openscad modell for Johnson NF243G-20242 Motor

	2015 by ChrisMicro

*/

$fn=100; // resolution
manuFactoringOffset=0.5;

motorDiameter   = manuFactoringOffset+24;
motorHeight     = manuFactoringOffset+18.5;
motorBodyLength = manuFactoringOffset+30.3;

axisLength      = 20;
axisTotalLength = 55;
axisDiameter    = 2;

frontRingDiameter = 6.2;
frontRingLength   = 1.2;

backRingDiameter  = manuFactoringOffset+8.5;
backRingLength    = manuFactoringOffset+1.7+.5;

ringInlayOffset=2; // this is only to prevent rendering errors
 
motor();

function get_motorDiameter()=motorDiameter;
function get_motorHeight()=motorHeight;

axisShift=axisTotalLength-(motorBodyLength+frontRingLength+axisLength);


module motor()
{
	// front ring
	translate([motorBodyLength/2-ringInlayOffset,0,0]) rotate([0,90,0])	
		cylinder(h = frontRingLength+ringInlayOffset, r = frontRingDiameter/2, center = false);

	// back ring
	translate([-motorBodyLength/2-backRingLength,0,0]) rotate([0,90,0])	
		cylinder(h = backRingLength+ringInlayOffset, r = backRingDiameter/2, center = false);

	// axis
	color("grey") translate([-motorBodyLength/2-axisShift,0,0]) rotate([0,90,0])	
		cylinder(h = axisTotalLength, r = axisDiameter/2, center = false);

	// body
	color("grey") intersection()
	{
		translate([-motorBodyLength/2,0,0]) rotate([0,90,0])	
			cylinder(h = motorBodyLength, r = motorDiameter/2, center = false);
			cube(size = [motorBodyLength,motorDiameter,motorHeight], center = true);
	}
}
