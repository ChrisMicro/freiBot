print "show analog input"
print

let value = 0 

' read analog input every 1000 ms
timer 1000,[readAnalogInput]

' show value in text box
textbox value 
print

button "Exit", [TestExit] 
wait 


[readAnalogInput] 
value = io(ai) 
wait 

[TestExit] 
end


