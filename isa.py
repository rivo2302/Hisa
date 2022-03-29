# -*- coding: utf-8 -*-

"""
    Isa : Python module that translates a number
    into Malagasy letters 

    Author : rivo2302 | www.rivo.iteam-s.mg
"""

import sys

class Isa :
    """
       The class that contains each method of the model.
    """
    def __init__(self,item) :
        if item.isdigit() == False :
            print(f"Error : The argument must be an integer")
            sys.exit()


rivo = Isa("79")