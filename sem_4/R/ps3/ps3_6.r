library(lpsolve)

cost <- matrix(c(80,55,45,45,58,35,70,50,70,50,80,65,90,70,40,80), nrow=4, byrow=TRUE)
lpass = lp.assign(cost, direction="max")

lpass$solution
lpass$objval