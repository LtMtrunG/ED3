% Clear workspace and command window
clear;
clc;


% Create a joystick object for the first joystick
joy = vrjoystick(1);

% Display joystick information
disp('Joystick connected:');
disp(vrjoystick(1));

% Specify the axis number you want to read (e.g., 1 for the first axis)
x = 1; % Change this value based on the axis you want to check
y = 2;
z = 3;

% Loop to continuously read joystick input
try
    while true
        % Read the status of the specified axis
        ax = axis(joy, x); % Read the x axis of the controller
        ay = axis(joy, y); % Read the y axis of the controller
        az = axis(joy, z); % Read the z axis of the controller


        disp(ax);
        disp(ay);
        disp(az);
        % Display the axis value
        fprintf('Axis x value: %.2f\n', ax);
        fprintf('Axis y value: %.2f\n', ay);
        fprintf('Axis z value: %.2f\n', az);

        % Pause for a short duration to avoid flooding the console
        pause(0.1);
    end
catch ME
    disp('Exiting joystick input loop.');
    disp(ME.message);
end

% Clean up
delete(joy);