%basic understating of plots
f0=1000;%Freqyency of sin
fs1=10000;%Sampling Frequency Fs>2Fm
fs2=1500;%Sampling Frequency Fs<2Fm
n=0:1:50;
x=cos(2*pi*f0*n/fs1);
x1=cos(2*pi*f0*n/fs2);
figure (1)
subplot(2,1,1)
plot(n,x)
subplot(2,1,2)
hold on
plot(n,x)
stem(n,x,'r')
plot(n,x1,'g')
legend('Original function','Sampling With Fs>2Fm','Sampling With Fs<2Fm')
figure (2)
hold on
% sine wave
t=0:0.01:1; a=2; b=a*sin(2*pi*2*t); subplot(3,3,1); stem(t,b); xlabel('time'); ylabel('Amplitude'); title('sinewave');
% Cosine wave
t=0:0.01:1; a=2; b=a*cos(2*pi*2*t); subplot(3,3,2); stem(t,b); xlabel('time'); ylabel('Amplitude'); title ('Coswave');
% Square wave
t=0:0.01:1; a=2; b=a*square(2*pi*2*t); subplot(3,3,3); stem(t,b); xlabel('time'); ylabel('Amplitude'); title('square wave');
% unit impulse
n=-5:5; a = [zeros(1,5),ones(1,1),zeros(1,5)]; subplot(3,3,4); stem(n,a); xlabel ('time');
ylabel ('amplitude'); title('Unit impulse');
% unit step signal
n=-5:5; a = [zeros(1,5),ones(1,6)]; subplot(3,3,5); stem(n,a); xlabel ('time'); ylabel ('amplitude'); title('Unit step');