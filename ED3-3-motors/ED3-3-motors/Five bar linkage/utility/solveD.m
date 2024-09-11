function point = solveD(theta1, L2)
syms x y;
% Define the equations using the parameters
eq1 = x == L2*cos(sym(theta1)); 
eq2 = x^2 + y^2 == L2.^2; 

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
