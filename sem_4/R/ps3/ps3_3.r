library(lpSolve)

cost <- matrix(c(5,7,6,2,3,5),nrow=2,byrow=TRUE)
row.signs <- rep("=",2)
row.rhs <- c(60,40)
col.signs <- rep(">=",3)
col.rhs <- c(50,30,20)

lptrans <- lp.transport(cost, "max", row.signs, row.rhs, col.signs, col.rhs)

lptrans$solution
lptrans$objval