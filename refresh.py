# Python CheatSheat
# https://colab.research.google.com/drive/13R6Qbdv1BbPxYftSupZBPLRbOCbPEuIb?usp=sharing#scrollTo=iU2U3w8ksV48
# https://colab.research.google.com/drive/1rL8jOwylJCKkmmp_8mySYVXT-yGKO_Y5?usp=sharing

# LAMBDA with CONDITIONs
# lambda <arguments> : <Return Value if condition is True> if <condition> else <Return Value if condition is False>
# SAMPLE

test =  lambda x : True if (x > 10 and x < 20) else False
print( test(23) )

# Understanding the lamdam expression 
def whatToDo(name = str, email = str ):
    
    print(f"Hi {name}, we all happy for your election.")
    print("At the end of the process, we will be providing a function to validate your email:")
    print(f"Email: {email}")
    
    return lambda status = False:  f"Your email '{email}' is actived." if (status) else f"Your email '{email}' is deactived."


result = whatToDo("John", "jonh@gmail.com")

print( result() )


#FILTER

listofNum = [1,3,33,12,34,56,11,19,21,34,15]

newList = list( filter( lambda num : num > 33, listofNum ) )
print(newList)

mappedList = list( map( lambda value: value*2, newList ) )
print(mappedList)

users = [
    {
        "name" : "Juan Toscano",
        "status" : True
    },
    {
        "name" : "Stephen Curry",
        "status" : True
    },
    {
        "name" : "Klay Thomson",
        "status" : True
    },
    {
        "name" : "Jalen Brown",
        "status" : False
    },
    {
        "name" : "Jason Tatum",
        "status" : False
    }
    
]


active_users = list( filter( lambda user: user["status"] == True, users ) )
print( active_users )

# Iterables
nums = [2,3,23,34,231,5352,32,56,73,78,10 ]

even_numbers = [ i for i in nums if i%2 == 0 ]

print(even_numbers)


# Generators -> I iterate its values when I need.

def odd_generator(odds = []):
    
    for i in odds:
        
        if i%2 != 0:
            yield i
            
# Now I can iterate this odd_generator as I need
odd_numbers = odd_generator(nums)

    # First do some stuff ....
    # ...
    
print( next( odd_numbers ) )
print( next( odd_numbers ) )

print("\n")

# Also I can Iterate in a bucle
for x in odd_generator( [1,2,3,5,6,7,8,9,10] ):
    print(x)



# Factorial
def factorial(n):
    if n == 1: return 1
    return n * factorial(n - 1)

factorial(6)


# Argumentos claves #Annotations

def presentar(nombre: str, edad: int, color: str ="Azul", frutas: list =[]) -> str:
  """
  Descripción
  -----------
  Esta función presenta a individuos
  https://es.wikipedia.org/wiki/Individuo
  """
  print(
f"""
Su nombre es {nombre}, tiene {edad} años de edad.
Su color favorito es {color}.""" )
  
  if frutas:
    print(f"Sus frutas favoritas son: {', '.join(frutas)}")

  return "Adiós"

presentar("Carlos", 21, frutas=["Mango", "Fresa"], color="Rojo")
