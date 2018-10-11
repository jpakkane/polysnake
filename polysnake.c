/*
 * Copyright (C) 2017 Jussi Pakkanen.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of version 3, or (at your option) any later version,
 * of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<Python.h>
#include<string.h>

double fortranfunc(char *buf, int len_buf);
const char* cppfunc();
const char* rustfunc();

static PyObject* generate(PyObject *self, PyObject *args) {
    char mainbuf[1024] = "Combining many languages in one shared module is simple.\n\n";
    char fstore[80];
    int i=0;
    fortranfunc(fstore, 80);
    /* FORTRAN does not null terminate strings. */
    while(fstore[i] != '.') {
        i++;
    }
    fstore[i+1] = '\n';
    fstore[i+2] = '\0';
    strcat(mainbuf, "This line is created in C.\n");
    strcat(mainbuf, fstore);
    strcat(mainbuf, cppfunc());
    strcat(mainbuf, rustfunc());
    return Py_BuildValue("y", mainbuf);
}

static PyMethodDef TachyonMethods[] = {
    {"generate",  generate, METH_VARARGS,
     "Create polyglot text."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef polysnakemodule = {
   PyModuleDef_HEAD_INIT,
   "polysnake",
   NULL,
   -1,
   TachyonMethods
};

PyMODINIT_FUNC PyInit_polysnake(void) {
    return PyModule_Create(&polysnakemodule);
}
