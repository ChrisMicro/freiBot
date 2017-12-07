' adc meter example

html |<body style="background-color:powderblue;">|
html |<h1>ESP basic graphic elements</h1>|
html |</body>|

print "show analog input"
print

let value = 0 

meter value,0,1024

' read analog input every 100 ms
timer 100,[readAnalogInput]

' show value in text box
html |<p>adc value</p>|
textbox value 
print

cssclass "button", "background-color: yellow;"
button "Exit", [TestExit] 
wait 


[readAnalogInput] 
value = io(ai) 
wait 

[TestExit] 
end

