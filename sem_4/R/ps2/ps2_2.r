library(lpSolve)
f.obj <- c(8,5)
f.con <- matrix(c(1,0,0,1,2,1), nrow=3, byrow=TRUE)
f.dir <- c("<=", "<=")
f.rhs <- c(150,200,400)
# Qn 1

opt <- lp("max", f.obj, f.con, f.dir, f.rhs)
z <- opt$objval
sol <- opt$solution

cat("Optimal value is", z)
cat("Optimal soln is", sol[1], sol[2])

# Qn 2

dual <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)
cat("Dual Price of produciton capacity of type 2 hat", dual$duals[3])

# Qn 3
if (dual$duals.from[1] < 120 && 120 < dual$duals.to[1]) {
  change = (f.rhs[1]-120)*dual$duals[1]
  if (change == 0) {
    print("No change in optimum")
  } else {
    cat("New optimum is ", z-change)
  }
} else {
  print("Change not possible")
}

# Qn 4
cat("Dual Price of Market share of type 2 hat", dual$duals[1])
cat("Maximum increase we can have for type 2 hat is", dual$duals.to[2]-f.rhs[2])
