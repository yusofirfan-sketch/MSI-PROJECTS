import serial
import time

# Update COM port accordingly
ser = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)

try:
    while True:
        val = input("Enter Angle (0-180) or 'q' to quit: ")
        if val.lower() == 'q':
            break
        ser.write(val.encode())
except KeyboardInterrupt:
    pass
finally:
    ser.close()
    print("Connection Closed.")
