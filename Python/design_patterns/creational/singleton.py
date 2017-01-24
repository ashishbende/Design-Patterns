""" When we want to create only one object in the class """
class Borg:
    _shared_state = dict()
    def __init__(self):
        self.__dict__ = self._shared_state

class Singleton(Borg):
    def __init__(self,**kwargs):
        Borg.__init__(self)
        self._shared_state.update(kwargs)
    def __str__(self):
        return str(self._shared_state)