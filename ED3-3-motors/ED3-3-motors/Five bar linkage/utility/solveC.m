function point = solveC(theta1, L1, L6)
syms x y;
% Define the equations using the parameters
eq1 = 2*L6*x - 2*L6.^2 == -2*L6*L1*cos(sym(pi-theta1)); 
eq2 = (L6 - x)^2 + y^2 == L1.^2; 

assume(y > 0);

% Solve the equations
sol = solve([eq1, eq2], [x, y]);

% Check if solutions were found
if isempty(sol.x) || isempty(sol.y)
    error('No solutions found.');
end

% Create a point structure
point.x = sol.x;
point.y = sol.y;
end
