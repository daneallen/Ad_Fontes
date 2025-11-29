# Ad Fontes STEM Project 2025

A project intended to introduce students to electrical engineering, printed circuit
board (PCB) design, soldering and embedded microcontroller programming.

# Day 1

Introduction to circuit design of the project. The entire design of the PCB was
completed using [KiCad](https://www.kicad.org/), a free and open sourced PCB software application.

The design of the circuit is built around the small and very capable [ATtiny1616](https://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny1614-16-17-DataSheet-DS40002204A.pdf) microcontroller.

![Close up image of a soldered ATtiny1616](/Images/Assembly/microscopeCheck.png)

The entire schematic of the PCB is [here](/Documents/Schematic.pdf)

## Design Timeline

| Date | Notes |
| ------ | ----------- |
| 8/23/25 | The PCB was first designed in KiCad |
| 8/28/25 | The first order of PCBs was placed. |
| 9/15/25 | The first of PCBs arrives. The design was sound, however the logo was too dark and there was improvements that could be made |
| 9/19/25 | Order #2 (v02) was placed to fix some of the identified issues |
| 10/6/25 | v02 badges arrive, Overall good, would benefit from a few additional things printed on the back of the board. |
| 10/19/25 | Order #3 (v03) was placed |
| 10/30/25 | v03 badge arrives. There is a problem with the back grounding plane... it was NOT filled in and so nothing works. |
| 11/10/25 | Order #4 (v04) was placed to finally fix all the things. |
| 11/20/25 | v04 arrives and is functional and ready for class. |

### Ideas for improvement

   - [x] lighten the colors for on the front of the badge for more contrast
   - [x] enlarge the test on the back of the badge... possibly expand/point out the different components
   - [x] remove the svg2mod on the front silkscreen
   - [x] better align the image on the front of the badge
   - [x] fix/address/remove the white parts near the mouse bites
   - [x] add a box and label for initials



# Day 2

On this day students will select the 4 LEDs that will be soldered onto their PCB.

![Good & Bad solder examples](/Images/Assembly/solderExamples.png)

[YouTube Link for Soldering Example](https://www.youtube.com/watch?v=eHu_fGAyNY4)

# Day 3

Time to finish the PCB with some custom firmware. The ATtiny1616 utilizes the [Unified Program and Debug Interface (UPDI)]([https://learn.adafruit.com/adafruit-updi-friend/overview) protocol to program the microcontroller. Having the [Adafruit UPDI Friend Programmer](https://www.adafruit.com/product/5879) is quite helpful, especially when using it with the Tag-Connect [TC2030-IDC-NL](https://www.tag-connect.com/product/tc2030-idc-nl) 6-pin plug-of-nails connector tool.


# Behind the Scenes

You will notice that there numerous components already assembled on the board prior to the 4 LEDs. Those components were assembled
in the following manner.

1. Setup the PCB in a jig to apply the solder paste.
![Solder Paste Setup](/Images/Assembly/solderPasteSetup.png)

2. Apply the solder paste to the PCB.
![Applying the Solder Paste](/Images/Assembly/solderPasteApplication.png)

3. Setup the Pick and Place Machine and have it place all the small components to the board.
[Watch the PnP magic](/Images/Assembly/PnP.mp4)

4. Add the larger components by hand.

5. Put the board in the oven.
![Placing the boards in the oven](/Images/Assembly/ovenStart.png)

6. Wait about 6 minutes for a freshly cooked badge to come out completed on the other side.
[Cooked badge](/Images/Assembly/ovenFinished.mov)

7. Enjoy all the completed badges.

![All the badge assembly completed](/Images/Assembly/completedFunctional.png)
