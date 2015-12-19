/*

	robo axis bearings

	2015 by ChrisMicro

*/

//$fn=100; // resolution


basePlateLength=40;
basePlateThickness=3;

axisLength=120;
axisDiameter=3.2;
outerDiamter=7;

wheelWidth=12;
wheelDiameter=30;
wheelHolderWidth=5;

axisBearings();

module axisBearings()
{
	difference()
	{
		allBearings();
	
		translate([wheelHolderWidth,-wheelDiameter/2*0.8,0])
			cube(size = [wheelWidth,basePlateLength,wheelDiameter/2], center = false);
	
		translate([axisLength-wheelHolderWidth-wheelWidth,-wheelDiameter/2*0.8,0])
			cube(size = [wheelWidth,basePlateLength,wheelDiameter/2], center = false);

		translate([axisLength/4,-wheelDiameter/2*0.8,0])
			cube(size = [axisLength/2,basePlateLength,wheelDiameter/2], center = false);
	}
}


module allBearings()
{
	//translate([0,axisDiameter/2,(outerDiamter-axisDiameter)])rotate([0,90,0])
	translate([0,axisDiameter/2,basePlateThickness+axisDiameter/2])rotate([0,90,0])
		bearing(axisLength,axisDiameter,outerDiamter);
	
	//cube(size = [axisLength,basePlateLength,(outerDiamter-axisDiameter)/2], center = false);
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