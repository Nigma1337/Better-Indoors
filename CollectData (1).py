import serial
import sys
import time
import datetime

datetime.datetime.now()
myFile = str(datetime.datetime.now())
f = open( myFile, 'wb+')

timeout = time.time() + 10
try:
    ser = serial.Serial('/dev/ttyACM0',9600)
except:
    ser = serial.Serial('/dev/ttyACM1',9600)
s = [0]
#tag serial input fra arduinoen og smid det ind i en fil
while True:
    read_serial=ser.readline()
    print (read_serial)
    f.write(read_serial + b'\n')
    f.close

while False:
    break
#luk filen og stop scriptet
f.close()
sys.exit("dab")