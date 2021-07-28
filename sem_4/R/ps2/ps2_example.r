library(lpSolve)
f.obj <- c(30,20)
f.con <- matrix(c(2,1,1,3), nrow=2, byrow=TRUE)
f.dir <- c("<=", "<=")
f.rhs <- c(8,8)
opt <- lp("max", f.obj, f.con, f.dir, f.rhs)

z <- opt$objval
sol <- opt$solution

cat("Optimal value is ", z)
cat("Optimal soln is ", sol[1], sol[2])

# Qn 1 

dual <- lp("max", f.obj, f.con, f.dir, f.rhs, compute.sens=TRUE)
dcons <- dual$duals
if (dcons[1] > dcons[2]){
  print("Machine 1 has higher priority")
} else {
  print("Machine 2 has higher priority")
}

# Qn 2

netRev1 = dcons[1] - 10
netRev2 = dcons[2] - 10

if (netRev1 > 0) {
  print("Machine 1 advisable")
} else {
  print("Machine 1 not advisable")
}

if (netRev2 > 0) {
  print("Machine 2 advisable")
} else {
  print("Machine 2 not advisable")
}

# Qn 3

dfrom <- dual$duals.from
dto <- dual$duals.to
newHour1 = 13
if (newHour1 > dfrom[1] && newHour1 < dto) {
  print("Increase Possible")
  incr = dcons[1]*(newHour1 - f.rhs[1])
  cat("New optimum value", z+incr)
} else {
  print("Increase not possible")
}

# Qn 4

dfrom <- dual$duals.from
dto <- dual$duals.to
newHour1 = 20
if (newHour1 > dfrom[1] && newHour1 < dto) {
  print("Increase Possible")
  incr = dcons[1]*(newHour1 - f.rhs[1])
  cat("New optimum value", z+incr)
} else {
  print("Increase not possible")
}

# Qn 5
sfrom <- dual$sens.coef.from
sto <- dual$sens.coef.to
newCost1 = 35
newCost2 = 25
if (newCost1 > sfrom[1] && newCost1 < sto[1] && newCost2 > sfrom[2] && newCost2 < sto[2]) {
  print("Optimum remains same")
} else {
  print("Optimum changes")
}

