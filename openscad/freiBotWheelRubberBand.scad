/*
	freiBot wheel with pulley and rubber band groove

	2015 by ChrisMicro
*/

use <pulley.scad>

$fn=100;

wheelInnerDiameter 	= 30;
wheelOuterDiameter 	= 40;
wheelThickness     	= 4;

wheelRimDeepnes       = 0.8; // Rillentiefe
wheelRimBootomWith    = 1.2; // Rillenbreite unten
wheelRimTopWith       = 3; // Rillenbreite oben

pulleyInnerDiameter 	= wheelInnerDiameter;
pulleyOuterDiameter 	= 35;
pulleyThickness     	= 8;

pulleyRimDeepnes      = 2; // Rillentiefe
pulleyRimBootomWith   = 2; // Rillenbreite unten
pulleyRimTopWith      = 6; // Rillenbreite oben

hubLength           	= 14;
hubHoleDiameter     	= 3;
hubDiameter         	= 6;

// wheel
pulley(	wheelInnerDiameter,
			wheelOuterDiameter,
			wheelThickness,
			wheelRimDeepnes,
			wheelRimBootomWith,
			wheelRimTopWith	);

// steep border for rubber 
washer((wheelThickness-wheelRimBootomWith)/2,wheelInnerDiameter,wheelOuterDiameter);

// pulley
translate([0,0,wheelThickness])
	pulley(	pulleyInnerDiameter,
				pulleyOuterDiameter,
				pulleyThickness,
				pulleyRimDeepnes,
				pulleyRimBootomWith,
				pulleyRimTopWith	);
// hub
hub(hubLength,hubHoleDiameter,hubDiameter,wheelInnerDiameter);

module hub(thickness,innerDiameter,outerDiameter,inner_d)
{
	inner_r=inner_d/2;
	difference()
	{
		union()
		{
			cylinder(thickness,outerDiameter/2,outerDiameter/2);
			cube([inner_r,2,hubLength-2]);
			rotate([0, 0,  90]) cube([inner_r,2,hubLength-2]);
			rotate([0, 0, 180]) cube([inner_r,2,hubLength-2]);
			rotate([0, 0, 270]) cube([inner_r,2,hubLength-2]);
		}
		// hole
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}