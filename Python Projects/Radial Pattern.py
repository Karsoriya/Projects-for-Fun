import turtle
import math as m
import random

fire_colors = [
    "#FFFFFF", "#FFF8E7", "#FFEFD5", "#FFE4B5", "#FFD700",  
    "#FFC800", "#FFB700", "#FFA500", "#FF9400", "#FF8200",  
    "#FF6F00", "#FF5C00", "#FF4500", "#FF2A00", "#FF1100",  
    "#FF0000", "#E00000", "#C80000", "#B00000", "#990000",  
    "#820000", "#6B0000", "#550000", "#400000", "#2A0000",  
    "#200000", "#180000", "#100000", "#080000", "#000000"   
]

t=turtle.Turtle()

def sq():
    t.forward(100)
    t.right(90)
    t.forward(200)
    t.right(90)
    t.forward(200)
    t.right(90)
    t.forward(200)
    t.right(90)
    t.forward(100)

def shape():
    for x in range(0, 20):
        for y in range(0, 20):
            thickness = int(m.sqrt(x**2 + y**2)/2.357)
            t.color(fire_colors[thickness])
            t.width(0.1)
            t.circle(10*x + 1)
            t.right(45)      
        
shape()

t.penup()
t.goto(0, 250)
t.setheading(180)
t.pendown()
t.color("black")

t.fillcolor("black")
t.begin_fill()
for i in range(0, 90):
    t.color("white")
    t.forward(4.4)
    sq()
    t.left(4)