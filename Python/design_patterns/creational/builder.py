""" used to build a complex object from many other objects """

class Director():
    """ orchestrates the build process """
    def __init__(self, builder):
        self._builder = builder
    
    def construct_car(self):
        self._builder.create_new_car()
        self._builder.add_model()
        self._builder.add_engine()
        self._builder.add_tires()

    def get_car(self):
        self._builder.car
          
class Builder():    
    """Abstract builder class"""

    def __init__(self): 
        self.car = None

    def create_new_car(self):
        self.car = Car()

class Car():
    """ Product """
    def __init__(self):
        self.model = None
        self.engine = None
        self.tires  = None
    
    def __str__(self):
        return "{} | {} | {} ".format(self.model,self.tires,self.engine)

    
class BMWBuilder(Builder):
    """Concrete builder"""
    def add_model(self):
        self.car.model = "BMW"
    
    def add_tires(self):
        self.car.tires = "Regular Tires"

    def add_engine(self):
        self.car.engine = "Turbo engine"