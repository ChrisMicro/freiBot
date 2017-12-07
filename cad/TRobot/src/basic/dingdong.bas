' bewege Servo links rechts wenn Knopf gedrückt

let pin = 4 
let zeit = 100

button "play",[play]
slider zeit,100,1000

wait 

[play]
for n=1 to 3
 gosub [runter]
 delay zeit
 gosub [hoch]
 delay zeit
next
io(po,pin,0)
wait

[hoch]
io(servo,pin,100)
return

[runter]
io(servo,pin,120)
return

