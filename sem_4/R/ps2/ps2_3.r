library(lpSolve)
f.obj <- c(20,50,35)
f.con <- matrix(c(1,-1,-1,1,0,0,2,4,3), nrow=3, byrow=TRUE)
f.dir <- c(">=", "<=", "<=")
f.rhs <- c(0,75,240)
# Qn 1

opt <- lp("max", f.obj, f.con, f.dir, f.rhs)
z <- opt$objval
sol <- opt$solution

cat("Optimal value is", z)

# Qn 1

cat("Optimal soln is", sol[1], sol[2], sol[3])

# Qn 2

dual <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)
cat("Dual price of raw material", dual$duals[3])
cat("Dual price range of raw material", dual$duals.from[3], dual$duals.to[3])

if (dual$duals.from[3] < f.rhs[3] + 120 && f.rhs[3] + 120 < dual$duals.to[3]) {
  change = 120*dual$duals[3]
  cat("Change in toltal revenue", change)
  newOpt <- lp("max", f.obj, f.con, f.dir, c(f.rhs[1], f.rhs[2], f.rhs[3]+120))
  newSol <- newOpt$solution
  cat("New solution is", newSol)
} else {
  print("Change not possible")
}

# Qn 3

if (dual$duals.from[2] < f.rhs[2] + 10 && f.rhs[2] + 10 < dual$duals.to[2]) {
  change = 10*dual$duals[2]
  cat("Change in toltal revenue", change)
  if (change == 0) {
    print("No change in revenue")
  } else {
    print("New revenue", z+change)
  }
} else {
  print("Change not possible")
}

if (dual$duals.from[2] < f.rhs[2] - 10 && f.rhs[2] - 10 < dual$duals.to[2]) {
  change = 10*dual$duals[2]
  cat("Change in toltal revenue", change)
  if (change == 0) {
    print("No change in revenue")
  } else {
    print("New revenue", z-change)
  }
} else {
  print("Change not possible")
}