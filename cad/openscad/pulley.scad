/* 

	simple pulley

	2015 by ChrisMicro

*/
$fn=100;

pulleyInnerDiameter = 37;
pulleyOuterDiameter = 40;
pulleyThickness     = 4;

rimDeepnes          = 0.7; // Rillentiefe
rimBootomWith       = 1; // Rillenbreite unten
rimTopWith          = 3; // Rillenbreite oben


pulley(	pulleyInnerDiameter,
					pulleyOuterDiameter,
					pulleyThickness,
					rimDeepnes,
					rimBootomWith,
					rimTopWith	);

module pulley(	pulleyInnerDiameter,
					pulleyOuterDiameter,
					pulleyThickness,
					rimDeepnes,
					rimBootomWith,
					rimTopWith	)
{
	halfPulley(pulleyInnerDiameter,pulleyOuterDiameter,pulleyThickness,rimDeepnes,rimBootomWith,rimTopWith);
	translate([0,0,pulleyThickness]) mirror([0,0,1])
		halfPulley(pulleyInnerDiameter,pulleyOuterDiameter,pulleyThickness,rimDeepnes,rimBootomWith,rimTopWith);
}

module halfPulley(	pulleyInnerDiameter,
						pulleyOuterDiameter,
						pulleyThickness,
						rimDeepnes,
						rimBootomWith,
						rimTopWith	)
{
	// 1. inner Ring
	washer(pulleyThickness/2,pulleyInnerDiameter,pulleyOuterDiameter-rimDeepnes*2);

	// 2. outer edge ring
	flThickness=(pulleyThickness-rimTopWith)/2; 
	washer(flThickness,pulleyInnerDiameter,pulleyOuterDiameter);

	// 3. bevel ring ( Schrägflächen Ring)
	brThickness=pulleyThickness/2-flThickness-rimBootomWith/2;

	brInnerDiameter=pulleyOuterDiameter-rimDeepnes*2;
	
	brYPos=flThickness;
	
	translate([0,0,brYPos])
		difference()
		{
			cylinder(h=brThickness,r2=brInnerDiameter/2,r1=pulleyOuterDiameter/2);
			cylinder(h=brThickness,r=brInnerDiameter/2);
		}
}

module washer(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(h=thickness,r=outerDiameter/2);
		cylinder(h=thickness,r=innerDiameter/2);
	}
}