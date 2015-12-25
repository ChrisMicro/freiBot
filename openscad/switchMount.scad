/*
	swicht mount for 'ON' switch

	2015 by ChrisMicro
*/

$fn=50;

ManufactoringTolerance=1;

mountX=30;
mountY=6;
mountZ=10;
mountFrontThickness=1;


swBodyX          = ManufactoringTolerance +  11.5;
swHeigth         = ManufactoringTolerance +   5.5;
swBodyY          =                             10;
swPlateX         = ManufactoringTolerance +    20;
swPlateYOffset   =                              5;
swPlateThickness =                              1;
swLength         =                             10;
drilling         =                            2.5;
drillingPosX     =                            2.5;
drillingPosY     = ManufactoringTolerance/2 + 2.5;


switchMount();
//switchModel();

module switchMount()
{
	difference()
	{
		cube([mountX,mountY,mountZ]);
		translate([(mountX-swPlateX)/2,-4,mountZ-swHeigth]) switchModel();
	}
}

module switchModel()
{
	// body
	translate([(swPlateX-swBodyX)/2,0,0])cube([swBodyX,swBodyY,swHeigth]);
	// plate
	translate([0,swPlateYOffset,0])cube([swPlateX,swPlateThickness,swHeigth]);
	// drilling 1
	translate([drillingPosX,0,drillingPosY]) rotate([270,0,0])cylinder(h=swBodyY,r=drilling/2);
	// drilling 2
	translate([swPlateX-drillingPosX,0,drillingPosY]) rotate([270,0,0])cylinder(h=swBodyY,r=drilling/2);
}