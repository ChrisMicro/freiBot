print "Servoposition ueber Schieberegler steuern"
print

let pinNummer = 4 
let value = 0 

' Schieberegler erzeugen
slider value,0,255

' alle 100 Millisekunden das Servo aktualisieren
timer 100,[SetThePinServo]

' Wert anzeigen
textbox value 
print

button "Exit", [TestExit] 
wait 


[SetThePinServo] 
io(servo,pinNummer,value) 
wait 

[TestExit] 
end


