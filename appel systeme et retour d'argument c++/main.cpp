#include <boost/python.hpp>
#include <iostream>

int main()
{
   using namespace boost::python;
   using namespace std;

   // Set PYTHONPATH TO working directory
   setenv("PYTHONPATH",".",1);

   PyObject *pName, *pModule, *pDict, *pFunc, *pValue, *presult;
   PyObject *pv1, *pv2;

   // Initialize the Python Interpreter
   Py_Initialize();

   // Build the name object
   pName = PyString_FromString((char*)"bloup");

   // Load the module object

   pModule = PyImport_Import(pName);
   if (pModule == 0)
   {
       PyErr_Print();
       return 0;
   }

   // pDict is a borrowed reference
   pDict = PyModule_GetDict(pModule);

   // pFunc is also a borrowed reference
   pFunc = PyDict_GetItemString(pDict, (char*)"someFunction");

   if (PyCallable_Check(pFunc))
   {
       pValue=Py_BuildValue("(z)",(char*)"j ai perdu");
       PyErr_Print();
       cout << "Let's give this a shot!" << endl;
       presult = PyObject_CallObject(pFunc,pValue);
       pv1 = PyTuple_GetItem(presult, 0);
       pv2 = PyTuple_GetItem(presult, 1);
       PyErr_Print();
   } else {
       PyErr_Print();
   }
   cout << "Parsing done !" << endl;

   // clean up
   Py_DECREF(pValue);
   Py_DECREF(pModule);
   Py_DECREF(pName);

   // Finish the Python Interpreter
   Py_Finalize();


    return 0;
}
