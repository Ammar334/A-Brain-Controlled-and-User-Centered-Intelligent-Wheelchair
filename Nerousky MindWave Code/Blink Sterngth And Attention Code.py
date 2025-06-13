import socket
import json
import re  # Import regex for extracting attention value
import time
import serial   
# Connection settings for Neurosky MindWave
HOST, PORT = '127.0.0.1', 13854
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)


# --- STM32 Serial Communication ---
SERIAL_PORT = "COM3"  # Replace with your actual COM port
# SERIAL_PORT = "/dev/ttyACM0"  # Use this on Linux/macOS
BAUD_RATE = 115200



# Movement control variables
forward_count = 0
backward_count = 0
command = None
Current_command = None
counter = 0
stop_system = 0

try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Wait for connection
except Exception as e:
    print(f"Error: Unable to connect to STM32 UART - {e}")
    exit()

try:
    sock.connect((HOST, PORT))
    print("✅ Connected to the sensor successfully!")

    # Send settings to the sensor
    sock.sendall(b'{"enableRawOutput": false, "format": "Json"}')

    buffer = ""

    while True:
        data = sock.recv(1024).decode('utf-8', errors='ignore')  # Receive data
        if not data:
            break

        buffer += data  # Store data

        # Extract all JSON objects using regex
        matches = re.findall(r'\{.*?\}', buffer)

        for json_str in matches:
            if not json_str.endswith("}"):  # Ensure JSON is complete
                continue

            attention = None  # Default value if not found
            blink_strength = None  # Default value if not found

            try:
                parsed_data = json.loads(json_str)  # Try to parse JSON

                # **Extract Blink Strength**
                if "blinkStrength" in parsed_data:
                    blink_strength = parsed_data["blinkStrength"]

                # **Extract Attention (if JSON decoding succeeds)**
                if "eSense" in parsed_data and "attention" in parsed_data["eSense"]:
                    attention = parsed_data["eSense"]["attention"]
                    
            except json.JSONDecodeError:
                # **Extract Attention using regex in case JSON decoding fails**
                match = re.search(r'"attention"\s*:\s*(\d+)', json_str)
                if match:
                    attention = int(match.group(1))  # Convert extracted value to integer

            # **Process Blink Strength (if found)**
            if blink_strength is not None:
                print(f"Blink Strength: {blink_strength}")

                if 90 < blink_strength < 140:
                    forward_count += 1
                elif blink_strength > 140:
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
            if command == 'S' :
                while counter < 7 :
                        counter += 1
                        time.sleep(1)
                        print(f"Attention Counter : {counter}")  

            # **Process Attention (if found)**
            if attention is not None and Current_command == 'S' and stop_system == 0:
                print(f"Attention Level: {attention}")
                if attention > 60:
                    command = 'R'
                elif 10 < attention < 30:
                    command = 'L'
                else:
                    print(" Center")
                    command = 'S'
                if attention <= 10 :
                    stop_system = 1
            if command and Current_command != command:
                Current_command = command
                print(f"Command Sent: {command}")
                ser.write(command.encode())  # Send to STM32
                counter = 0

        # Update buffer to keep only data after the last complete JSON
        if matches:
            last_match = matches[-1]
            buffer = buffer[buffer.rfind(last_match) + len(last_match):]

except Exception as e:
    print("❌ Error:", e)

finally:
    sock.close()
