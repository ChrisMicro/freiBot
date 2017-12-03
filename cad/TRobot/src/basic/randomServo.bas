let pin = 4 
let value = 0 

for n=1 to 50
 delay 300
' randon number up to 255
 value=rnd(255)
 io(servo,pin,value)
next

