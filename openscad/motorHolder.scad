/*
	motor holder for JohnsonNF243G-20242 motor
	2015 by ChrisMicro
*/

use <JohnsonNF243G-20242.scad>

MotorholderLength = 33;
MotorholderHeight = 10;
MotorHolderWitdh  = 25;

basePlateLength   = MotorholderLength;
basePlateWidth    = 40;
basePlateHeight   = 3;


drilldiameter = 3.3/2;
drillPositionBorderDistance = 5 ;

motorDiameter   = 23.5;
motorHeight     = 18.5;

motorHolder();


basePlateOffset=-MotorholderHeight/2-basePlateHeight/2;

// drilling coordinates
x0=basePlateLength/2-drillPositionBorderDistance;
y0=MotorHolderWitdh-drillPositionBorderDistance-drilldiameter*2;

x1=-basePlateLength/2+drillPositionBorderDistance;
y1=(MotorHolderWitdh-drillPositionBorderDistance-drilldiameter*2);

x2=-basePlateLength/2+drillPositionBorderDistance;
y2=-(MotorHolderWitdh-drillPositionBorderDistance-drilldiameter*2);

x3=basePlateLength/2-drillPositionBorderDistance;
y3=-(MotorHolderWitdh-drillPositionBorderDistance-drilldiameter*2);

module motorHolderbasePlate()
{
	difference()
	{
		// baseplate
		color("silver") translate([0,0,basePlateOffset]) 		
			cube(size = [basePlateLength,basePlateWidth,basePlateHeight], center = true);

		// baseplate drillings
		union()
		{
			// drill 0
			translate([x0,y0,basePlateOffset-basePlateHeight/2]) 		
				cylinder(basePlateHeight,drilldiameter,drilldiameter);

			// drill 1
			translate([x1,y1,basePlateOffset-basePlateHeight/2]) 		
				cylinder(basePlateHeight,drilldiameter,drilldiameter);

			// drill 2
			translate([x2,y2,basePlateOffset-basePlateHeight/2]) 		
				cylinder(basePlateHeight,drilldiameter,drilldiameter);

			// drill 3
			translate([x3,y3,basePlateOffset-basePlateHeight/2]) 		
				cylinder(basePlateHeight,drilldiameter,drilldiameter);
		}
	}
}
	
//basePlate();

module motorHolder()
{
	translate([basePlateLength/2,basePlateWidth/2,MotorholderHeight/2+basePlateHeight])
	union()
	{	
		motorHolderbasePlate();
		
		// motor holder main
		difference()
		{
			cube(size = [MotorholderLength,MotorHolderWitdh,MotorholderHeight], center = true);
			translate([0,0,motorHeight/2-MotorholderHeight/2]) 
				motor();
		}
	}
}