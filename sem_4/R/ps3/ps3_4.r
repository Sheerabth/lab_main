library(lpsolve)

cost <- matrix(c(17,25,31,10,25,16,12,14,11), nrow=3, byrow=TRUE)
lpass = lp.assign(cost, direction="min")

lpass$solution
lpass$objval