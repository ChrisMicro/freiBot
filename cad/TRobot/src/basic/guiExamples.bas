' graphic elements example

' blue background
html |<body style="background-color:powderblue;">|
html |<h1>ESP basic graphic elements</h1>|
html |</body>|

html |<p> button </p>|

cssclass "button", "background-color: yellow;"
button "press it",[buttonPressed]

html |<p> slider </p>|

slider value,0,100

html |<p> meter ( more or less a bar graph ) </p>|

meter value,0,100

html |<p> listbox </p>|
listbox elementText,"apple,orange,kivi,leon",3

html |<p> textbox, in this example shows the listbox element </p>|

textbox elementText

html |<p> dropdown menue </p>|

dropdown selection,"hallo,bello,cello"

'imagebutton "bild.png",[buttonPressed]

wait

[buttonPressed]
print "pressed"
wait











