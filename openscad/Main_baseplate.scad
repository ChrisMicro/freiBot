/*
	freiBotbaseplate

	2015 by ChrisMicro
*/

// 
use <axisBearings.scad>
use <circuitBoardHolder.scad>
use <motorHolder.scad>

motorHolderX=35;
motorHolderY=40;

circuitBoardHolder();

translate([-20,90,0])
	axisBearings();

// left motor
translate([120-motorHolderX,100,0])
	motorHolder();

// right motor
translate([motorHolderX,100+motorHolderY,0]) rotate([0,0,180])
	motorHolder();

fs=25;
// front plate
translate([60-fs/2,-fs+10,0])
cube([fs,fs,3]);