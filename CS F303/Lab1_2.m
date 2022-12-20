% Verification of sampling theorem
t=-100:01:100; fm=0.02; x=cos(2*pi*t*fm); subplot(2,2,1); plot(t,x);
xlabel('time in sec'); ylabel('x(t)'); title('continuous time signal');
n=-2:2; fs1=0.02; x1=cos(2*pi*fm*n/fs1); subplot(2,2,2); stem(n,x1); hold on; subplot(2,2,2); plot(n,x1,':'); title('discrete time signal x(n) with fs<2fm'); xlabel('n'); ylabel('x(n)');
n1=-4:4; fs2=0.04; x2=cos(2*pi*fm*n1/fs2); subplot(2,2,3); stem(n1,x2); hold on; subplot(2,2,3); plot(n1,x2,':'); title('discrete time signal x(n) with fs>2fm'); xlabel('n');
ylabel('x(n)');
n2=-50:50; fs3=0.5; x3=cos(2*pi*fm*n2/fs3); subplot(2,2,4); stem(n2,x3); hold on;
subplot(2,2,4); plot(n2,x3,':'); xlabel('n');ylabel('x(n)');
title('discrete time signal x(n) with fs=2fm');
x=input('enter the sequence : ');
h=input('enter the imp response : '); % no of samples in x
n1=length(x); n2=length(h); n3=n1+n2-1; n=max(n1,n2);
if(n3>=0)
h=[h,zeros(1,n3)];
else
x=[n,zeros(1,-n3)];
end;
for a =1:n y(a)=0;
for i=1:n j=a-i+1;
if(j<=0) j=n+j;
end;
y(a)=y(a)+[x(i)*h(j)];
end;
end;
t=1:n; stem(t,y); disp(y); title('circular convolution'); xlabel('samples'); ylabel('amplitude');