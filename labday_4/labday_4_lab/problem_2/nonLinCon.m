function [c,ceq] = nonLinCon(z,alpha, beta,lambda_t,N,mx)

c = zeros(N,1);

for i = 1:N
c(i) = alpha*exp(-beta*(z(1 + (i-1)*mx) - lambda_t)^2) - z(5+ (i-1)*mx);
end
ceq = [];
end