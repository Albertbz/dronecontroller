from tello import Tello
from time import sleep
import serial

tello = Tello()

run = False
ser = serial.Serial('COM5', baudrate=250000, timeout=1)
sleep(1)

tello.send_command("command")

while True:
    arduinoData = ser.readline().decode('ascii')
    arduinoDataSplit = arduinoData.split(",")

    x = float(arduinoDataSplit[0])
    y = float(arduinoDataSplit[1])
    ax = float(arduinoDataSplit[2])
    ay = float(arduinoDataSplit[3])
    az = float(arduinoDataSplit[4])
    gx = float(arduinoDataSplit[5])
    gy = float(arduinoDataSplit[6])
    gz = float(arduinoDataSplit[7])
    temp = float(arduinoDataSplit[8])

    if gx > 500 and not run:
        tello.send_command("takeoff")
        run = True
    if gx < -500 and run:
        tello.send_command("land")
        run = False
    if run and -100 <= x <= 100:
        tello.send_command('rc ' + str(x) + ' ' + str(y) + ' 0 ' + str(gz))
    elif run and x == 199:
        tello.send_command("emergency")
        run = False
