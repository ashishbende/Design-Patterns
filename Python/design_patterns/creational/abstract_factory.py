""" Used when client expects a family of related object but don't know which family until runtime """

class Dog:
    def speak(self):
        return "Woof!"
    def __str__(self):
        return "Dog"

class Cat:
    def speak(self):
        return "Meow!"
    def __str__(self):
        return "Cat"

class CatFactory:
    """Abstract cat factory"""
    def get_pet(self):
        return Cat()
    def get_food(self):
        return "Cat food"

class DogFactory:
    """ Abstract Factory """

    def get_pet(self):
        return Dog()
    def get_food(self):
        return  "Dog Food"

class PetStore:
    """ houses abstract factory """
    def __init__(self, pet_factory = None):
        """ pet factory is abstract factory """
        self._pet_factory = pet_factory

    def show_details(self):
        pet = self._pet_factory.get_pet()
        pet_food = self._pet_factory.get_food()

        print("Pet : {}".format(pet))
        print("Pet says: {}".format(pet.speak()))
        print("Pet likes to eat : {}".format(pet_food))
    