/*
	Openscat modell for Johnson NF243G-20242 Motor

	2015 by ChrisMicro

*/

//$fn=100; // resolution

motorDiameter   = 23.5;
motorHeight     = 18.5;
motorBodyLength = 30.3;

axisLength      = 20;
axisTotalLength = 55;
axisDiameter    = 2;

frontRingDiameter = 6.2;
frontRingLength   = 1.2;

backRingDiameter  = 8.5;
backRingLength    = 1.7;

motor();



axisShift=axisTotalLength-(motorBodyLength+frontRingLength+axisLength);


module motor()
{
	// front ring
	translate([motorBodyLength/2,0,0]) rotate([0,90,0])	
	cylinder(h = frontRingLength, r = frontRingDiameter/2, center = false);

	// back ring
	translate([-motorBodyLength/2-backRingLength,0,0]) rotate([0,90,0])	
	cylinder(h = backRingLength, r = backRingDiameter/2, center = false);

	// axis
	color("grey") translate([-motorBodyLength/2-axisShift,0,0]) rotate([0,90,0])	
	cylinder(h = axisTotalLength, r = axisDiameter/2, center = false);

	// body
	color("grey") intersection()
	{
		translate([-motorBodyLength/2,0,0]) rotate([0,90,0])	
		cylinder(h = motorBodyLength, r = motorDiameter/2, center = false);
		//motorZylinder();
		cube(size = [motorBodyLength,motorDiameter,motorHeight], center = true);
	}
}

