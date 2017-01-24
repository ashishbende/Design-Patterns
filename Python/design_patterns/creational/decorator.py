from functools import wraps

def make_blink(function):
    @wraps(function)
    def decorator():
        ret = function()
        return "<blink>" + ret +"</blink>"
    return decorator


def hello_world():
    return "Hello, World"

@make_blink
def hello_world_with_decorator():
    return "Hello, World"
        