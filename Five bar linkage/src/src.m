clc;
clear all; 
close all;

% inputs
t = linspace(0, 10, 101); % more s for smoother animation
L1 = 0.2;
L2 = 0.4;
L3 = 0.2;
L4 = 0.3;
L5 = 0.3;
L6 = 0.1;
theta1 = linspace(pi*99/100, pi/9, length(t));
theta2 = linspace(pi*90/100, pi/50, length(t));

% animation
figure;
hold on;
C = solveC(theta2(1), L1, L6);
hL1 = plot([L6 C.x], [0 C.y], 'r-', 'LineWidth', 2);
D = solveD(theta1(1), L2);
hL2 = plot([0 D.x], [0 D.y], 'g-', 'LineWidth', 2);
E = solveE(C, D, L3, L4);
hL3 = plot([D.x E.x], [D.y E.y], 'c-', 'LineWidth', 2);
hL4 = plot([C.x E.x], [C.y E.y], 'm-', 'LineWidth', 2);
P = solveP(D, E, L3, L5);
hL5 = plot([E.x P.x], [E.y P.y], 'y-', 'LineWidth', 2);
hBP = plot(P.x, P.y, 'yo', 'MarkerFaceColor','y');
hL6 = plot([0 L6], [0 0], 'b-', 'LineWidth', 2);

axis([-1 1 -1 1]);
set(gca, 'YDir','reverse')
% 
% m = 1;
% mov(m) = getframe;

for ii=2:length(t)
    C = solveC(theta2(ii), L1, L6);
    set(hL1, 'XData', [L6 C.x]);
    set(hL1, 'YData', [0 C.y]);
    D = solveD(theta1(ii), L2);
    set(hL2, 'XData', [0 D.x]);
    set(hL2, 'YData', [0 D.y]);
    E = solveE(C, D, L3, L4);
    set(hL3, 'XData', [D.x E.x]);
    set(hL3, 'YData', [D.y E.y]);
    set(hL4, 'XData', [C.x E.x]);
    set(hL4, 'YData', [C.y E.y]);
    P = solveP(D, E, L3, L5);
    set(hL5, 'XData', [E.x P.x]);
    set(hL5, 'YData', [E.y P.y]);
    set(hBP, 'XData', P.x);
    set(hBP, 'YData', P.y);

    disp(double(P.x));
    disp(double(P.y));
    drawnow;
    % m = m + 1;
    % mov(m) = getframe;
end

% v = VideoWriter('video/animation1', 'MPEG-4');
% open(v);
% writeVideo(v, mov);
% close(v);


