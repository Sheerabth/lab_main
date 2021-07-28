library(lpSolve)
f.obj <- c(2,3)
f.con <- matrix(c(2,3,2,6), nrow=2, byrow=TRUE)
f.dir <- c("<=", "<=")
f.rhs <- c(8,18)
opt <- lp("max", f.obj, f.con, f.dir, f.rhs)

z <- opt$objval
sol <- opt$solution

cat("Optimal value is ", z)
cat("Optimal soln is ", sol[1], sol[2])

# Qn 1

dual <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)
dcons <- dual$duals
cat("Dual Prices", dcons[1], dcons[2])

# Qn 2

if (dcons[1] - 0.3 > 0) {
  print("Change is advisable")
} else {
  print("Change is not advisable")
}

# Qn 3

cat("If company pays ", dcons[2], " per unit of M2 company will have neither profit nor loss")

# Qn 4

dfrom <- dual$duals.from
dto <- dual$duals.to
newRHS2 = f.rhs[2] + 5
if (newRHS2 > dfrom && newRHS2 < dto) {
  change = dcons[2]*5
  print("Change in revenue ", z+change)
} else {
  print("Increase not possible")
}