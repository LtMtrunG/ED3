function point = solveP(D, E, L3, L5)
    % Parametric solutions
    t1 = 1 + L5 / L3;
    t2 = 1 - L5 / L3;

    % Calculate points
    P1 = [D.x, D.y] + t1 * ([E.x, E.y] - [D.x, D.y]);
    P2 = [D.x, D.y] + t2 * ([E.x, E.y] - [D.x, D.y]);

    % Calculate the distances from D to P1 and P2
    distD_P1 = sqrt((D.x - P1(1))^2 + (D.y - P1(2))^2);
    distD_P2 = sqrt((D.x - P2(1))^2 + (D.y - P2(2))^2);

    % Return points
    if (distD_P1 > distD_P2)
        point.x = P1(1);
        point.y = P1(2);
    else 
        point.x = P2(1);
        point.y = P2(2);
    end
end