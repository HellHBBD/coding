from gurobipy import *
model = Model()
x1 = model.addVar(name = 'x1')
x2 = model.addVar(name = 'x2')
x3 = model.addVar(name = 'x3')
model.update()
model.addConstr(2*x1-2*x2+3*x3<=5)
model.addConstr(x1+x2-x3<=3)
model.addConstr(x1-x2+x3<=2)
model.setObjective(x1-x2+2*x3, GRB.MAXIMIZE)
model.optimize()
for i in model.getVars():
    print(i.VarName, i.X)
