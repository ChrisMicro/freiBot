speed = 100
speedSetting = 700

RichtungL = 0
RichtungR = 0

button "links",[links]
button "rechts",[rechts]
button "vor",[vor]
button "rueck",[rueck]
button "stop",[bstop]
slider speedSetting,0,800
print 
button "beep",[beep]
wait

[beep]
speed = 300
for n=4 to 20
Pwmfreq n*100 
RichtungL = 1
RichtungR = 1
gosub [move]
delay 10
RichtungL = 0
RichtungR = 0
gosub [move]
delay 10
next

gosub [stop]
wait

[vor]
speed = speedSetting
RichtungL = 0
RichtungR = 0
gosub [move]
wait

[rueck]
speed = speedSetting
RichtungL = 1
RichtungR = 1
gosub [move]
wait

[links]
speed = speedSetting
RichtungL = 0
RichtungR = 1
gosub [move]
delay 200
gosub [stop]
wait

[rechts]
speed = speedSetting
RichtungL = 1
RichtungR = 0
gosub [move]
delay 200
gosub [stop]
wait

[move]
if RichtungL = 1 then
io(pwo,D1,speed)
io(po,D2,0)
else
io(pwo,D1,1023-speed)
io(po,D2,1)
end if

if RichtungR = 0 then
io(pwo,D3,speed)
io(po,D4,0)
else
io(pwo,D3,1023-speed)
io(po,D4,1)
end if
return

[bstop]
gosub [stop]
wait

[stop]
io(pwo,D1,0)
io(po,D2,0)
io(pwo,D3,0)
io(po,D4,0)
return 









