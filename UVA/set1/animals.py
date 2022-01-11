def main():
  
    animals = [] 
    dicc = {}
    N = input ("Se va a insertar: ");
    
    for i in (0, N):
       specie = input ("Especie: ")
       poblation = input ("Población: ")
       ubication = input ("Ubicación: ")
       
       animals.append({'Especie': specie , 'Población' : poblation , 'Ubicación' : ubication })
       
    for e in animals:
      print(e);

if __name__ == '__main__':
    main()
