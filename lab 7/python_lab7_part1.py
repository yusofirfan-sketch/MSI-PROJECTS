import serial
import time

# Replace COM3 with the correct port
ser = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)  # wait for Arduino to initialize

while True:
    data = ser.readline().decode('utf-8').strip()
    if data:
        print(f"Received: {data}")
        # Simple logic to determine dominant color
        try:
            parts = data.replace('R:', '').replace('G:', '').replace('B:', '').split()
            red, green, blue = int(parts[0]), int(parts[1]), int(parts[2])
            if red > green and red > blue:
                color = "Red detected"
            elif green > red and green > blue:
                color = "Green detected"
            elif blue > red and blue > green:
                color = "Blue detected"
            else:
                color = "Uncertain color"
            print(color)
        except:
            continue
