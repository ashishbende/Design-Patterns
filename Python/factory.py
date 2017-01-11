class Dog:
    """ a basic dog class """

    def __init__(self, name):
        self._name = name

    def speak(self):
        return '{} : Woof!'.format(self._name)


class Cat:
    """ a basic cat class """

    def __init__(self, name):
        self._name = name

    def speak(self):
        return '{} : Meow!'.format(self._name)


class Tiger:
    """ a basic tiger class """

    def __init__(self, name):
        self._name = name

    def speak(self):
        return '{} : Rawr!'.format(self._name)


def get_pet(pet="dog"):
    """ the factory method """
    pets = dict(dog=Dog('Bob'),cat=Cat('Tom'),tiger=Tiger('Simba'))
    return pets[pet]


d = get_pet('dog')
print(d.speak())

c = get_pet('cat')
print(c.speak())

t = get_pet('tiger')
print(t.speak())