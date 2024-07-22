clc;clear all; close all;

% inputs
t=0:0.1:10;
L1 = 0.6;
L2 = 0.5;
theta1=pi*cos(2*t)/3+sin(t);
theta2=pi*cos(2*t)/6-2*sin(t);

% animation
figure;
hL1 = plot([0 L1*sin(theta1(1))], [0 -L1*cos(theta1(1))], 'r-', 'LineWidth', 2);
hold on;
hB1 = plot(L1*sin(theta1(1)), -L1*cos(theta1(1)), 'bo', 'MarkerFaceColor','b');
hL2 = plot([L1*sin(theta1(1)) L1*sin(theta1(1))+L2*sin(theta2(1))], ...
    [-L1*cos(theta1(1)) -L1*cos(theta1(1))-L2*cos(theta2(1))], 'g-', 'LineWidth', 2);
hB2 = plot(L1*sin(theta1(1))+L2*sin(theta2(1)), -L1*cos(theta1(1))-L2*cos(theta2(1)), 'ko', 'MarkerFaceColor','k');
axis([-1.5 1.5 -1.5 1.5]);

for ii=2:length(t)
    set(hL1, 'XData', [0 L1*sin(theta1(ii))]);
    set(hL1, 'YData', [0 -L1*cos(theta1(ii))]);
    set(hB1, 'XData', L1*sin(theta1(ii)));
    set(hB1, 'YData', -L1*cos(theta1(ii)));
    set(hL2, 'XData', [L1*sin(theta1(ii)) L1*sin(theta1(ii))+L2*sin(theta2(ii))]);
    set(hL2, 'YData', [-L1*cos(theta1(ii)) -L1*cos(theta1(ii))-L2*cos(theta2(ii))]);
    set(hB2, 'XData', L1*sin(theta1(ii))+L2*sin(theta2(ii)));
    set(hB2, 'YData', -L1*cos(theta1(ii))-L2*cos(theta2(ii)));
    drawnow;
    pause(0.05); % Pause for 0.05 seconds
end
