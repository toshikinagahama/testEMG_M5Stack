import serial
import datetime

ser = serial.Serial("/dev/cu.usbserial-01DB9718", 115200)
if(ser.isOpen()):
  ser.close()
ser.open()

total_time = 60
SF = 1000

data = []
for i in range(total_time * SF + 1):
  line = ser.readline().decode("utf-8").replace("\n", "")
  #最初は飛ばす
  if(i == 0): continue
  data.append(line)
  print(f"{i}\t{line}")

now = datetime.datetime.now()
filename = './data/' + now.strftime('%Y%m%d_%H%M%S_emg') + '.csv'
with open(filename, 'w') as f:
  f.write("Emg_cnt\n")
  for d in data:
    f.write(f"{d}\n")
  f.close()