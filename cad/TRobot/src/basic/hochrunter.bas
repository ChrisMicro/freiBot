let pin = 4 

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
io(servo,pin,n)
next
return

[runter]
io(servo,pin,10)
return

