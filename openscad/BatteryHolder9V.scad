/*

	holder for 9V block battery

	2015 by ChrisMicro
*/

batteryLength=45;
batteryWidth=26;
batterHeight=17;

wallThickness=1;
wallHeight=15;

BatteryClipThickness=6;

manuFactoringOffset=0.5;


totalLength=batteryLength+BatteryClipThickness;

difference()
{
	// housing
	cube([totalLength+2*wallThickness,batteryWidth+2*wallThickness,wallHeight+2*wallThickness]);
	// battery
	translate([wallThickness-manuFactoringOffset/2,wallThickness-manuFactoringOffset/2,wallThickness*2])
		cube([totalLength+manuFactoringOffset,batteryWidth+manuFactoringOffset,batterHeight+manuFactoringOffset]);
	// batteryClip
translate([wallThickness*2,0,wallThickness*2])
		cube([BatteryClipThickness,batteryLength+2*wallThickness,batterHeight+2*wallThickness]);
}