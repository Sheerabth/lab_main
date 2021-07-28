library(lpsolve)

cost <- matrix(c(10,14,16,13,12,13,15,12,9,12,12,11,14,16,18,16), nrow=4, byrow=TRUE)
lpass = lp.assign(cost, direction="min")

lpass$solution
lpass$objval