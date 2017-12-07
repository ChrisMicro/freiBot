html |<body style="background-color:powderblue;">|
html |<h1> Dingdong Generator </h1>|
html |</body>|

let pin = 4 
let zeit = 500
let ton = 1
let wiederholung = 3

button "ding",[ding]
button "dong",[dong]
print 
button "rythmus",[rythmus]
html |<p> Wiederholung </p>|
textbox wiederholung
html |<p> Geschwindigkeit </p>|
slider zeit,100,1000

wait 

[ding]
gosub [playDing]
wait

[dong]
gosub [playDong]
wait

[rythmus]
for n = 1 to wiederholung
gosub [playDing]
gosub [playDong]
gosub [playDong]
gosub [playDong]
next
io(po,pin,0) 'servo aus
wait

[playDing]
gosub [links]
delay 100
gosub [mitte]
delay zeit

return

[playDong]
gosub [rechts]
delay 100
gosub [mitte]
delay zeit

return

[links]
io(servo,pin,80)
return

[mitte]
io(servo,pin,100)
return

[rechts]
io(servo,pin,120)
return




