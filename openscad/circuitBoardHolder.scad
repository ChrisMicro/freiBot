/*
	circuit board holder

	2015 by ChrisMicro

*/

manuFactoringOffset = 1; // tollarance for colling down the PLA

// outer dimensions
frameLength = 120;
frameWidth  = 95;
frameHeight = 3;

// board dimensions
boardLength = manuFactoringOffset + 100;
boardWidth  = manuFactoringOffset + 75 ;
boardHeight = manuFactoringOffset + 1.5;

boardAuflageBreite = 3;

circuitBoardHolder();

module circuitBoardHolder()
{
	difference()
	{
		// frame
		cube([frameLength,frameWidth,frameHeight]);
	
		// hole 
		translate([(frameLength-boardLength)/2+boardAuflageBreite,(frameWidth-boardWidth)/2+boardAuflageBreite,0])
			cube([boardLength-boardAuflageBreite*2,boardWidth-boardAuflageBreite*2,frameHeight]);

		// board
		translate([(frameLength-boardLength)/2,(frameWidth-boardWidth)/2,frameHeight-boardHeight])
			cube([boardLength,boardWidth,boardHeight]);
	}
}	