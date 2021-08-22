pkg load instrument-control

s1 = serial("/dev/tty.usbmodem14101", 9600) 
srl_flush(s1);

y_temp = cell(10,1)
y = 0
while true
  for i = 1:10
    y_serial = str2num(char(srl_read(s1,4)))
    y_temp {i,1} = y_serial
  endfor
  y = cat(1, y, y_temp{1:10})
  plot(y)
  pause(1)
endwhile
srl_close(s1)
