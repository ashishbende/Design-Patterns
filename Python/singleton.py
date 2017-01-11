class Borg:
    """This class makes class atributes global"""

    # let's define attribute dictionary
    _shared_state = {}

    def __init__(self):
        self.__dict__ = self._shared_state


class Singleton(Borg):
    def __init__(self, **kwargs):
        Borg.__init__(self)
        self._shared_state.update(kwargs)

    def __str__(self):
        return str(self._shared_state)


scenario1 = Singleton(GMAP="Game map")
print(scenario1)

scenario2 = Singleton(CMAP="Character map")
print(scenario2)
