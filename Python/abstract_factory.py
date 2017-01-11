class Dog:
    """ return type object """
    def speak(self):
        return "Woof!"

    def __str__(self):
        return 'Dog'

class DogFactory:
    """ Concrete factory """
    def get_pet(self):
        return Dog()

    def get_food(self):
        return "Dog food!"


class PetStore:
    def __init__(self,pet_factory=None):
        self._pet_factory=pet_factory

    def show_pet(self):

        pet = self._pet_factory.get_pet()
        pet_food = self._pet_factory.get_food()

        print("{} is your new pet".format(pet))
        print("{} says {}".format(pet,pet.speak()))
        print("{} likes to eat {}".format(pet,pet_food))



factory = DogFactory()
shop = PetStore(factory)
shop.show_pet()