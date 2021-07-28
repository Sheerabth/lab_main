library(lpSolve)

f.obj <- c(4, 5)

f.con <- matrix(c(1, 2,
                  6, 6,
                  1, 0), nrow=3, byrow=TRUE)

f.dir <- c("<=", "<=", "<=")

f.rhs <- c(10, 36, 4)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)

lp1$solution