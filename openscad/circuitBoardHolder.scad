/*
	circuit board holder

	2015 by ChrisMicro

*/

frameLength = 120;
frameWidth  = 85;
frameHeight = 3;

boardAuflageBreite = 3;

manuFactoringOffset = 0.2;

boardLength = 100 + manuFactoringOffset;
boardWidth  = 75  + manuFactoringOffset;
boardHeight = 1.5 + manuFactoringOffset;

//translate([frameLength/2-5,0,frameHeight])
	//cube([10,(frameWidth-boardWidth)/2+boardAuflageBreite,frameHeight]);

difference()
{
	// frane
	cube([frameLength,frameWidth,frameHeight]);
	
	// loch 
	translate([(frameLength-boardLength)/2+boardAuflageBreite,(frameWidth-boardWidth)/2+boardAuflageBreite,0])
		cube([boardLength-boardAuflageBreite*2,boardWidth-boardAuflageBreite*2,frameHeight]);

	// board
	translate([(frameLength-boardLength)/2,(frameWidth-boardWidth)/2,frameHeight-boardHeight])
		cube([boardLength,boardWidth,boardHeight]);

}