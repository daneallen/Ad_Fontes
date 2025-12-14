#!/bin/bash

programBoard() {
	echo "Select the Ad Fontes Program you would like to use"
	echo "1. All LEDs on steady"
	echo "2. Twinkle Effect"
	echo "3. Chase Effect"
	echo "4. Breathing Effect"
	read -n 1 -p "Select your entry here:" userInput

	echo ""

	binaryLoad = ""

	if (($userInput == 1 )); then
		echo "Binary Load All LEDs on steady"
		binaryLoad="adFontes.steadyOn.ino.hex"
	elif (($userInput == 2 )); then
		echo "Binary Load Twinkle Effect"
		binaryLoad="adFontes.twinkle.ino.hex"
	elif (($userInput == 3 )); then
		echo "Binary Load Chase Effect"
		binaryLoad="adFontes.chase.ino.hex"
	elif (($userInput == 4)); then
		echo "Binary Load Breathing Effect"
		binaryLoad="adFontes.breathing.ino.hex"
	else
		echo "Invalid entry selected"
		return 0
	fi

	echo $binaryLoad

	"/Users/danallen/Library/Arduino15/packages/megaTinyCore/tools/python3/3.7.2-post1/python3" -u "/Users/danallen/Library/Arduino15/packages/megaTinyCore/hardware/megaavr/2.6.12/tools/prog.py"  -t uart -u /dev/cu.usbserial-1420 -b 57600 -d attiny1616 --fuses 0:0b00000000 2:0x02 6:0x04 7:0x00 8:0x00 "-f./${binaryLoad}" -a write -v
}


while true
do
	programBoard
done
