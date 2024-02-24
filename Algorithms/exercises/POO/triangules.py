#1.- Diseñe una clase que represente un triángulo rectángulo y permita determinar el
#área, el perímetro, la hipotenusa y los ángulos del mismo a partir de sus dos catetos.
#Ejemplo:
#Entrada: 3, 4
#Salida: Área:6, Perímetro: 12, Hipotenusa 5

import math

class Triangles():
    """
    Triangle Calculator
    """
    
    def __init__(self, base, perpendicular) -> None:
        self.base = base
        self.perpendicular = perpendicular
        self.hypotenuse = 0
        self.calculate_hypotenuse()
        
    def calculate_hypotenuse(self):
        self.hypotenuse = math.sqrt( (self.base**2) + (self.perpendicular**2) )
        return self.hypotenuse
    
    def calculate_perimeter(self):
        return self.hypotenuse + self.perpendicular + self.base
    
    def calculate_area(self):
        
        return (self.base * self.perpendicular)/2
    
    def __str__(self) -> str:
        return f"Area: {self.calculate_area()} Perimeter: {self.calculate_perimeter()} Hypotenuse: {self.hypotenuse}"

triangle1 = Triangles(3, 4)

print(triangle1)

 
