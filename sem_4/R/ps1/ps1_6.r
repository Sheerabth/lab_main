library(lpSolve)

f.obj <- c(5000, 8500, 2400, 2800)

f.con <- matrix(c(1, 1, 1, 1,
                  1, 0, 0, 0,
                  0, 1, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1,
                  0, 0, 1, 1,
                  0, 0, 290, 380), nrow=7, byrow=TRUE)

f.dir <- c("<=", "<=", "<=", "<=", "<=", ">=", "<=")

f.rhs <- c(8000, 12, 5, 25, 20, 5, 1800)

lp1 <- lp("max", f.obj, f.con, f.dir, f.rhs)
lp1$solution