
from design_patterns.creational.factory import get_pet
from design_patterns.creational.abstract_factory import CatFactory
from design_patterns.creational.abstract_factory import DogFactory
from design_patterns.creational.abstract_factory import PetStore

from design_patterns.creational.singleton import Singleton

from design_patterns.creational.builder import BMWBuilder
from design_patterns.creational.builder import Director

from design_patterns.creational.prototype import Car
from design_patterns.creational.prototype import Prototype

from design_patterns.creational.decorator import hello_world
from design_patterns.creational.decorator import hello_world_with_decorator


def decorator_pattern():
    hello_world()
    hello_world_with_decorator()

def factory_pattern():
    print("Factory pattern")
    c = get_pet("cat")
    print(c.speak())
    d = get_pet("dog")
    print(d.speak())

def abstract_factory_pattern():
    dog_factory = DogFactory()
    dog_shop = PetStore(dog_factory)
    cat_factory = CatFactory()
    cat_shop = PetStore(cat_factory)
    dog_shop.show_details()

def singleton_pattern():
    x = Singleton(google="www.google.com")
    print(x)
    y = Singleton(facebook = "www.facebook.com")
    print(x)

def builder_pattern():
    print("Building started!")
    builder = BMWBuilder()
    director = Director(builder)
    director.construct_car()
    new_car = director.get_car()
    print("Car built!")
    print(new_car)

def prototype_pattern():
    c = Car()
    prototype = Prototype()
    prototype.register_object('bmw',c)
    print(c)
    c1 = prototype.clone('bmw')
    print(c1)
    
