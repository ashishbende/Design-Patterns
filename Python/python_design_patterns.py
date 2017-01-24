""" This is the main application """


from design_patterns.design_patterns import abstract_factory_pattern
from design_patterns.design_patterns import builder_pattern
from design_patterns.design_patterns import singleton_pattern
from design_patterns.design_patterns import factory_pattern
from design_patterns.design_patterns import prototype_pattern
from design_patterns.design_patterns import decorator_pattern



def show_design_patterns():

    decorator_pattern()
    prototype_pattern()
    builder_pattern()
    singleton_pattern()
    factory_pattern()
    abstract_factory_pattern()
    
def main():
    print("---- Welcome ----")
    show_design_patterns()

if __name__ == "__main__": main() 