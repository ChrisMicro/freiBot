/*
freiBot Pneu
robot wheel to press-fit on bearing
2015 by cho & stahl

hub added
2015 by stochri

*/

$fn=100; // resolution

// dimensions
outer_r = 26/2; // outer radius
inner_r = 23/2; // inner radius / radius of bearing


// construction heights
groove = 0.5; // green
bevel = 2; // deeppink
rim = 1.5; // gold
flange = 1.0; // blue
hubLength=10;
hubHoleDiameter=3;
hubDiameter=6;
flange_hole_r = hubDiameter/2;

// make it
build();

module build()
{
    translate([0,0,groove+bevel+rim+flange])
    difference() {
        union() {
            wheel();
            translate([0,0,-(groove+bevel+rim+flange)]) cylinder(r=outer_r, h=flange);
        }
        color("silver") union() {
            translate([0,0,-(bevel+groove+rim+0.1)]) cylinder(r=inner_r, h=20);
            translate([0,0,-(bevel+groove+rim+flange+0.1)]) cylinder(r=flange_hole_r, h=20);
        }
    }
hub(hubLength,hubHoleDiameter,hubDiameter);
}

module hub(thickness,innerDiameter,outerDiameter)
{
	difference()
	{
		cylinder(thickness,outerDiameter/2,outerDiameter/2);
		cylinder(thickness,innerDiameter/2,innerDiameter/2);
	}	
}
module wheel()
{
     union() {
        half_wheel();
        mirror([0,0,1]) half_wheel();
    }
}

module half_wheel()
{
    union() {
        color("green") cylinder(r=inner_r+0.5, h=groove);
        color("deeppink") translate([0,0,groove]) cylinder(r1=inner_r+0.5, r2=outer_r, h=bevel);
        color("gold") translate([0,0,groove+bevel]) cylinder(r=outer_r, h=rim);
    }

}
