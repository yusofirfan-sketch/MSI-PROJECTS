# Lab 6: Wireless Temperature Monitoring with Arduino & ThingSpeak

## Abstract
This lab explores real-time temperature monitoring using an Arduino with Wi-Fi and an LM35 sensor. Temperature data is transmitted over Wi-Fi to ThingSpeak, allowing remote visualization and analysis via a cloud dashboard.

## Extended Description
The LM35 sensor reads ambient temperature, converts it to a voltage, and the Arduino sends this data over Wi-Fi to ThingSpeak. Users can monitor temperature trends remotely. This demonstrates IoT integration and wireless control for microcontroller-based systems.

## Equipment
- Arduino ESP32 (or any Wi-Fi capable board)
- LM35 temperature sensor
- Wi-Fi network & internet access
- Power supply
- Breadboard & jumper wires

## Images
- Setup: ![Setup](image_lab6)
- Results: 
  - ![Result 1](results1_lab6)
  - ![Result 2](results2_lab6)
  - ![Result 3](results3_lab6)

## Methodology
1. Connect LM35 to ESP32 analog pin.
2. Configure Wi-Fi credentials and ThingSpeak API key in the Arduino code.
3. Upload the Arduino sketch.
4. Observe temperature data on Serial Monitor.
5. ThingSpeak plots real-time data on a dashboard.

## Discussion
The system successfully transmitted temperature data from LM35 to ThingSpeak. Data was visible on the cloud dashboard, though slight delays occurred due to Wi-Fi latency. This demonstrates practical IoT integration and real-time remote monitoring.

## Conclusion
Lab 6 shows the successful implementation of wireless temperature monitoring. Arduino and ThingSpeak together provide a low-cost, effective IoT solution.

## Recommendations
- Ensure Wi-Fi signal is strong to minimize delays in data plotting.
