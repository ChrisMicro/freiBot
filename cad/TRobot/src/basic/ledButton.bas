let pin = 0 ' hw button
let ledPin = 16
let value = 0

textbox value

timer 100, [show]

button "exit",[stopProgram]

wait

[show]
value=io(pi,pin)
if value = 1 then
io(po,ledPin,0)
else
io(po,ledPin,1)
endif

wait

[stopProgram]
end




