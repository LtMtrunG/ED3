function point = solveE(C, D, L3, L4)
syms x y;
% Define the equations using the parameters
eq1 = (x - D.x)^2 + (y - D.y)^2 == L3.^2; 
eq2 = (x - C.x)^2 + (y - C.y)^2 == L4.^2; 

assume(x > D.x);

% Solve the equations
sol = solve([eq1, eq2], [x, y]);

% Check if solutions were found
if isempty(sol.x) || isempty(sol.y)
    error('No solutions found.');
end

% Create a point structure
if (sol.x(1) > sol.x(2))
    point.x = sol.x(1);
    point.y = sol.y(1);
else 
    point.x = sol.x(2);
    point.y = sol.y(2);
end
end
