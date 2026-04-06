%Data column order:

% 1. Time
% 2. Pitch reference
% 3. Elevation reference
% 4. Travel
% 5. Travel rate
% 6. Pitch
% 7. Pitch rate
% 8. Elevation 
% 9. Elevation rate

addpath('data')


% load datastructs and create data variables
data_struct_q0k12 = load("q_012");
data_q0k12 = data_struct_q0k12.All_variables;

data_struct_q1 = load("q_1");
data_q1 = data_struct_q1.All_variables;

data_struct_q1k2 = load("q_1k2");
data_q1k2 = data_struct_q1k2.All_variables;

data_struct_q12 = load("q_12");
data_q12 = data_struct_q12.All_variables;

