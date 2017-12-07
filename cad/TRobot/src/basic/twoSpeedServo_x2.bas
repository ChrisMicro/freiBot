let pin = 4 
let pos=0
let vForward= 1
let vBackward = 1
let direction = 1
let minpos = 50
let maxpos = 200

let pin2 = 5 
let pos2 = 0
let vForward2 = 1
let vBackward2 = 1
let direction2 = 1
let minpos2 = 50
let maxpos2 = 200

html |<body style="background-color:powderblue;">|
html |<h1>ESP basic graphic elements</h1>|
html |</body>|

html |<h1> servo1 </h1>|
print "pos",
textbox pos
meter pos,0,255

print "speedForward",
slider vForward,0,50

print "speedBackward",
slider vBackward,0,50

print "minpos",
slider minpos,0,255

print "maxpos",
slider maxpos,0,255

button "set minpos",[setMinPos]
button "set maxpos",[setMaxPos]

'===============================
html |<h1> servo2 </h1>|
print "pos2",
textbox pos2
meter pos2,0,255

print "speedForward2",
slider vForward2,0,50

print "speedBackward2",
slider vBackward2,0,50

print "minpos2",
slider minpos2,0,255

print "maxpos2",
slider maxpos2,0,255

button "set minpos 2",[setMinPos2]
button "set maxpos 2",[setMaxPos2]

html |<h1> start/stop </h1>|
button "start",[start]
button "stop",[stop]


print
button "Exit", [stopProgram] 
wait 

'==============================
[taskRoutine] 
if direction=1 then
 pos=pos+vForward
endif

if direction=-1 then
 pos=pos-vBackward
endif


if pos > maxpos then 
 direction=-1
 pos=maxpos
endif

if pos < minpos then
 direction=1
 pos=minpos
endif

io(servo,pin,pos) 
'---------------------------
if direction2=1 then
 pos2=pos2+vForward2
endif

if direction2=-1 then
 pos2=pos2-vBackward2
endif


if pos2 > maxpos2 then 
 direction2=-1
 pos2=maxpos2
endif

if pos2 < minpos2 then
 direction2=1
 pos2=minpos2
endif

io(servo,pin2,pos2) 

wait 

'===========================
[start]
timer 50,[taskRoutine]
wait

[stop]
timer 0
wait

[setMinPos]
pos=minpos
io(servo,pin,pos) 
wait

[setMaxPos]
pos=maxpos
io(servo,pin,pos) 
wait

[setMinPos2]
pos2=minpos2
io(servo,pin2,pos2) 
wait

[setMaxPos2]
pos2=maxpos2
io(servo,pin2,pos2) 
wait


[stopProgram]
' set servo pin to zero ( turn off pwm ) 
io(po,pin,0) 
io(po,pin2,0) 
end










