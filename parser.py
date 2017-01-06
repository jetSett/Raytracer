#!/usr/bin/env python
import os
import sys
import re
import argparse

## --------- values ---------

types = {"Sphere" : 0 ,
         "Triangle" : 1,
         "Plane" : 2,
         "LampPoint" : 3,
         "Camera" : 4}

materials = { "ColorGreen" : 0,
              "ColorRed" : 1,
              "ColorYellow" : 2,
              "ColorCyan" : 3,
              "ColorMagenta" : 4,
              "ColorBlue" : 5
            }

## --------- utility functions -----------

def error(er_msg):
    raise BaseException("Error : " + er_msg)

def delete_empty_lines(s):
    return [x for x in s if x != ""]

def is_a_label(line):
    return (line[-1]==":")

def convert_tuple(s):
    return s[1:-1].split(",")

def get_rid_of_indent(s):
    l = re.findall('[\S]+', s)
    return l[0]

## -------- parsing functions -----------

def parse_object(obj):
    """ parse the object definition """
    typ = obj[1].split("=")[1]
    if typ == "Sphere" :
        return parse_object_with_type(obj, ["type","material","center","radius"])
    elif typ == "Triangle" :
        return parse_object_with_type(obj, ["type","material","p1","p2","p3"])
    elif typ == "Plane" :
        return parse_object_with_type(obj, ["type","material","origin","normal"])
    elif typ == "LampPoint" :
        return parse_object_with_type(obj, ["type","pos"])
    elif typ == "Camera" :
        return parse_object_with_type(obj, [])
    else :
        return error(" Type '"+ typ +"' is incorrect. Types should be in " + str(types.keys()))

def parse_object_with_type(obj,check):
    order =[x for x in check]
    name = obj[0]
    arguments = {}
    for line in obj[1:] : # gettinf rid of the object name
        arg,value = line.split("=")
        print(arg,value)
        if arg not in check:
            return error("while parsing object '" + name + "' , don't know what to do with '"+param+"' parameter")
        if arg == "type" :
            arguments[arg]= types[value]
        elif arg == "material" :
            arguments[arg]= materials[value] # changing string to int coding
        else :
            arguments[arg]=value
        check.remove(arg)
    if check :
        missing = ""
        for x in check :
            missing += x+", "
        return error("while parsing object '" + name + "' , parameters went missing : \n" + missing)
    return tuple([arguments[x] for x in order])

def parse(s_file):
    """
    Goes through the code and generates a list of tuple
    """

    # ------ initialisation ------
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

    print "------ Now parsing the parameters -------"
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


    print "------ now parsing the objects ------"
    # detecting objects labels and splitting the datas
    labels = []
    for i in range(len(after)):
        if is_a_label(after[i]):
            labels.append(i)
    # now retrieving the datas and parsing them
    for i in range(len(labels)-1):
        an_object = after[labels[i]:labels[i+1]]
        an_object = [get_rid_of_indent(line) for line in an_object]
        code.append(parse_object(an_object))
    # Don't forget the last one
    an_object = after[labels[-1]:]
    an_object = [get_rid_of_indent(line) for line in an_object]
    code.append(parse_object(an_object))
    print "Parsing DONE"
    print(code)
    return code

## ------ main ------
if __name__ == '__main__':

    argparser = argparse.ArgumentParser(description='A parser for a scenery description langage. raytracer Project, Projet1 L3IF 2016 @ENS Lyon')
    argparser.add_argument('filename', help='name of the source file.  "python parser.py toto.scn" assembles toto.scn')

    options=argparser.parse_args()
    code = parse(options.filename)
    """
    f = open("file.obj",'w')
    for x in code :
        f.write(x)
    f.close()
    """
