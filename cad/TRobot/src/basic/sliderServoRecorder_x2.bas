print "servo position recorder and player"
print


let pin = 4  ' servo 1
let pin2 = 5 ' servo 2
let ledPin = 16

let posOk = false
let flag = true

let pos = 100
let pos2 = 100
let realPos = 100
let realPos2 = 100 
let speed = 10
let counter = 0
let repeats = 1

dim posRecord(100)
dim posRecord2(100)
let posPointer = 0 

slider pos,0,255
textbox pos 
print

slider pos2,0,255
textbox pos2 
print

print "posPointer",
textbox posPointer
button "store",[store]
button "reset",[pointerReset]
button "play",[play]
textbox repeats

print "speed",
textbox speed

button "Exit", [TestExit] 

timer 100,[SetThePinServo]
wait 

[store]
posPointer = posPointer +1
posRecord(posPointer)=pos
posRecord2(posPointer)=pos2
wait

[pointerReset]
posPointer = 0
wait

'==== play =============
[play]
let k = posPointer
timer 0

for w=1 to repeats

k = posPointer
posPointer = 0

do
 posPointer = posPointer +1
 pos=posRecord(posPointer)
 pos2=posRecord2(posPointer)
 for n=1 to 8
  gosub [setServo]
  delay 50
 next

loop while posPointer<k
next

timer 100,[SetThePinServo]

wait

'=============================

[SetThePinServo] 
gosub [setServo]
wait

[setServo]
flag = true

if pos<realPos then
realPos = realPos - speed
flag = false
endif

if pos > realPos then
realPos = realPos + speed
flag = false
endif

if pos2<realPos2 then
realPos2 = realPos2 - speed
'flag = false
endif

if pos2 > realPos2 then
realPos2 = realPos2 + speed
'flag = false
endif

posOk=flag


io(servo,pin,realPos) 
io(servo,pin2,realPos2) 

' blink led
counter = counter +1
if counter > 10 then
counter = 0
io(po,ledPin,0)
else
io(po,ledPin,1)
endif

return

'================
[TestExit] 
end











