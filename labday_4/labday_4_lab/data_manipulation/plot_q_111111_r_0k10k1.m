
data_loads_day4;


data = data_q_111111_r_0k10k1;

time = data(1,:);

pitch_reference = data(2,:);
elevation_reference = data(3,:);
travel = data(4,:);
travel_rate = data(5,:);
pitch = data(6,:);
pitch_rate = data(7,:);
elevation = data(8,:);
elevation_rate = data(9,:);

figure(1);

p1 = plot(time,pitch_reference, 'r--', time, pitch, 'g' );
grid on
title('Pitch')
xlabel('[s]')
ylabel('[Degrees]')
legend( 'Pitch reference','Pitch')

p1(1).LineWidth = 3;
p1(2).LineWidth = 2;

figure(2);
p2 =plot(time,elevation_reference, 'r--', time, elevation, 'g' );
grid on
title('Elevation')
xlabel('[s]')
ylabel('[Degrees]')
legend('Elevation Reference', 'Elevation')

p2(1).LineWidth = 3;
p2(2).LineWidth = 2;

figure(3)
p3 = plot(time, travel, 'g' );
grid on
title('Travel')
xlabel('[s]')
ylabel('[Degrees]')
legend('Travel')
p3(1).LineWidth = 2;


figure(4);
p4 = plot(time, travel_rate, 'g' );
grid on
title('Travel_rate')
xlabel('[s]')
ylabel('[Degrees/s]')
legend('Travel_rate')

p4(1).LineWidth = 2;

figure(5);
p5 = plot(time, pitch_rate, 'g' );
grid on
title('Pitch rate')
xlabel('[s]')
ylabel('[Degrees/s]')
legend('Pitch rate')

p5(1).LineWidth = 2;


figure(6);
p6 = plot(time, elevation_rate, 'g' );
grid on
title('Elevation rate')
xlabel('[Degrees/s]')
ylabel('[Degrees]')
legend('Elevation rate')

p6(1).LineWidth = 2;
