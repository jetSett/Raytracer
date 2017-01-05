#!/usr/bin/env python
import os
import sys
import re
import argparse

def error(line, er_msg):
    raise BaseException("Error at line " + str(line) + " : " + er_msg)

def parse(s_file):
    """
    Goes through the code and generate a dict
    """
    global line
    global labels
    objects = {}
    lights = {}
    parameters = {}
    address = 0
    source = open(s_file)
    for source_line in source:
        tokens = re.findall('[\S]+', source_line) # \S means: any non-whitespace
        #print(tokens)  # to debug
        # if there is a label, consume it
        if tokens:
            token=tokens[0]
            if token[-1] == ":": # last character
                label = token[0: -1] # all the characters except last one
                labels[label] = current_address #new label to jump to
                tokens = tokens[1:]

        line += 1

    source.close()
    print("\n DONE \n")
    return code,current_address

## ------ main ------
if __name__ == '__main__':

    argparser = argparse.ArgumentParser(description='A parser for a scenery description langage. raytracer Project, Projet1 L3IF 2016 @ENS Lyon')
    argparser.add_argument('filename', help='name of the source file.  "python parser.py toto.scn" assembles toto.scn')

    options=argparser.parse_args()
    filename = options.filename
    filename = os.path.join("ASM",filename)
    basefilename, extension = os.path.splitext(filename)
    obj_file = os.path.split(basefilename)[-1]+".obj"
    asm_pass(1, filename) # first pass essentially builds the labels
    code = asm_pass(2, filename)[0] # second pass is for good
    outfile = open(obj_file, "w")
    for instr in code:
        outfile.write(format(instr, "04x"))
        outfile.write("\n")
    outfile.close()
