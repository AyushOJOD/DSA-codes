clc;            % Clear command window
close all;      % Close all open figures
clear all;      % Clear all variables from the workspace

n = input('Enter n value for n-bit PCM system: ');  % User input for the number of bits in PCM system
n1 = input('Enter number of samples in a period: ');  % User input for the number of samples in a period

L = 2^n;        % Number of quantization levels

x = 0:2*pi/n1:4*pi;  % Time vector for the analog signal
s = 8*sin(x);   % Analog signal (8*sin(x))

subplot(3,1,1);
plot(s);
title('Analog signal');
ylabel('Amplitude--->')
xlabel('Time--->');

subplot(3,1,2);
stem(s);
grid on;
title('Sampled signal');
ylabel('Amplitude--->');
xlabel('Time--->');

vmax = 8;       % Maximum amplitude of the signal
vmin = -vmax;   % Minimum amplitude of the signal
del = (vmax - vmin) / L;  % Quantization step size
part = vmin:del:vmax;     % Partition levels for quantization
code = vmin - (del/2):del:vmax + (del/2);  % Quantization codes

[ind, q] = quantiz(s, part, code);  % Quantization of the sampled signal

l1 = length(ind);
l2 = length(q);

for i = 1:l1
    if (ind(i) ~= 0)
        ind(i) = ind(i) - 1;
    end
    i + 1;
end

for i = l2
    if (q(i) == vmin - (del/2))
        q(i) = vmin + (del/2);
    end
end

subplot(3,1,3);
stem(q);
grid on;
title('Quantized signal');
ylabel('Amplitude---->');
xlabel('Time--->');

% figure;
code = de2bi(ind, 'left-msb');
k = 1;
for i = 1:l1
    for j = 1:n
        coded(k) = code(i, j);
        j = j + 1;
        k = k + 1;
    end
    i = i + 1;
end

subplot(2,1,1);
grid on;
stairs(coded);
axis([0 100 -2 3]);
title('Encoded signal');
ylabel ('Amplitude--->');

qunt = reshape(coded, n, length(coded)/n);  % Reshape the coded signal for demodulation
index = bi2de(qunt', 'left-msb');  % Convert binary code back to quantization indices
q = del * index + vmin + (del/2);  % Reconstruct the demodulated signal

subplot(2,1,2);
grid on;
plot(q);
title('Demodulated signal');
ylabel('Amplitude--->');
xlabel ('Time---->');

