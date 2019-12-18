// Chad Tolleson Copyright (c) 2018
// Python test file

// attribution: https://docs.python.org/2/extending/embedding.html

#include <Python.h>

int main(int argc, char *argv[])
    {
    Py_SetProgramName(argv[0]);  /* optional but recommended */
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print 'Today is',ctime(time())\n");
    Py_Finalize();
    return 0;
    }
