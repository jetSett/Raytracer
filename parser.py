#!/usr/bin/env python
import os
import sys
import re
import argparse

def error(er_msg):
    raise BaseException("Error : " + er_msg)

def delete_empty_lines(s):
    return [x for x in s if x != ""]

def is_a_label(line):
    return (line[-1]==":")

def convert_tuple(string):
    """ converts a string of form "(a,b,...)" into a list ["a","b",...] """
    return string[1:][:-1].split(",")

def parse_object(f,i):
    """ parse the object definition that starts at line i in f """
    val = {}
    sphere_check = ["type","material","center","radius"]
    plane_check = ["type","material","origin","normal"]
    triangle_check = ["type","material","p1","p2","p3"]
    lamppoint_check = ["type","pos",]
    x = i+1
    while not is_a_label(f[x]):
        string = f[x].split('=')
        val[string[0]]=string[1]
        x+=1


def parse(s_file):
    """
    Goes through the code and generates a list of tuple
    """
    parameters_check = ["name","width", "height", "nb_objects", "nb_displayer", "layout"]
    parameters = {}
    code = []
    line = 0

    filename = os.path.join("scenery",(s_file+".scn"))
    f = open(filename)
    source = [x[:-1].split(";")[0] for x in f.readlines()] #extract a list of lines without the \n
    f.close()

    # break before and after the #OBJECTS token
    i=0
    nb_lines = len(source)
    while i<= nb_lines:
        if i == nb_lines :
            return error("No #OBJECTS token found")
        elif source[i]=="#OBJECTS" :
            break
        i+=1

    before,after = delete_empty_lines(source[:i]) , delete_empty_lines(source[i+1:])
    # before = global parameters ; after = object description

    # Now parsing the parameters
    for line in before :
        param,value = line.split("=")
        if param not in parameters_check:
            return error("in preamble, don't know what to do with '"+param+"' parameter")
        parameters[param]=value
        parameters_check.remove(param)
    if parameters_check :
        missing = ""
        for x in parameters_check :
            missing += x+", "
        return error("in preamble, parameters are missing : \n" + missing)

    name = parameters["name"]
    nb_objects = int(parameters["nb_objects"])
    width = int(parameters["width"])
    height = int(parameters["height"])
    nb_displayer = int(parameters["nb_displayer"])
    layout = convert_tuple(parameters["layout"])
    layout_i = int(layout[0])
    layout_j = int(layout[1])
    code.append((name,nb_objects, width, height, nb_displayer, layout_i, layout_j))
    # Configuration is done,
    # now parsing the objects
    i=0
    """
    for source_line in after:
        if is_a_label(source_line):
            code.append(parse_object(after,i))
        i+=1
    """
    print("\n DONE \n")
    return code

## ------ main ------
if __name__ == '__main__':

    argparser = argparse.ArgumentParser(description='A parser for a scenery description langage. raytracer Project, Projet1 L3IF 2016 @ENS Lyon')
    argparser.add_argument('filename', help='name of the source file.  "python parser.py toto.scn" assembles toto.scn')

    options=argparser.parse_args()
    code = parse(options.filename)
