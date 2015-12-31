/*
freiBot Pneu
robot wheel to press-fit on bearing
2015 by cho & stahl
*/

$fn=100; // resolution

// dimensions
outer_r = 26/2; // outer radius
inner_r = 21/2; // inner radius / radius of bearing
flange_hole_r = 20/2;

// construction heights
groove = 0.5; // green
bevel = 2; // deeppink
rim = 1.5; // gold
flange = 0.5; // blue

wall_whickness = 0.5;

// make it
build();
//build_old(); // for old version

module build() {
    
    translate([0,0,groove+bevel+rim+flange])
    union() {
    
        union() {
            translate([0,0,groove/2]) groove();
            translate([0,0,-groove/2]) groove();
        }
        
        union() {
            translate([0,0,bevel/2+groove]) bevel();
            translate([0,0,-bevel/2-groove]) mirror([0,0,1]) bevel();
        }
        
        union() {
            translate([0,0,rim/2+bevel+groove]) rim();
            translate([0,0,-rim/2-bevel-groove]) rim();
        }
        
        union() {
            translate([0,0,flange/2+rim+bevel+groove]) flange();
            translate([0,0,-flange/2-rim-bevel-groove]) flange();
        }
    }
}

module groove() {
    difference() {
        color("green") cylinder(r=inner_r+wall_whickness, h=groove, center=true);
        color("silver") cylinder(r=inner_r, h=groove+0.1, center=true);
    }
}

module bevel() {
    difference() {
        color("deeppink") cylinder(r1=inner_r+wall_whickness, r2=outer_r, h=bevel, center=true);
        color("silver") cylinder(r=inner_r, h=bevel+0.1, center=true);
    }
}

module rim() {
    difference() {
        color("gold") cylinder(r=outer_r, h=rim, center=true);
        color("silver") cylinder(r=inner_r, h=rim+0.1, center=true);
    }
}

module flange() {
    difference() {
        color("blue") cylinder(r=outer_r, h=flange, center=true);
        color("silver") cylinder(r=flange_hole_r, h=flange+0.1, center=true);
    }
}



/* 
modules below are kept for old version
*/
module build_old()
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

