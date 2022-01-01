#!/usr/bin/env python
import math

def f(x):
  return (math.exp(math.cos(x))-math.pow(x,2))

def df(x):
  return (-math.exp(math.cos(x))*math.sin(x)-(2*x));

iterations = 15;
x = 0;
x0 = 1;
while abs(f(x0))>10e-3:
  x = x0 - (f(x0)/df(x0));
  erro = abs(x - x0)/abs(x);
  x0 = x;
  # print(x)


print("x = {}".format(x))
print("f(x) = {}".format(f(x)))
print("erro = {}".format(erro))
