clc;            % Clear command window
close all;      % Close all open figures
clear all;      % Clear all variables from the workspace

n = 10;         % Number of bits
b = [1 0 0 1 1 1 0 1 0 1];  % Binary message sequence
f1 = 1;         % Frequency for modulation when bit is 0
f2 = 2;         % Frequency for modulation when bit is 1
t = 0:1/30:1-1/30;  % Time vector with a sampling frequency of 30 Hz

% ASK Modulation
sa1 = sin(2*pi*f1*t);  % Sinusoidal signal for bit 1
E1 = sum(sa1.^2);      % Energy normalization
sa1 = sa1/sqrt(E1);     % Normalize the signal to have unit energy
sa0 = 0*sin(2*pi*f1*t); % Signal for bit 0 (zero amplitude)

% FSK Modulation
sf0 = sin(2*pi*f1*t);  % Signal for bit 0
E0 = sum(sf0.^2);      % Energy normalization
sf0 = sf0/sqrt(E0);     % Normalize the signal to have unit energy
sf1 = sin(2*pi*f2*t);   % Signal for bit 1
E1 = sum(sf1.^2);       % Energy normalization
sf1 = sf1/sqrt(E1);     % Normalize the signal to have unit energy

% PSK Modulation
sp = sin(2*pi*f1*t);    % Sinusoidal signal for bit 1
E1 = sum(sp.^2);        % Energy normalization
sp0 = -sin(2*pi*f1*t)/sqrt(E1);  % Signal for bit 0 with a 180-degree phase shift
sp1 = sin(2*pi*f1*t)/sqrt(E1);   % Signal for bit 1

% MODULATION
ask = []; psk = []; fsk = [];
for i = 1:n
    if b(i) == 1
        ask = [ask sa1];  % Append signal for bit 1 to ASK modulation sequence
        psk = [psk sp1];  % Append signal for bit 1 to PSK modulation sequence
        fsk = [fsk sf1];  % Append signal for bit 1 to FSK modulation sequence
    else
        ask = [ask sa0];  % Append signal for bit 0 to ASK modulation sequence
        psk = [psk sp0];  % Append signal for bit 0 to PSK modulation sequence
        fsk = [fsk sf0];  % Append signal for bit 0 to FSK modulation sequence
    end
end

figure(1)
subplot(411)
stairs(0:10, [b(1:10) b(10)], 'linewidth', 1.5)
axis([0 10 -0.5 1.5])
title('Message Bits'); grid on
xlabel('Time');
ylabel('Amplitude')

subplot(412)
tb = 0:1/30:10-1/30;
plot(tb, ask(1:10*30), 'b', 'linewidth', 1.5)
title('ASK Modulation'); grid on
xlabel('Time');
ylabel('Amplitude')

subplot(413)
plot(tb, fsk(1:10*30), 'r', 'linewidth', 1.5)
title('FSK Modulation'); grid on
xlabel('Time');
ylabel('Amplitude')

subplot(414)
plot(tb, psk(1:10*30), 'k', 'linewidth', 1.5)
title('PSK Modulation'); grid on
xlabel('Time');
ylabel('Amplitude')
