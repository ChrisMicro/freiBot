let pinNo = 4 
let pinStat = 0 

gosub [hoch]
delay 2000
gosub [runter]
delay 2000
gosub [hoch]
delay 2000
gosub [runter]
delay 2000


print "finished" 
wait 

[hoch]
for n=1 to 100
  delay 10
  io(servo,pinNo,n)
next
return

[runter]
for n=1 to 100
 delay 10
 io(servo,pinNo,100-n)
next
return

