EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:NTC-piiri-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LM324 U1
U 1 1 5A0DEA92
P 2550 3650
F 0 "U1" H 2550 3850 50  0000 L CNN
F 1 "LM324" H 2550 3450 50  0000 L CNN
F 2 "Housings_DIP:DIP-14_W7.62mm" H 2500 3750 50  0001 C CNN
F 3 "" H 2600 3850 50  0001 C CNN
	1    2550 3650
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A0DEB18
P 3400 3650
F 0 "R2" V 3480 3650 50  0000 C CNN
F 1 "R" V 3400 3650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3330 3650 50  0001 C CNN
F 3 "" H 3400 3650 50  0001 C CNN
	1    3400 3650
	0    1    1    0   
$EndComp
$Comp
L D_Zener D1
U 1 1 5A0DEB5F
P 3800 4050
F 0 "D1" H 3800 4150 50  0000 C CNN
F 1 "D_Zener" H 3800 3950 50  0000 C CNN
F 2 "Diodes_THT:D_A-405_P7.62mm_Horizontal" H 3800 4050 50  0001 C CNN
F 3 "" H 3800 4050 50  0001 C CNN
	1    3800 4050
	0    1    1    0   
$EndComp
$Comp
L POT RV2
U 1 1 5A0DEBCC
P 1950 4450
F 0 "RV2" V 1775 4450 50  0000 C CNN
F 1 "POT" V 1850 4450 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Bourns_3296W" H 1950 4450 50  0001 C CNN
F 3 "" H 1950 4450 50  0001 C CNN
	1    1950 4450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR01
U 1 1 5A0DEC15
P 2900 4950
F 0 "#PWR01" H 2900 4700 50  0001 C CNN
F 1 "GND" H 2900 4800 50  0000 C CNN
F 2 "" H 2900 4950 50  0001 C CNN
F 3 "" H 2900 4950 50  0001 C CNN
	1    2900 4950
	1    0    0    -1  
$EndComp
$Comp
L POT RV1
U 1 1 5A0DEC31
P 1350 3350
F 0 "RV1" V 1175 3350 50  0000 C CNN
F 1 "POT" V 1250 3350 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Bourns_3296W" H 1350 3350 50  0001 C CNN
F 3 "" H 1350 3350 50  0001 C CNN
	1    1350 3350
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A0DEDC1
P 1350 2900
F 0 "R1" V 1430 2900 50  0000 C CNN
F 1 "R" V 1350 2900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1280 2900 50  0001 C CNN
F 3 "" H 1350 2900 50  0001 C CNN
	1    1350 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3350 1500 3500
Wire Wire Line
	1500 3500 1350 3500
Wire Wire Line
	1350 3500 1350 3750
Wire Wire Line
	1350 3750 1050 3750
Wire Wire Line
	1050 4000 1050 4950
Wire Wire Line
	1050 4950 6650 4950
Wire Wire Line
	3800 4950 3800 4200
Connection ~ 2900 4950
Wire Wire Line
	1350 3200 1350 3050
Wire Wire Line
	2550 4050 2550 3950
Wire Wire Line
	2550 3950 2450 3950
Wire Wire Line
	2450 3350 2450 2450
Wire Wire Line
	1350 2750 1350 2550
Wire Wire Line
	1350 2550 2450 2550
Connection ~ 2450 2550
Wire Wire Line
	2250 3550 1350 3550
Connection ~ 1350 3550
Wire Wire Line
	2850 3650 3250 3650
Wire Wire Line
	3550 3650 7100 3650
Wire Wire Line
	3800 3650 3800 3900
Connection ~ 3800 3650
Wire Wire Line
	2400 4950 2400 4000
Wire Wire Line
	2400 4000 2550 4000
Connection ~ 2550 4000
Connection ~ 2400 4950
Wire Wire Line
	3100 3650 3100 4450
Wire Wire Line
	3100 4450 2100 4450
Connection ~ 3100 3650
Wire Wire Line
	1800 4450 1800 4950
Connection ~ 1800 4950
Wire Wire Line
	1950 4300 1950 3750
Wire Wire Line
	1950 3750 2250 3750
$Comp
L C C1
U 1 1 5A0EBCAE
P 1300 3950
F 0 "C1" H 1325 4050 50  0000 L CNN
F 1 "C" H 1325 3850 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D4.3mm_W1.9mm_P5.00mm" H 1338 3800 50  0001 C CNN
F 3 "" H 1300 3950 50  0001 C CNN
	1    1300 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3800 1300 3750
Connection ~ 1300 3750
Wire Wire Line
	1300 4100 1050 4100
Connection ~ 1050 4100
$Comp
L Conn_01x15 J2
U 1 1 5A0EC200
P 7400 3150
F 0 "J2" H 7400 3950 50  0000 C CNN
F 1 "Conn_01x15" H 7400 2350 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x15_Pitch2.54mm" H 7400 3150 50  0001 C CNN
F 3 "" H 7400 3150 50  0001 C CNN
	1    7400 3150
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x15 J3
U 1 1 5A0EC24F
P 7700 3150
F 0 "J3" H 7700 3950 50  0000 C CNN
F 1 "Conn_01x15" H 7700 2350 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x15_Pitch2.54mm" H 7700 3150 50  0001 C CNN
F 3 "" H 7700 3150 50  0001 C CNN
	1    7700 3150
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x03 J11
U 1 1 5A0EC46C
P 10300 3400
F 0 "J11" H 10300 3600 50  0000 C CNN
F 1 "Conn_FET" H 10300 3200 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03_Pitch2.54mm" H 10300 3400 50  0001 C CNN
F 3 "" H 10300 3400 50  0001 C CNN
	1    10300 3400
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A0EC4E1
P 9600 3400
F 0 "R3" V 9680 3400 50  0000 C CNN
F 1 "R" V 9600 3400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 9530 3400 50  0001 C CNN
F 3 "" H 9600 3400 50  0001 C CNN
	1    9600 3400
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J4
U 1 1 5A0EC55E
P 8100 5400
F 0 "J4" H 8100 5500 50  0000 C CNN
F 1 "Conn_10vOUT" H 8100 5300 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x01_Pitch2.54mm" H 8100 5400 50  0001 C CNN
F 3 "" H 8100 5400 50  0001 C CNN
	1    8100 5400
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J7
U 1 1 5A0EC5ED
P 8700 5400
F 0 "J7" H 8700 5500 50  0000 C CNN
F 1 "Conn_GND" H 8700 5300 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x01_Pitch2.54mm" H 8700 5400 50  0001 C CNN
F 3 "" H 8700 5400 50  0001 C CNN
	1    8700 5400
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x01 J5
U 1 1 5A0EC63C
P 8100 6000
F 0 "J5" H 8100 6100 50  0000 C CNN
F 1 "Conn_24vIN" H 8100 5900 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x01_Pitch2.54mm" H 8100 6000 50  0001 C CNN
F 3 "" H 8100 6000 50  0001 C CNN
	1    8100 6000
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J8
U 1 1 5A0EC69D
P 8700 6000
F 0 "J8" H 8700 6100 50  0000 C CNN
F 1 "Conn_GND" H 8700 5900 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x01_Pitch2.54mm" H 8700 6000 50  0001 C CNN
F 3 "" H 8700 6000 50  0001 C CNN
	1    8700 6000
	-1   0    0    1   
$EndComp
Wire Wire Line
	10100 3500 10100 5400
Wire Wire Line
	10100 5400 8900 5400
Wire Wire Line
	10100 3300 10100 3250
Wire Wire Line
	10100 3250 9600 3250
Wire Wire Line
	9600 3550 10100 3550
Connection ~ 10100 3550
$Comp
L Conn_01x06 J9
U 1 1 5A0EC9BC
P 8850 2400
F 0 "J9" H 8850 2700 50  0000 C CNN
F 1 "Conn_SD" H 8850 2000 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x06_Pitch2.54mm" H 8850 2400 50  0001 C CNN
F 3 "" H 8850 2400 50  0001 C CNN
	1    8850 2400
	0    1    1    0   
$EndComp
$Comp
L Conn_01x04 J1
U 1 1 5A0ECD97
P 5900 3200
F 0 "J1" H 5900 3400 50  0000 C CNN
F 1 "Conn_SCREEN" H 5900 2900 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 5900 3200 50  0001 C CNN
F 3 "" H 5900 3200 50  0001 C CNN
	1    5900 3200
	-1   0    0    1   
$EndComp
Wire Wire Line
	8550 2200 8350 2200
Wire Wire Line
	8350 2200 8350 2650
Wire Wire Line
	8350 2650 7900 2650
Wire Wire Line
	8650 2200 8650 2150
Wire Wire Line
	8650 2150 7200 2150
Wire Wire Line
	7200 2150 7200 2450
Wire Wire Line
	8750 2200 8750 2100
Wire Wire Line
	8750 2100 8200 2100
Wire Wire Line
	8200 2100 8200 2550
Wire Wire Line
	8200 2550 7900 2550
Wire Wire Line
	8850 2200 8850 2050
Wire Wire Line
	8850 2050 8150 2050
Wire Wire Line
	8150 2050 8150 2450
Wire Wire Line
	8150 2450 7900 2450
Wire Wire Line
	8950 2200 8950 1900
Wire Wire Line
	8950 1900 6950 1900
Wire Wire Line
	6950 1900 6950 3550
Wire Wire Line
	6600 3550 7200 3550
Wire Wire Line
	9050 2200 9050 1800
Wire Wire Line
	9050 1800 6850 1800
Wire Wire Line
	6850 1800 6850 3750
Wire Wire Line
	6100 3750 7550 3750
Wire Wire Line
	6650 4950 6650 6350
Wire Wire Line
	6650 6350 8900 6350
Wire Wire Line
	8900 6350 8900 5400
Connection ~ 3800 4950
Connection ~ 8900 6000
Wire Wire Line
	7900 5400 7000 5400
Wire Wire Line
	7000 5400 7000 3850
Wire Wire Line
	7000 3850 7200 3850
Wire Wire Line
	6100 3300 6100 3750
Connection ~ 6850 3750
Wire Wire Line
	6100 3200 6950 3200
Connection ~ 6950 3200
Wire Wire Line
	6100 3100 6500 3100
Wire Wire Line
	6500 3100 6500 2850
Wire Wire Line
	6500 2850 7200 2850
Wire Wire Line
	6100 3000 6350 3000
Wire Wire Line
	6350 3000 6350 2750
Wire Wire Line
	6350 2750 7200 2750
Wire Wire Line
	7900 3150 9650 3150
Wire Wire Line
	9650 3150 9650 3250
Connection ~ 9650 3250
Wire Wire Line
	7550 3750 7550 3550
Wire Wire Line
	7550 3550 8200 3550
Connection ~ 7200 3750
$Comp
L Conn_01x04 J6
U 1 1 5A0F40DE
P 8400 3350
F 0 "J6" H 8400 3550 50  0000 C CNN
F 1 "Conn_ENCODER" H 8400 3050 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 8400 3350 50  0001 C CNN
F 3 "" H 8400 3350 50  0001 C CNN
	1    8400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3250 8200 3250
Wire Wire Line
	7900 3350 8200 3350
Wire Wire Line
	7900 3450 8200 3450
Connection ~ 7900 3550
Wire Wire Line
	7100 3650 7100 3350
Wire Wire Line
	7100 3350 7200 3350
$Comp
L Conn_01x05 J10
U 1 1 5A0F92B7
P 9850 5900
F 0 "J10" H 9850 6200 50  0000 C CNN
F 1 "Conn_TIP" H 9850 5600 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x05_Pitch2.54mm" H 9850 5900 50  0001 C CNN
F 3 "" H 9850 5900 50  0001 C CNN
	1    9850 5900
	1    0    0    -1  
$EndComp
Connection ~ 8900 6100
Wire Wire Line
	9650 5900 8900 5900
Connection ~ 8900 5900
Wire Wire Line
	9650 5700 7900 5700
Wire Wire Line
	7900 5700 7900 6000
Wire Wire Line
	9650 5800 9650 3800
Wire Wire Line
	9650 3800 9900 3800
Wire Wire Line
	9900 3800 9900 3400
Wire Wire Line
	9900 3400 10100 3400
Wire Wire Line
	550  6450 550  3500
Wire Wire Line
	550  3500 1150 3500
Wire Wire Line
	1150 3500 1150 3750
Connection ~ 1150 3750
Wire Wire Line
	7000 4500 4900 4500
Wire Wire Line
	4900 4500 4900 2900
Wire Wire Line
	4900 2900 2450 2900
Connection ~ 2450 2900
Connection ~ 7000 4500
Wire Wire Line
	9350 6450 9350 6100
Connection ~ 9350 6450
Wire Wire Line
	9650 6450 550  6450
Wire Wire Line
	9350 6100 9650 6100
Wire Wire Line
	9650 6000 8900 6000
$Comp
L +VDC #PWR02
U 1 1 5A0FDA47
P 3250 2650
F 0 "#PWR02" H 3250 2550 50  0001 C CNN
F 1 "+VDC" H 3250 2900 50  0000 C CNN
F 2 "" H 3250 2650 50  0001 C CNN
F 3 "" H 3250 2650 50  0001 C CNN
	1    3250 2650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 5A0FE77E
P 6600 3450
F 0 "#PWR03" H 6600 3300 50  0001 C CNN
F 1 "+5V" H 6600 3590 50  0000 C CNN
F 2 "" H 6600 3450 50  0001 C CNN
F 3 "" H 6600 3450 50  0001 C CNN
	1    6600 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3550 6600 3450
Connection ~ 6950 3550
Wire Wire Line
	3250 2650 3250 2900
Connection ~ 3250 2900
$Comp
L +24V #PWR04
U 1 1 5A0FF79E
P 7650 5850
F 0 "#PWR04" H 7650 5700 50  0001 C CNN
F 1 "+24V" H 7650 5990 50  0000 C CNN
F 2 "" H 7650 5850 50  0001 C CNN
F 3 "" H 7650 5850 50  0001 C CNN
	1    7650 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 5850 7900 5850
Connection ~ 7900 5850
Wire Wire Line
	6300 4950 6300 3750
Connection ~ 6300 3750
Connection ~ 6300 4950
$EndSCHEMATC
