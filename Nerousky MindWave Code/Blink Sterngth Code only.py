import socket
import json
import serial
import time

# --- Neurosky MindWave Connection ---
HOST, PORT = '127.0.0.1', 13854  # Neurosky TCP settings
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# --- STM32 Serial Communication ---
SERIAL_PORT = "COM3"  # Replace with your actual COM port
# SERIAL_PORT = "/dev/ttyACM0"  # Use this on Linux/macOS
BAUD_RATE = 115200

# --- Try to open serial port ---
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Wait for connection
except Exception as e:
    print(f"Error: Unable to connect to STM32 UART - {e}")
    exit()

# --- Blink Control Variables ---
forward_count = 0
backward_count = 0

try:
    sock.connect((HOST, PORT))
    sock.sendall(b'{"enableRawOutput": false, "format": "Json"}')

    buffer = ""  # Data storage buffer

    while True:
        data = sock.recv(1024).decode('utf-8')
        buffer += data

        while "}\r" in buffer:
            try:
                part, buffer = buffer.split("}\r", 1)
                json_data = json.loads(part + "}")

                if "blinkStrength" in json_data:
                    blink_strength = json_data["blinkStrength"]
                    print(f"Blink Strength: {blink_strength}")
                        
                    if 90 < blink_strength < 180:
                        forward_count += 1
                    elif blink_strength > 180:
                        backward_count += 1
                    command = None
                    if forward_count == 1 or backward_count == 1:
                        command = 't'
                        forward_count = 2
                        backward_count = 2
                    elif forward_count == 3 and backward_count == 2:
                        command = 'F'
                    elif forward_count == 3 and backward_count == 3:
                        command = 'S'
                        forward_count = 2
                        backward_count = 2
                    elif forward_count == 2 and backward_count == 3:
                        command = 'B'
                    elif forward_count == 2 and backward_count == 4:
                        command = 'S'
                        forward_count = 2
                        backward_count = 2
                    elif forward_count == 4 and backward_count == 2:
                        command = 'S'
                        forward_count = 2
                        backward_count = 2

                    if command:
                        print(f"Command Sent: {command}")
                        ser.write(command.encode())  # Send to STM32

            except json.JSONDecodeError:
                pass

except Exception as e:
    print(f"Connection error or runtime error: {e}")

finally:
    sock.close()
    ser.close()
