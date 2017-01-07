#include "parse.hpp"
#include <string>
#include <assert.h>

using namespace boost::python;
using namespace std;


Point point_from_tuple(PyObject * t) {
	return Point(PyInt_AsLong(PyTuple_GetItem(t, 0)),
							 PyInt_AsLong(PyTuple_GetItem(t, 1)),
							 PyInt_AsLong(PyTuple_GetItem(t, 2)));
}

const Color get_material(int k) {
	switch (k) {
		case 0 : // ColorGreen
			return Color::Green;
		case 1 : // ColorRed
			return Color::Red;
		case 2 : // ColorYellow
			return Color::Yellow;
		case 3 : // ColorCyan
			return Color::Cyan;
		case 4 : // ColorMagenta
			return Color::Magenta;
		case 5  : // ColorBlue
			return Color::Blue;
		default :
			cout << "Error : material Not found !" << endl;
			assert(1==0);
	}
}

PyObject * parse(int argc, char * argv[]) {

	assert(argc>0); // We should have an argument

	setenv("PYTHONPATH",".",1);
	Py_Initialize();

	PyObject *pName, *pModule, *pDict;
	PyObject *presult, *pFunc, *pValue;

	// Build the name object
	pName = PyString_FromString((char*)"parser");

	// Load the module object

	pModule = PyImport_Import(pName);
	if (pModule == 0)
	{
			PyErr_Print();
			assert(1==0);
	}

	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);

	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, (char*)"parse");

	if (PyCallable_Check(pFunc))
	{
			pValue=Py_BuildValue("(z)", argv[1]);
			PyErr_Print();
			cout << "Parsing file " << argv[1] << " ..." << endl;
			presult = PyObject_CallObject(pFunc,pValue); // Une liste de tuple décrivant les objets de la scène.
			PyErr_Print();
	} else
	{
			PyErr_Print();
	}

	// Clean up
	Py_DECREF(pValue);
	Py_DECREF(pModule);
	Py_DECREF(pName);


	Py_Finalize();

	return presult;
}
