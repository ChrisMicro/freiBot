boardLength=75;
boardHeight=1.5;
boardWidth=100;

color("silver") translate([0,0,basePlateOffset]) 		
	cube(size = [basePlateLength,basePlateWidth,basePlateHeight], center = true);