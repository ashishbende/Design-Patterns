import copy

class Prototype():
    def __init__(self):
        self._objects = {}
    
    def register_object(self,name,obj):
        self._objects[name] = obj
    
    def unregister_object(self,name):
        del self._objects[name]

    def clone(self,name,**attr):
        obj = copy.deepcopy(self._objects.get(name))
        obj.__dict__.update(attr)
        return obj

class Car():
    def __init__(self):
        self.name = "BMW"
        self.color = "Red"
        self.engine = "Turbo"

    def __str__(self):
        return "{}".format(self.name)
