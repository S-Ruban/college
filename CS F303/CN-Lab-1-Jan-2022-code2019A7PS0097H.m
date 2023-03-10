clc
t = 0:0.01:1;
V = 5 ;
R = 1 ;
C = 0.5 ;
ew = V * (1-exp(-t/(R*C)));
subplot(2, 1, 1);
stem(t, ew);
xlabel('time');
ylabel('amplitude');
title('Exponential Waveform');
ts = 1000;
t = 0:1/ts:0.2-1/ts;
f = 20 ;
sw = sawtooth(2*pi*f*t);
subplot(2, 1, 2);
stem(t, sw);
xlabel('Time');
ylabel('Amplitude');
title('Sawtooth Waveform');