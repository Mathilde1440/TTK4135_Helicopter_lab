data_struct = load("P_03_E_03.mat");


data = data_struct.all_variables;

time = data(1,:);
p_ref = data(2,:);
e_ref = data(3,:);
p_data = data(6,:);
e_data = data(8, :);


figure()
plot(time, p_ref );
hold on 
plot(time, p_data );
grid on
title("Pitch vs reference pitch");
legend("p_ref","p" );

figure()

plot(time, e_ref );
hold on 
plot(time, e_data );
grid on
title("Elevation vs reference elevation");
legend("e_ref","e" );
