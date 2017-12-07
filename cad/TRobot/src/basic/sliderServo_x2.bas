print "Servoposition ueber Schieberegler steuern"
print

let pin = 4 
let pos = 0 
let pin2 = 5 
let pos2 = 0 

slider pos,0,255
textbox pos 
print

slider pos2,0,255
textbox pos2 
print

button "Exit", [TestExit] 

timer 100,[SetThePinServo]
wait 


[SetThePinServo] 
io(servo,pin,pos) 
io(servo,pin2,pos2) 
wait 

[TestExit] 
end










