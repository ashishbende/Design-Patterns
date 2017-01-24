""" Encapsulates object creation. Use when you are unsure what types of object you will need eventually
    or what classes to use is decided at the runtime.
 """

class Dog:
    """ Simple dog class """

    def __init__(self, name):
        self._name = name
    def speak(self):
        return "Woof!"

class Cat:
    """ Simple dog class """

    def __init__(self, name):
        self._name = name

    def speak(self):
        return "Meow!"

def get_pet(pet='dog'):
    """ factory method """
    pets = dict(dog = Dog("Bob"),cat = Cat("Tom"))
    return pets[pet]