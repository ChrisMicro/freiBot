/*

	robo base plate for two axis

	( 4 wheels )

	2015 by ChrisMicro

*/

$fn=100; // resolution

basePlateLength=80/2;
basePlateThickness=3;

axisLength=170;
axisDiameter=3.2;
outerDiamter=7;

wheelWidth=20;
wheelDiameter=50;
wheelHolderWidth=5;



yClearing=basePlateLength-wheelDiameter/2*1.2;

axisBearings();
translate([0,basePlateLength*2,0])mirror([0,1,0])axisBearings();

module axisBearings()
{
	difference()
	{
		allBearings();
	
		translate([wheelHolderWidth,-yClearing,0])
			cube(size = [wheelWidth,basePlateLength,wheelDiameter/2], center = false);
	
		translate([axisLength-wheelHolderWidth-wheelWidth,-yClearing,0])
			cube(size = [wheelWidth,basePlateLength,wheelDiameter/2], center = false);

		translate([axisLength/4,-yClearing,0])
			cube(size = [axisLength/2,basePlateLength,wheelDiameter/2], center = false);
	}
}

module allBearings()
{
	translate([0,axisDiameter/2,basePlateThickness+axisDiameter/2])rotate([0,90,0])
		bearing(axisLength,axisDiameter,outerDiamter);

	cube(size = [axisLength,basePlateLength,basePlateThickness], center = false);
}

module bearing(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(thickness,outerDiameter/2,outerDiameter/2);
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}